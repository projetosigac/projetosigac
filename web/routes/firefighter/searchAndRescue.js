var util = require('../utils');
var crisisDAO = require('../../db/crisisDAO')();
var victimsDAO = require('../../db/victimsDAO')();

module.exports = function (app) {
    //TODO remove hard-coded data
    var commonOptions =
    {
        'title': 'SIGAC Web - Integrated Management System for Crisis and Incidents',
        'description': 'Sistema para Gerenciamento de Crises e sinais de pacientes',
        'author': 'SI-GAC Team',
        'navbarbrand': 'SIGAC Web - Firefighter - Search and Rescue',
        'toprightlinks':
        [
            {
                'text': 'Dashboard',
                'href': '/dashboard',
                'faicon': 'fa-users',
            },
        ]
    };

    app.get('/firefighter/sar', /*util.autenticarSessao,*/ function(req, res) {
        return crisisDAO.getCurrentCrisis(function (err, result, fields){
            if(err)
            {
                console.log(err);
                return res.status(500).send('DB Error');
            }

            var options = Object.create(commonOptions);

            options.content = {};
            options.content.results = result.map(function(row) {
                return {
                    'id': row.cri_id,
                    'description': row.cri_ds,
                    'category': row.cri_cat,
                    'affected': row.cri_afetados };
            });

            options.contentTemplate = 'crisis_view';

            return res.render('firefighter/searchandrescue/index', options);
        });
    });

    app.get('/firefighter/sar/crisis/:crisis_id/victim', util.autenticarSessao, function(req, res) {
        return victimsDAO.getVictimsByCrisisID(req.params.crisis_id, function (err, result, fields){
            if(err)
            {
                console.log(err);
                return res.status(500).send('DB Error');
            }

            var options = Object.create(commonOptions);

            options.content = {};
            options.content.results = result.map(function(row) {
                return {
                    'token': row.token,
                    'name': row.nome,
                    'sex': row.sexo,
                    'status': row.status,
                    'age': row.age,
                    'crisis': row.cri_ds
                };
            });

            options.contentTemplate = 'victims_view';

            return res.render('firefighter/searchandrescue/index', options);
        });
    });
}
