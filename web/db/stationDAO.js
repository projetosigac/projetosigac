/**
 * Station database access object
 * @author Paulo Henrique Aguiar(https://github.com/PauloAguiar)
 */

var db = require("./db");
var stationDAO;

if(typeof stationDAO === 'undefined')
{
    stationDAO = {};

    (function(dao) {
        var _pool;

        dao.setPool = function(pool) {
            if(typeof pool === 'undefined' || pool === null)
                throw 'Pool is null or undefined';
            _pool = pool;
            return this;
        };

        dao.getStations = function(callback) {
            return _pool.query(
                {
                    sql: 'SELECT * FROM stations'
                },
                function(err, results, fields) {
                    if(err)
                        return callback(err, {});
                    return callback(null, results);
                }
            );
        };

        dao.getStationPerimeter = function(stationID, callback) {
            return _pool.query(
                {
                    sql: 'SELECT * FROM station_perimeter_nodes WHERE station_id = ' + stationID + ' ORDER BY station_perimeter_node_id ASC;'
                },
                function(err, results, fields) {
                    if(err)
                        return callback(err, {});
                    return callback(null, results);
                }
            );
        };

        dao.getStationDevices = function(stationID, callback) {
            return _pool.query(
                {
                    sql: 'SELECT * FROM station_devices WHERE station_id = ' + stationID + ' ORDER BY device_id ASC;'
                },
                function(err, results, fields) {
                    if(err)
                        return callback(err, {});
                    return callback(null, results);
                }
            );
        };

        dao.registerStationDevice = function(stationID, device, callback) {
            return _pool.query(
                {
                    sql: 'INSERT INTO station_devices \
                            (device_id, device_name, station_id, device_description) \
                          VALUES \
                            (' + device.id + ', \'' + device.name + '\', ' + stationID + ',\'' + device.description + '\');'
                },
                function(err, results, fields) {
                    if(err)
                        return callback(err, {});
                    return callback(null, results);
                }
            );
        };

        dao.updateDeviceLastReading = function(deviceID, timestamp, callback) {
            return _pool.query(
                {
                    sql: 'UPDATE station_devices \
                          SET device_last_reading = '+ timestamp + '\
                          WHERE \
                            device_id = ' + deviceID +';'
                },
                function(err) {
                    if(err)
                        return callback(err, {});
                    return callback(null, {});
                }
            );
        };

        dao.registerStationDeviceReading = function(device, reading, callback) {
            return _pool.query(
                {
                    sql: 'INSERT INTO station_device_readings \
                            (device_id, reading_timestamp, reading_value) \
                          VALUES \
                            (' + device.id + ', ' + reading.timestamp + ', ' + reading.value + ');'
                },
                function(err, results, fields) {
                    if(err)
                        return callback(err, {});
                    return callback(null, results);
                }
            );
        };

        dao.getDeviceReadings = function(deviceID, callback) {
            return _pool.query(
                {
                    sql: 'SELECT * FROM station_device_readings WHERE device_id = ' + deviceID + ' ORDER BY reading_timestamp DESC LIMIT 20;'
                },
                function(err, results, fields) {
                    if(err)
                        return callback(err, {});
                    return callback(null, results);
                }
            );
        };
    }(stationDAO));
}

module.exports = function(pool) {
    if(pool)
        return stationDAO.setPool(pool);
    return stationDAO;
}

