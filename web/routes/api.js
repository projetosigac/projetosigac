
var ocorrenciaDAO = require('../db/ocorrenciaDAO')(); // load the database library
var localicazaoAmbulanciaDAO = require('../db/localizacaoAmbulanciaDAO')(); // load the database library

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
        localicazaoAmbulanciaDAO.salvarLocalizacao(localizacao, function(err) {
            if (err) {
                console.log(err);
            }
        });
    }
    ocorrenciaDAO.obterOcorrenciaAberta(function(err, result) {
        if (err) return next(err);
        res.json(result);
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
        var query = connection.query('SELECT usu_token FROM usuario WHERE usu_email = ? AND usu_senha=?', [email, senha], function(err,rows)
        {
            if(err)
                console.log("Error Query : %s ",err );

            if(rows.length == 1)
            {
                sess.token = rows[0].usu_token;
                sess.login = req.body.login;
                res.json({status: 'OK', token: sess.token});
            }else
            {
                res.statusCode = 401;
                res.json({status: 'Error 401', message: 'Login ou senha estão incorretos', body: req.body});
            }
        });
    });
};

/*Realizar logout do sistema*/
exports.logout = function (req, res){
	req.session.destroy(function(err){
		if (err){
			console.log(err);
		}
		else
		{
			res.redirect('/');
		}
	});
};


/*cadastrar equipamento no bd*/

exports.insertEquip = function (req, res) {
    var sess = req.session;    
    var equipDesc = req.body.equipDesc;
    req.getConnection(function(err,connection){   
        var query = connection.query('INSERT INTO amb_equipamento (equip_descricao) VALUES (?);', [equipDesc], function(err, result) {
            if(err) {
                console.log(err);
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
            }

            if(result.affectedRows > 0)
            {
                return res.json({'status': 'OK'});
            }else
            {
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
    req.getConnection(function(err,connection){   
        var query = connection.query('DELETE FROM amb_equipamento WHERE equip_descricao = (?);', [equipDesc], function(err, result) {
            if(err) {
                console.log(err);
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel deletar do banco de dados', body: req.body});
            }

            if(result.affectedRows > 0)
            {
                return res.json({'status': 'OK'});
            }else
            {
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
    req.getConnection(function(err,connection){   
        var query = connection.query('INSERT INTO amb_lista_equipamentos VALUES (?, (SELECT equip_id FROM amb_equipamento WHERE equip_descricao LIKE ?));', [placaAmb, nomeEquipamentoAmb], function(err, result) {
            if(err) {
                console.log(err);
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
            }

            if(result.affectedRows > 0)
            {
                return res.json({'status': 'OK'});
            }else
            {
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
            if(err) {
                console.log(err);
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
            }

            if(result.affectedRows > 0)
            {
                return res.json({'status': 'OK'});
            }else
            {
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
            }
        });
    });
};


/*Get Equip*/
exports.getEquipAmb = function (req, res) {

    var sess = req.session;
    var placaAmbGet = req.body.placaAmbGet;

    req.getConnection(function(err,connection){   
            var query = connection.query('SELECT E.equip_descricao FROM amb_lista_equipamentos as L LEFT JOIN amb_equipamento as E ON (L.equip_id = E.equip_id) WHERE L.placa_ambulancia = ?;',[placaAmbGet], function(err,rows,fields)
        {
            if(err)
                return console.log("Error Query : %s ",err );

            return res.json({status: 'OK', 'rows' : rows, token: sess.token});            
                          
        });
    }); 

};

/*Show Equip*/
exports.showEquip = function (req, res) {
    
    var sess = req.session;     

    req.getConnection(function(err,connection){   
            var query = connection.query('SELECT equip_descricao from amb_equipamento;', function(err,rows,fields)
        {
            if(err)
                return console.log("Error Query : %s ",err );

            return res.json({status: 'OK', 'rows' : rows, token: sess.token});            
                          
        });
    }); 


};



    /*Show amb*/
exports.showAmb = function (req, res) {
    
    var sess = req.session;     

    req.getConnection(function(err,connection){   
            var query = connection.query('SELECT placa from ambulancia;', function(err,rows,fields)
        {
            if(err)
                return console.log("Error Query : %s ",err );

            return res.json({status: 'OK', 'rows' : rows, token: sess.token});            
                          
        });
    });
};

exports.leituraSinais = function (req, res) {

    var pacienteId  = req.body.pacienteId;
    var batimentos  = req.body.batimentos;
    var temperatura = req.body.temperatura;
    var oximetria   = req.body.oximetria;

    req.getConnection(function(err,connection){   
        var query = connection.query('INSERT INTO paciente_status (paciente_id, batimento_cardiaco, temperatura, oximetria, timestamp) VALUES (?,?,?,?,NOW());', 
                        [pacienteId, batimentos, temperatura, oximetria], 

                        function(err, result) {
                            if(err) {
                                console.log(err);
                                res.statusCode = 401;
                                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
                            }

                            if(result.affectedRows > 0)
                            {
                                return res.json({'status': 'OK'});
                            }else
                            {
                                res.statusCode = 401;
                                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
                            }
                        }
                    );
    });
};