/*
 * Funcionalidades envolvendo a página de atendimento
 */
exports.carregarPagina = function(req, res){
  res.render('defcivil/main', { title: 'Hello World' });
};

exports.leituraGeral = function (req, res) {

    var pacienteId  = req.body.pacienteId;
    var batimentos  = req.body.batimentos;
    var temperatura = req.body.temperatura;
    var oximetria   = req.body.oximetria;

    req.getConnection(function(err,connection){
        var query = connection.query('INSERT INTO paciente_status (paciente_id, batimento_cardiaco, temperatura, oximetria, timestamp) VALUES (?,?,?,?,NOW());',
                        [pacienteId, batimentos, temperatura, oximetria],

                        function(err, result) {
                            if(err) {
                                console.log(err);
                                res.statusCode = 401;
                                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
                            }

                            if(result.affectedRows > 0)
                            {
                                return res.json({'status': 'OK'});
                            }else
                            {
                                res.statusCode = 401;
                                return res.json({status: 'Error 401', message: 'Nao foi possivel inserir no banco de dados', body: req.body});
                            }
                        }
                    );
    });
};