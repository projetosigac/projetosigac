var panelDAO = require('../db/panelDAO')();

exports.getParameters = function (req, res, next) {
    var params = [];
    panelDAO
    .getMissing(function(err, result) {
        if (err) return next(err);
        else params.push(result);
    })
    .getAmbulances(function(err, result) {
        if (err) return next(err);
        else params.push(result);
    })
    .getLatitude(function(err, result) {
        if (err) return next(err);
        else params.push(result);
    })
    .getLongitude(function(err, result) {
        if (err) return next(err);
        else params.push(result);
    })
    .getVictims(function(err, result) {
        if (err) return next(err);
        else params.push(result);
    })
    .getTemperature(function(err, result) {
        if (err) return next(err);
        else params.push(result);
    })
    .getHumidity(function(err, result) {
        if (err) return next(err);
        else params.push(result);
    })
    .getClassification(function(err, result) {
        if (err) return next(err);
        else params.push(result);
    });
    res.json(params);
};
