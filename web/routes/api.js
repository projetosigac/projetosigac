var ocorrenciaDAO = require('../db/ocorrenciaDAO')(); // load the database library
var localizacaoAmbulanciaDAO = require('../db/localizacaoAmbulanciaDAO')(); // load the database library
var utils = require('./utils');
/*
 * APIS do Sistema.
 */

/**
 * Retorna a ocorrência em aberto mais antiga que ainda precisa de atendimento.
 * Esse serviço é utilizado pelas ambulâncias para obter novas ocorrências a serem atendidas.
 *
 * @author vinicius
 *
 * @param req HTTP request
 * @param res HHTP response
 */
exports.verificarOcorrencia = function (req, res, next) {
    if (req.query.lat && req.query.long && req.query.placa) {
        console.log('Salvando localizacao para ambulancia ' + req.query.placa);

        var longAsDouble = parseFloat(req.query.long);
        var latAsDouble = parseFloat(req.query.lat);

        if (isNaN(longAsDouble)) {
            res.status(400); // bad request;
            return res.json({message: 'Invalid longitude parameter.'})
        }
        if (isNaN(latAsDouble)) {
            res.status(400); // bad request;
            return res.json({message: 'Invalid latitude parameter.'})
        }

        var localizacao = {
            placa: req.query.placa,
            latitude: latAsDouble,
            longitude: longAsDouble
        }
        localizacaoAmbulanciaDAO.salvarLocalizacao(localizacao, function(err) {
            if (err) {
                console.log(err);
            }
        });
    }
    ocorrenciaDAO.obterOcorrenciaAberta(req.query.placa, function(err, result) {
        if (err) return next(err);
		if (result != null) {
			result.endereco = utils.removeSpecialChars(result.endereco);
			result.comentarios = utils.removeSpecialChars(result.comentarios);
			res.json(result);
		} else {
			res.json({});
		}        
    });
}

/**
 * Método POST que realiza a confirmação de que uma dada ambulância partiu para o atendimento
 * de uma ocorrência.
 *
 * @author vinicius
 *
 * @param req HTTP request
 * @param res HHTP response
 */
exports.confirmarAtendimento = function (req, res, next) {
    var placaAmbulancia = req.body.placaAmbulancia;
    var ocorrenciaId = req.body.ocorrenciaId;

    var atendimento = { ocorrenciaId: ocorrenciaId, placaAmbulancia: placaAmbulancia };
    ocorrenciaDAO.salvarAtendimento(atendimento, function(err) {
        if (err) {
            return next(err);
        } else {
            res.end();
        }
    });
}

exports.loginSistema = function (req, res) {

    if (!req.body.hasOwnProperty('login') || !req.body.hasOwnProperty('senha')) {
        res.statusCode = 400;
        return res.json({status: 'Error 400', message: 'Login ou senha não preenchidos', body: req.body});
    }

    var sess = req.session;
    var email = req.body.login;
    var senha = req.body.senha;

    req.getConnection(function(err,connection){
        var query = connection.query('SELECT usu_token FROM usuario WHERE usu_email = ? AND usu_senha=?', [email, senha], function(err,rows) {
            if(err) {
                console.log("Error Query : %s ",err );
            }

            if(rows.length == 1) {
                sess.token = rows[0].usu_token;
                sess.login = req.body.login;
                res.json({status: 'OK', token: sess.token});
            } else {
                res.statusCode = 401;
                res.json({status: 'Error 401', message: 'Login ou senha estão incorretos', body: req.body});
            }
        });
    });
};

/*Realizar logout do sistema*/
exports.logout = function (req, res) {
    req.session.destroy(function(err) {
        if (err) {
            console.log(err);
        }
        else {
            res.redirect('/');
        }
    });
};

/*Insert Occurrence Report*/
exports.insertOR = function (req, res) {
    var sess = req.session;
    var input = JSON.parse(JSON.stringify(req.body));

    req.getConnection(function(err,connection){

        var bulletin = {
            por_officer_id          : input.officerid,
            pol_victim_ident        : input.id,
            pol_victim_name         : input.name,
            pol_address             : input.adress,
            pol_city                : input.city,
            pol_state               : input.state,
            pol_dt_fact             : input.date_fact,
            pol_time_fact           : input.time_fact,
            pol_dt_start_attend     : input.dt_start_attend,
            pol_time_start_attend   : input.time_start_attend,
            pol_desc                : input.description,
            pol_incid_type          : input.inc_type,
            pol_num_missing_people  : input.missing,
            pol_dt_end_attend       : input.dt_end_attend,
            pol_time_end_attend     : input.time_end_attend,
        };

        var query = connection.query("INSERT INTO PoliceReport set ? ",bulletin, function(err, rows)
        {
            if (err) {
                console.log("Error inserting : %s ",err );
                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
            }
            return res.json({'status': 'OK'});
        });
    });
};

/*Show Occurrence Reports*/
exports.showORs = function (req, res) {
    var sess = req.session;
    req.getConnection(function(err,connection){
        var query = connection.query('SELECT * from PoliceReport;', function(err,rows,fields) {
            if(err) {
                return console.log("Error Query : %s ",err );
            }
            return res.json({status: 'OK', 'rows' : rows, token: sess.token});
        });
    });
};


/*cadastrar equipamento no bd*/
exports.insertEquip = function (req, res) {
    var sess = req.session;
    var equipDesc = req.body.equipDesc;
    req.getConnection(function(err,connection) {
        var query = connection.query('INSERT INTO amb_equipamento (equip_descricao) VALUES (?);', [equipDesc], function(err, result) {
            if(err) {
                console.log(err);
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
            }

            if (result.affectedRows > 0) {
                return res.json({'status': 'OK'});
            } else {
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
            }
        });
    });
};

/*deletar equipamento no bd*/
exports.deleteEquip = function (req, res) {
    var sess = req.session;
    var equipDesc = req.body.equipDesc;
    req.getConnection(function(err,connection) {
        var query = connection.query('DELETE FROM amb_equipamento WHERE equip_descricao = (?);', [equipDesc], function(err, result) {
            if (err) {
                console.log(err);
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel deletar do banco de dados', body: req.body});
            }

            if(result.affectedRows > 0) {
                return res.json({'status': 'OK'});
            } else {
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel deletar do banco de dados', body: req.body});
            }
        });
    });
};

/*inserir equipamento na ambulancia*/
exports.insertEquipAmb = function (req, res) {
    var sess = req.session;
    var nomeEquipamentoAmb = req.body.nomeEquipamentoAmb;
    var placaAmb = req.body.placaAmb;

    //nomeEquipamentoAmb = "%" + nomeEquipamentoAmb + "%";
    req.getConnection(function(err,connection) {
        var query = connection.query('INSERT INTO amb_lista_equipamentos VALUES (?, (SELECT equip_id FROM amb_equipamento WHERE equip_descricao LIKE ?));', [placaAmb, nomeEquipamentoAmb], function(err, result) {
            if (err) {
                console.log(err);
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
            }

            if(result.affectedRows > 0) {
                return res.json({'status': 'OK'});
            } else {
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
            }
        });
    });
};

/*deletar equipamento na ambulancia*/
exports.deleteEquipAmb = function (req, res) {
    var sess = req.session;
    var nomeEquipamentoAmb = req.body.nomeEquipamentoAmb;
    var placaAmb = req.body.placaAmb;

    //nomeEquipamentoAmb = "%" + nomeEquipamentoAmb + "%";
    req.getConnection(function(err,connection){
        var query = connection.query('DELETE FROM amb_lista_equipamentos WHERE (placa_ambulancia = ? AND equip_id = (SELECT equip_id FROM amb_equipamento WHERE equip_descricao = ?));', [placaAmb, nomeEquipamentoAmb], function(err, result) {
            if (err) {
                console.log(err);
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
            }

            if(result.affectedRows > 0) {
                return res.json({'status': 'OK'});
            } else {
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
            }
        });
    });
};

exports.registrarObito = function(req,res){}

/*Get Equip*/
exports.getEquipAmb = function (req, res) {
    var sess = req.session;
    var placaAmbGet = req.body.placaAmbGet;

    req.getConnection(function(err,connection) {
        var query = connection.query('SELECT E.equip_descricao FROM amb_lista_equipamentos as L LEFT JOIN amb_equipamento as E ON (L.equip_id = E.equip_id) WHERE L.placa_ambulancia = ?;',[placaAmbGet], function(err,rows,fields)
        {
            if(err) {
                return console.log("Error Query : %s ",err );
            }
            return res.json({status: 'OK', 'rows' : rows, token: sess.token});
        });
    });

};

/*Show Equip*/
exports.showEquip = function (req, res) {
    var sess = req.session;
    req.getConnection(function(err,connection){
        var query = connection.query('SELECT equip_descricao from amb_equipamento;', function(err,rows,fields) {
            if(err) {
                return console.log("Error Query : %s ",err );
            }

            return res.json({status: 'OK', 'rows' : rows, token: sess.token});
        });
    });
};

    /*Show amb*/
exports.showAmb = function (req, res) {
    var sess = req.session;

    req.getConnection(function(err,connection){
        var query = connection.query('SELECT placa from ambulancia;', function(err,rows,fields) {
            if(err) {
                return console.log("Error Query : %s ",err );
            }

            return res.json({status: 'OK', 'rows' : rows, token: sess.token});
        });
    });
};

exports.leituraSinais = function (req, res) {
    var id_vitima  = req.body.id_vitima;
    var pulso  = req.body.pulso;
    var bpm  = req.body.bpm;
    var temperatura = req.body.temperatura;
    var oximetria   = req.body.oximetria;

    req.getConnection(function(err,connection) {
        var query = connection.query('INSERT INTO vitimas_status (id_vitima, pulso, bpm, temperatura, oximetria, timestamp) VALUES (?,?,?,?,?,NOW());',
            [id_vitima, pulso, bpm, temperatura, oximetria],

            function(err, result) {
                if(err) {
                    console.log(err);
                    res.statusCode = 401;
                    return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
                }

                if(result.affectedRows > 0) {
                    return res.json({'status': 'OK'});
                } else {
                    res.statusCode = 401;
                    return res.json({status: 'Error 4010', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
                }
            }
        );
    });
};


/*Show Crisis*/
exports.showCrisis = function (req, res) {
    var sess = req.session;

    req.getConnection(function(err,connection){
        var query = connection.query('SELECT cri_id, cri_ds, cri_afetados, latitudeBoxValue, LongitudeBoxValue from crise  where cri_id not in (select id_crise from ocorrencia);', 
            function(err,rows,fields) {
            if(err) {
                return console.log("Error Query : %s ",err );
            }else
              return res.json({status: 'OK', 'rows' : rows, token: sess.token});

        });
    });
};


/*Get Crises*/
exports.getCrisis = function (req, res) {
    var sess = req.session;
    var criseDs = req.body.listaCriseSelecao;

    req.getConnection(function(err,connection) {
        var query = connection.query('SELECT cri_afetados FROM crise WHERE cri_ds = ?;',[criseDs], function(err,rows,fields)
        {
            if(err) {
                return console.log("Error Query : %s ",err );
            }
            return res.json({status: 'OK', 'rows' : rows, token: sess.token});
        });
    });
};


/*Show AmbList*/
exports.showAmbList = function (req, res) {
    var sess = req.session;

    req.getConnection(function(err,connection){   
            var query = connection.query('SELECT A.placa, A.qtd_passageiros, A.tipo, A.status, L.latitude, L.longitude from ambulancia as A LEFT JOIN localizacao_ambulancia as L ON (A.placa = L.placa_ambulancia)  ;', function(err,rows,fields) {
            if(err) {
                return console.log("Error Query : %s ",err );
            }else
              return res.json({status: 'OK', 'rows' : rows, token: sess.token});

        });
    });
};

/*Show Active Occurrences*/
exports.showOccurrences = function (req, res) {
    var sess = req.session;

    req.getConnection(function(err,connection){
        //var query = connection.query('SELECT cri_id, cri_ds, cri_afetados, latitudeBoxValue, LongitudeBoxValue from crise  where cri_id in (select id_crise from ocorrencia);', function(err,rows,fields) {
        var query = connection.query('SELECT * from ocorrencia WHERE id_crise <> 0;', function(err,rows,fields) {
            if(err) {
                return console.log("Error Query : %s ",err );
            }else
              return res.json({status: 'OK', 'rows' : rows, token: sess.token});

        });
    });
};
