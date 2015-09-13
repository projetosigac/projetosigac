
/*
 * GET home page.
 */

exports.index = function(req, res){
  res.render('index', { title: 'Hello World' });
};

exports.atendimento = function(req, res){
  res.render('atendimento', { title: 'Hello World' });
};
