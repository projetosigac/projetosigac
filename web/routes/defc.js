/*
 * Funcionalidades envolvendo a página de atendimento
 */
var panelDAO = require('../db/panelDAO')();
var EventEmitter =  require('events').EventEmitter;
var flowController = new EventEmitter();

exports.carregarPagina = function(req, res){
  res.render('defc', { title: 'Civil Defence' });
};

exports.carregarPainel = function(req, res){
  res.render('defcivil/main', { title: 'Civil Defence Control Panel' });
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
                //flowController.emit('occPositions',args)
                res.json(args);
            }
        });
    })

    //ESTA FUNÇÃO NÃO ESTÁ SENDO CHAMADA NA ATUALIZAÇÃO PARA NÃO CAUSAR OVERHEAD NO PAINEL

        .on('occPositions',function(args){
            panelDAO.getOccurrencesPositions(function(err, result) {
                if (err) 
                    return next(err);
                else{
                    args.push(result);
                    res.json(args);
                }
            });
        })

    //FIM

    flowController.emit('start',[]);
};


exports.getOccurrencesPositions = function (req, res) {    

    panelDAO.getOccurrencesPositions(function(err, result) {
        if(err) {
            console.log(err);
            res.statusCode = 401;
            return res.json({status: 'Error 401', message: 'Nao foi possivel consultar as posições das ocorrências', body: req.body});
        }
        else{
            //return res.json(result);
            res.send(JSON.stringify(result, null, 3));
        }
    });
   
};

exports.getClosedOccurrencesPositions = function (req, res) {    

    panelDAO.getClosedOccurrencesPositions(function(err, result) {
        if(err) {
            console.log(err);
            res.statusCode = 401;
            return res.json({status: 'Error 401', message: 'Nao foi possivel consultar as posições das ocorrências passadas', body: req.body});
        }
        else{
            //return res.json(result);
            res.send(JSON.stringify(result, null, 3));
        }
    });
   
};

exports.getAmbulancesPositions = function (req, res) {    

    panelDAO.getAmbulancesPositions(function(err, result) {
        if(err) {
            console.log(err);
            res.statusCode = 401;
            return res.json({status: 'Error 401', message: 'Nao foi possivel consultar as posições das ambulâncias', body: req.body});
        }
        else{
            //return res.json(result);
            res.send(JSON.stringify(result, null, 3));
        }
    });
   
};

exports.getSensorsPositions = function (req, res) {    

    panelDAO.getSensorsPositions(function(err, result) {
        if(err) {
            console.log(err);
            res.statusCode = 401;
            return res.json({status: 'Error 401', message: 'Nao foi possivel consultar as posições dos sensores', body: req.body});
        }
        else{
            //return res.json(result);
            res.send(JSON.stringify(result, null, 3));
        }
    });
   
};

exports.getStationsPositions = function (req, res) {    

    panelDAO.getStationsPositions(function(err, result) {
        if(err) {
            console.log(err);
            res.statusCode = 401;
            return res.json({status: 'Error 401', message: 'Nao foi possivel consultar as posições das estações', body: req.body});
        }
        else{
            //return res.json(result);
            res.send(JSON.stringify(result, null, 3));
        }
    });
   
};

exports.getHospitalsPositions = function (req, res) {    

    panelDAO.getHospitalsPositions(function(err, result) {
        if(err) {
            console.log(err);
            res.statusCode = 401;
            return res.json({status: 'Error 401', message: 'Nao foi possivel consultar as posições das estações', body: req.body});
        }
        else{
            //return res.json(result);
            res.send(JSON.stringify(result, null, 3));
        }
    });
   
};