/**
 * Crisis database access object
 * @author Marrcio V Ramos(https://github.com/marrcio)
 */

var db = require("./db");
var crisisDAO;

if(typeof crisisDAO === 'undefined')
{
    crisisDAO = {};

    (function(dao) {
        var _pool;

        dao.setPool = function(pool) {
            if(typeof pool === 'undefined' || pool === null)
                throw 'Pool is null or undefined';
            _pool = pool;
            return this;
        };

        dao.getCurrentCrisis = function(callback) {
            return _pool.query(
                {
                    sql: "SELECT * FROM sigac.crise WHERE cri_status='In progress' ORDER BY cri_afetados DESC;"
                },
                function(err, results, fields) {
                    if(err)
                        return callback(err, {});
                    return callback(null, results);
                }
            );
        };

    }(crisisDAO));
}

module.exports = function(pool) {
    if(pool)
        return crisisDAO.setPool(pool);
    return crisisDAO;
}

