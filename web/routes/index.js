/*
 * GET home page.
 */
exports.index = function(req, res){
  res.render('index', { title: 'Hello World' });
};

/*mover funcoes abaixo para arquivo js igual nome da funcionalidade*/

exports.ambulancias = function(req, res){
  res.render('ambulancia/ambulancias', { title: 'Ambulancias' });
};

exports.chamados = function(req, res){
  res.render('ambulancia/chamados', { title: 'Chamados' });
};

