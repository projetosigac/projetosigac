/*
 * Funcionalidades envolvendo a página de atendimento
 */
exports.carregarPagina = function(req, res){
  res.render('atendimento', { title: 'Hello World' });
};
