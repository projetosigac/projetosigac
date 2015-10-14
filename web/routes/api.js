
/*
 * APIS do Sistema.
 */

exports.login = function (req, res) {
  //req
  //res.render('index', { title: 'Hello World' });
  
  if (!req.body.hasOwnProperty('login') || !req.body.hasOwnProperty('senha')) {
		res.statusCode = 400;
		return res.json({status: 'Error 400', message: 'Login ou senha não preenchidos',body: req.body});
	}
    
    var sess = req.session;	    
    var email = req.body.login;
    var senha = req.body.senha;
/*    
    ***DESCOMENTAR APOS A CRIACAO DA TABELA USUARIOS
    req.getConnection(function(err,connection){   
        var query = connection.query('SELECT token FROM tb_usuario WHERE email = ? AND senha=?',[email, senha],function(err,rows)
        {
            if(err)
                console.log("Error Query : %s ",err );

            if(rows.length == 1)
            {
                sess.token = rows[0].token;
                */
                sess.login = req.body.login;
                /* APAGAR LINHA ABAIXO QUANDO CONECTAR NO BD */
                sess.token = 'QWERTYUIOPASDFG1236547';
    /*
            }else
            {
                res.statusCode = 401;
                return res.json({status: 'Error 401', message: 'Login ou senha estão incorretos',body: req.body});
            }
                
        });
    }); 
      */  
    res.json({status: 'OK', token: sess.token});
};
