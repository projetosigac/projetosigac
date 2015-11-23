/**
 * Arquivo com funções de acesso a base de dados.
 * @author Danilo Ramalho
 */

var db = require("./db");

/**
 * Data Access Object para hospital.
 *
 * @param pool the database connection pool
 * @constructor
 */
function HospitalDAO(pool) {
    var self = this;
    if (pool != null) {
        this.pool = pool;
    }

    this.listarLeitoDisponivel = function(callback) {
        var query = self.pool.query("SELECT *, (leitos_total-leitos_ocupados) as leitos_disponiveis FROM hospitais WHERE leitos_ocupados < leitos_total", function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows : {});
                callback(null, result);
            }
        });
    };
}

var hospitalDAO = null;

module.exports = function (pool) {
    if (pool != null && hospitalDAO == null) {
        hospitalDAO = new HospitalDAO(pool);
    }
    return hospitalDAO;
};
