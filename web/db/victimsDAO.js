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

        dao.getVictimsByCrisisID = function(crisisID, callback) {
            return _pool.query(
                {
                    sql: 'SELECT * FROM vitimas WHERE crise = ' + crisisID + ' ORDER BY id ASC;'
                },
                function(err, results, fields) {
                    if(err)
                        return callback(err, {});
                    return callback(null, results);
                }
            );
        };

        dao.insertVictimByCrisisID = function(crisisID, victim, callback) {
            return _pool.query(
                {
                    sql: 'INSERT INTO sigac.vitimas \
                            (crise, token, nome, sexo, status, age) \
                        VALUES (?, ?, ?, ?, ?, ?)',
                    values: [crisisID, victim.token, victim.name, victim.sex, victim.status, victim.age]
                },
                function(err, results, fields) {
                    if(err)
                        return callback(err, {});
                    return callback(null, results);
                }
            );
        };

        dao.insertVictimVitalReading = function(vitalID, reading, callback) {
            return _pool.query(
                {
                    sql: 'INSERT INTO vital_readings \
                            (vital_id, reading, timestamp) \
                        VALUES (?, ?, ?)',
                    values: [vitalID, reading.value, reading.timestamp]
                },
                function(err, results, fields) {
                    if(err)
                        return callback(err, {});
                    return callback(null, results);
                }
            );
        };

        dao.updateVictimVitalID = function(vitalID, token, callback) {
            console.log(vitalID);
            console.log(token);
            return _pool.query(
                {
                    sql: 'UPDATE vitimas \
                            SET vital_id=? \
                            WHERE token=?;',
                    values: [vitalID, token]
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

