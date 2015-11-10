/*
 * Funcionalidades envolvendo a página de atendimento
 */
var ocorrenciaDAO = require('../db/ocorrenciaDAO')(); // load the database library
var localizacaoAmbulanciaDAO = require('../db/localizacaoAmbulanciaDAO')();

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
};
/**
 * Retorna a lista de ocorrências
 * Esse método é utilizado pela tela de ambulancias/chamados
 *
 * @author Danilo Ramalho
 *
 * @param req HTTP request
 * @param res HHTP response
 */
exports.listarOcorrencia = function (req, res, next) {

    var param = {
      status : req.query.status
    };
    ocorrenciaDAO.listarOcorrencia(param, function(err, result) {
        if (err) return next(err);
        else res.json(result);
    });

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
exports.salvarOcorrencia = function (req, res, next) {

  var ocorrencia = {
      endereco : req.body.localEmergencia,
      latitude : req.body.latitudeEmergencia,
      longitude : req.body.longitudeEmergencia,
      qtdVitimas : req.body.qtdVitimas,
      qtdAmb : req.body.qtdAmb,
      qtdMed : req.body.qtdMed,
      observacao : req.body.observacao
    };

  /*Validação dos valores do formulário de cadastro de ocorrência*/
  var camposValidos = true;
  var campoObrigatorio;
  for(var campo in ocorrencia){
      if (campo != 'observacao' && !ocorrencia[campo]){
        camposValidos = true;
        campoObrigatorio = campo;
        break;
      }
  }
  if (!camposValidos){
    res.statusCode = 400;
    return res.json({status: 'Error 400', message: 'O campo ('+campoObrigatorio+') é obrigatório', body: req.body});
  }

  ocorrenciaDAO.salvarOcorrencia(ocorrencia, function(err, result) {
      if (err) return next(err);
      else res.json(result);
  });

};

/**
 * Retorna as localizações de todas as ambulâncias cadastradas
 * Esse método é utilizado pela tela de ambulancias/chamados
 *
 * @param req HTTP request
 * @param res HHTP response
 */
exports.localizacaoAmbulancias = function (req, res, next) {

    var param = {
      status : req.query.status
    };
    localizacaoAmbulanciaDAO.listarLocalizacoes(param, function(err, result) {
        if (err) return next(err);
        else res.json(result);
    });

};
