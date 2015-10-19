/*
 * Funcionalidades envolvendo a página de atendimento
 */
exports.carregarPagina = function(req, res){
  res.render('ambulancia/ambulancias', { title: 'Hello World' });
};
