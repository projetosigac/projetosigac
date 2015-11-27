var util = require('../utils');
var victimsDAO = require('../../db/victimsDAO')();

module.exports = function (app) {
    app.get('/api/firefighter/sar/crisis/:crisis_id/victims', function(req, res) {
        var crisisID = req.params.crisis_id;

        return victimsDAO.getVictimsByCrisisID(crisisID, function(err, result, fields) {
            if(err)
            {
                console.log(err);
                return res.status(500).json({'err': 'DB Error'});
            }

            return res.json(result.map(function(row) {
                return {
                    'token': row.token,
                    'name': row.nome,
                    'sex': row.sexo,
                    'status': row.status,
                    'age': row.age,
                };
            }));
        });
    });

    app.post('/api/firefighter/sar/crisis/:crisis_id/victim', function(req, res) {
        var crisisID = req.params.crisis_id;
        var victim = req.body;

        return victimsDAO.insertVictimByCrisisID(crisisID, victim, function(err, result, fields) {
            if(err)
            {
                console.log(err);
                return res.status(500).json({'err': 'DB Error'});
            }

            return res.send(200);
        });
    });

    app.post('/api/firefighter/sar/vital/:vital_id', function(req, res) {
        var vitalID = req.params.vital_id;
        var reading = req.body;

        return victimsDAO.insertVictimVitalReading(vitalID, reading, function(err, result, fields) {
            if(err)
            {
                console.log(err);
                return res.status(500).json({'err': 'DB Error'});
            }

            return res.send(200);
        });
    });

    app.post('/api/firefighter/sar/victim/updatevital', function(req, res) {
        var data = req.body;

        return victimsDAO.updateVictimVitalID(data.vital_id, data.token, function(err, result, fields) {
            if(err)
            {
                console.log(err);
                return res.status(500).json({'err': 'DB Error'});
            }

            return res.send(200);
        });
    });
}
