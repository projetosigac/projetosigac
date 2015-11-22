
/*
 * APIS do Sistema.
 */

exports.login = function(req, res){
  //req
  //res.render('index', { title: 'Hello World' });
  
  if (!req.body.hasOwnProperty('login')|| 
	   !req.body.hasOwnProperty('senha')) {

		res.statusCode = 400;
		return res.json({status: 'Error 400', message: 'Login ou senha não preenchidos',body: req.body});
	}
	
    res.json({status: 'OK', token: 'QWERTYUIOPASDFG1236547'});
  
};
