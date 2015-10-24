
var db = require('../db/db') // load the database library

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
    req.getConnection(function(err,connection) {
        db.obterOcorrenciaAberta(connection, function(err, result) {
            if (err) return next(err);
            res.json(result);
        });
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

    req.getConnection(function(err,connection){
        var atendimento = { ocorrenciaId: ocorrenciaId, placaAmbulancia: placaAmbulancia };
        db.salvarAtendimento(connection, function(err) {
            if (err) {
                return next(err);
            } else {
                res.end();
            }
        }, atendimento);
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
    var idEquipamento = req.body.idEquipamento; 
    var equipDesc = req.body.equipDesc;
   

    req.getConnection(function(err,connection){   
        var query = connection.query('INSERT INTO amb_equipamento VALUES (? , ?);', [idEquipamento, equipDesc], function(err, result) {
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



/*inserir equipamento na ambulancia*/

exports.insertEquipAmb = function (req, res) {
    
    var sess = req.session;    
    var idEquipamentoAmb = req.body.idEquipamentoAmb; 
    var placaAmb = req.body.placaAmb;
   

    req.getConnection(function(err,connection){   
        var query = connection.query('INSERT INTO amb_lista_equipamentos VALUES (? , ?);', [placaAmb, idEquipamentoAmb], function(err, result) {
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
        var query = connection.query('SELECT equip_id FROM amb_lista_equipamentos WHERE placa_ambulancia = ?;', [placaAmbGet], function(err,rows,fields)
        {
            if(err)
                console.log("Error Query : %s ",err );

            else
            {
                for (var i in rows){
                    console.log(rows[i]);
                    
                }
                res.json({status: 'OK', token: sess.token});            
            }                
        });
    }); 


};