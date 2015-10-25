/*
 * Funcionalidades envolvendo a página de atendimento
 */
var ocorrenciaDAO = require('../db/ocorrenciaDAO')(); // load the database library

exports.carregarPagina = function(req, res){
  res.render('ambulancia/atendimento', { title: 'Hello World' });
};
/**
 * Retorna a base de samu que contém a ambulância com a configuração adequada para atendimento a ocorrência
 * Esse método é utilizado pela tela de atendimento para abrir uma ocorrência
 *
 * @author Danilo Ramalho
 *
 * @param req HTTP request
 * @param res HHTP response
 */
exports.carregarBaseSamu = function (req, res, next) {
    ocorrenciaDAO.obterBaseSamuAtiva(function(err, result) {
        if (err) return next(err);
        else res.json(result);
    });
/*tirar essa parte pois a parte de cima ainda não funciona*/
//  req.getConnection(function(err,connection){
//      var query = connection.query('select * from cadastro_samu s where exists (select placa from ambulancia a where s.samu_id=a.samu_id and a.status = ?)', ['Ativo'], function(err,rows)
//      {
//          if(err)
//              console.log("Error Query : %s ",err );
//
//          if(rows.length > 0)
//              res.json({status: 'OK', result: rows});
//          else
//          {
//              res.statusCode = 401;
//              res.json({status: 'Error 401', message: 'Não existe base de Samu disponível no momento', body: req.body});
//          }
//      });
//  });
};
