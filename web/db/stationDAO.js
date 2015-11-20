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
    }(stationDAO));
}

module.exports = function(pool) {
    if(pool)
        return stationDAO.setPool(pool);
    return stationDAO;
}

