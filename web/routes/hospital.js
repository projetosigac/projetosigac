/*
 * métodos de envolvendo entidade Hospital
 */
var hospitalDAO = require('../db/hospitalDAO')(); // load the database library

/**
 * Retorna a base de samu que contém a ambulância com a configuração adequada para atendimento a ocorrência
 * Esse método é utilizado pela tela de atendimento para abrir uma ocorrência
 *
 * @author Danilo Ramalho
 *
 * @param req HTTP request
 * @param res HHTP response
 */
exports.listarLeitoDisponivel = function (req, res, next) {
    hospitalDAO.listarLeitoDisponivel(function(err, result) {
        if (err) return next(err);
        else res.json(result);
    });
};
