var db = require("./db");

/**
 * Data Access Object para localizacao de ambulancias.
 *
 * @param pool the database connection pool
 * @constructor
 */
function LocalizacaoAmbulanciaDAO(pool) {
    var self = this;
    if (pool != null) {
        this.pool = pool;
    }

    this.listarLocalizacoes = function(callback) {
        self.pool.query("SELECT * FROM localizacao_ambulancia",
            function(err, rows) {
                if (err) {
                    callback(err, {});
                } else {
                    var result = (rows ? rows[0] : null);
                    callback(null, result);
                }
            });
    };

    this.obterLocalizacaoRecente = function(placa, callback) {
        self.pool.query("SELECT * FROM localizacao_ambulancia WHERE placa_ambulancia LIKE ? ORDER BY data DESC LIMIT 1",
            [placa],
            function(err, rows) {
                if (err) {
                    callback(err, {});
                } else {
                    var result = (rows ? rows[0] : null);
                    callback(null, result);
                }
            });
    };

    this.salvarLocalizacao = function(localizacao, callback) {
        db.executarTransacao(self.pool, function(conn) {
            self.obterLocalizacaoRecente(localizacao.placa, function(err, result) {
                if (err) {
                    return callback(err, {});
                }
                if (result) {
                    conn.query("UPDATE localizacao_ambulancia SET latitude=?, longitude=?, data=NOW() WHERE placa_ambulancia = ?",
                    [localizacao.latitude, localizacao.longitude, localizacao.placa],
                    function(err, rows) {
                        callback(err, {});
                    });

                } else {
                    conn.query("INSERT INTO localizacao_ambulancia(placa_ambulancia, latitude, longitude) VALUES (?, ?, ?)",
                        [localizacao.placa, localizacao.latitude, localizacao.longitude],
                        function (err, rows) {
                            callback(err, {});
                        });
                }

            });

        });
    };

}

var localizacaoAmbulanciaDAO = null;

module.exports = function (pool) {
    if (pool != null && localizacaoAmbulanciaDAO == null) {
        localizacaoAmbulanciaDAO = new LocalizacaoAmbulanciaDAO(pool);
    }
    return localizacaoAmbulanciaDAO;
};



