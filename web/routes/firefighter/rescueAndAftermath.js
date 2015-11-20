var util = require('../utils');
var stationDAO = require('../../db/stationDAO')();

module.exports = function (app) {
    //TODO remove hard-coded data
    var commonOptions =
    {
        'title': 'SIGAC Web - Integrated Management System for Crisis and Incidents',
        'description': 'Sistema para Gerenciamento de Crises e sinais de pacientes',
        'author': 'SI-GAC Team',
        'navbarbrand': 'SIGAC Web - Firefighter - Rescue and Aftermath',
        'toprightlinks':
        [
            {
                'text': 'On Field Stations',
                'href': '/dashboard/firefighter/raa/onfieldstations',
                'faicon': 'fa-wifi',
            },
            {
                'text': 'Dashboard',
                'href': '/dashboard',
                'faicon': 'fa-users',
            },
        ]
    };

    app.get('/dashboard/firefighter/raa/onfieldstations', util.autenticarSessao, function(req, res) {
        return stationDAO.getStations(function(err, result, fields) {
            if(err)
            {
                console.log(err);
                return res.status(500).send('DB Error');
            }

            var options = Object.create(commonOptions);

            options.content = result.map(function(row) {
                return {
                    'id': row.station_id,
                    'name': row.station_name,
                    'last_report': row.station_last_report ? row.station_last_report : 'Nunca' };
            });

            options.contentTemplate = 'stations';
            return res.render('firefighter/rescueandaftermath/index', options);
        });
    });

    app.get('/dashboard/firefighter/raa', util.autenticarSessao, function(req, res) {
        return res.render('firefighter/rescueandaftermath/index', commonOptions);
    });
}