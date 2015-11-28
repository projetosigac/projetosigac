/*
 * Funcionalidades envolvendo a página de pedido de recursos
 */
exports.carregarPagina = function(req, res){
    res.render('defc/registroPedido', { title: 'Hello World' });
};
