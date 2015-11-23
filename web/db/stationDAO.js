/**
 * Station database access object
 * @author Paulo Henrique Aguiar(https://github.com/PauloAguiar)
 */

var db = require("./db");
var stationDAO;

debugger;

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
    }(stationDAO));
}

module.exports = function(pool) {
    if(pool)
        return stationDAO.setPool(pool);
    return stationDAO;
}

