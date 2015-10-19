/*
 * APIS do Sistema.
 */

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
