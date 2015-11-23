var util = require('../utils');
var stationDAO = require('../../db/stationDAO')();

module.exports = function (app) {
    app.get('/api/firefighter/raa/stations', /* util.autenticarSessao,*/ function(req, res) {
        return stationDAO.getStations(function(err, result, fields) {
            if(err)
            {
                console.log(err);
                return res.status(500).send('DB Error');
            }

            return res.json(result.map(function(row) {
                return {
                    'id': row.station_id,
                    'name': row.station_name,
                    'last_report': row.station_last_report,
                    'latitude': row.station_lat,
                    'longitude': row.station_lon,
                    'map_zoom': row.station_map_zoom, };
            }));
        });
    });

    app.get('/api/firefighter/raa/station/perimeter/:station_id', /* util.autenticarSessao,*/ function(req, res) {
        return stationDAO.getStationPerimeter(req.params.station_id, function(err, result, fields) {
            if(err)
            {
                console.log(err);
                return res.status(500).send('DB Error');
            }

            return res.json(result.map(function(row) {
                return {
                    'lat': row.station_perimeter_node_latitude,
                    'lng': row.station_perimeter_node_longitude,
                };
            }));
        });
    });

    app.get('/api/firefighter/raa/station/devices/:station_id', /* util.autenticarSessao,*/ function(req, res) {
        return stationDAO.getStationDevices(req.params.station_id, function(err, result, fields) {
            if(err)
            {
                console.log(err);
                return res.status(500).send('DB Error');
            }

            return res.json(result.map(function(row) {
                return {
                    'id': row.device_id,
                    'last_reading': row.device_last_reading,
                    'name': row.device_name,
                    'lat': row.device_latitude,
                    'lng': row.device_longitude,
                };
            }));
        });
    });
}