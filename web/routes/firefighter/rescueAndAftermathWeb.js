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
                'text': 'Stations Map',
                'href': '/dashboard/firefighter/raa',
                'faicon': 'fa-map',
            },
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
        ],
        'footerJavascriptURLs':
        [
            'https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js', // jQuery
            '/bower_components/bootstrap/dist/js/bootstrap.min.js',             // Bootstrap Core JavaScript
            '/bower_components/metisMenu/dist/metisMenu.min.js',                // Metis Menu Plugin JavaScript
            '/bower_components/metisMenu/dist/metisMenu.min.js',                // Metis Menu Plugin JavaScript
            '/dist/js/sb-admin-2.js',                                           // Custom Theme JavaScript
        ],
        'headerStylesheetURLs':
        [
            '/bower_components/bootstrap/dist/css/bootstrap.min.css',                      // Bootstrap Core CSS
            '/bower_components/metisMenu/dist/metisMenu.min.css',                          // MetisMenu CSS
            '/dist/css/sb-admin-2.css',                                                    // Custom CSS
            'https://maxcdn.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.min.css', // Custom Fonts
        ],
        'customFooterJavascriptURLs':
        [],
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

    app.get('/dashboard/firefighter/raa', /* util.autenticarSessao ,*/ function(req, res) {
        var options = Object.create(commonOptions);

        options.customFooterJavascriptURLs = [
            'http://maps.google.com/maps/api/js',
            '/js/firefighter/stationsMap.js'];

        options.contentTemplate = 'stations_map';
        return res.render('firefighter/rescueandaftermath/index', options);
    });

    //app.get('/dashboard/firefighter/raa/station/:station_id', util.autenticarSessao, function(req, res) {
    app.get('/dashboard/firefighter/raa/station/:station_id', function(req, res) {

        return stationDAO.getStationDevices(req.params.station_id, function(err, result, fields) {
            if(err)
            {
                console.log(err);
                return res.status(500).send('DB Error');
            }

            var options = Object.create(commonOptions);

            options.content = result.map(function(row) {
                return {
                    'id': row.device_id,
                    'name': row.device_name,
                    'last_reading': row.device_last_reading ? row.device_last_reading : 'Nunca' };
            });

            options.contentTemplate = 'station_details';
            return res.render('firefighter/rescueandaftermath/index', options);
        });

    });
}