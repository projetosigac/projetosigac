/*
 * Funcionalidades envolvendo a página de atendimento
 */
var panelDAO = require('../db/panelDAO')();
var EventEmitter =  require('events').EventEmitter;
var flowController = new EventEmitter();

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

exports.getParameters = function (req, res, next) {
    var params = [];
    
    var flowController = new EventEmitter();    
    flowController
    .on('start',function(args){
        panelDAO.getAmbulances(function(err, result) {
            if (err) 
                return next(err);
            else{
                params.push(result);
                flowController.emit('missing',params);
            }
        });        
    })
    .on('missing',function(args){
        panelDAO.getMissing(function(err, result) {
            if (err) 
                return next(err);
            else{
                args.push(result);
                flowController.emit('latitude',args);
            }
        });        
    })
    .on('latitude',function(args){
        panelDAO.getLatitude(function(err, result) {
            if (err) 
                return next(err);
            else{
                args.push(result);
                flowController.emit('longitude',args);
            }
        });        
    })
    .on('longitude',function(args){
        panelDAO.getLongitude(function(err, result) {
            if (err) 
                return next(err);
            else{
                args.push(result);
                flowController.emit('victims',args);
            }
        });        
    })
    .on('victims',function(args){
        panelDAO.getVictims(function(err, result) {
            if (err) 
                return next(err);
            else{
                args.push(result);
                flowController.emit('temperature',args);
            }
        });        
    })
    .on('temperature',function(args){
        panelDAO.getTemperature(function(err, result) {
            if (err) 
                return next(err);
            else{
                args.push(result);
                flowController.emit('humidity',args);
            }
        });        
    })
    .on('humidity',function(args){
        panelDAO.getHumidity(function(err, result) {
            if (err) 
                return next(err);
            else{
                args.push(result);
                flowController.emit('classification',args);
            }
        });
    })       
    .on('classification',function(args){
        panelDAO.getClassification(function(err, result) {
            if (err) 
                return next(err);
            else{
                args.push(result);
                console.log(args);
                res.json(args);
            }
        });
    })
    flowController.emit('start',[]);
};
