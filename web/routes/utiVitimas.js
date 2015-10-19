/*
 * Funcionalidades envolvendo a página de atendimento
 */
exports.carregarPagina = function(req, res){
  res.render('uti/vitimas', { title: 'Hello World' });
};
