/*
 * funções  utils do sistema
 */
exports.autenticarSessao = function (req, res, next){
    
    var sess = req.session;    
    
	if(!sess.login)
	{
		res.redirect('/');
	}else{
        next();
    }  
};
