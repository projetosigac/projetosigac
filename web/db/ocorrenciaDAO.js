/**
 * Arquivo com funções de acesso a base de dados.
 * @author vinicius
 */

var db = require("./db");

/**
 * Data Access Object para ocorrencias.
 *
 * @param pool the database connection pool
 * @constructor
 */
function OcorrenciaDAO(pool) {
    var self = this;
    if (pool != null) {
        this.pool = pool;
    }

    this.obterOcorrenciaAberta = function(callback) {
        var query = self.pool.query("SELECT * FROM ocorrencia AS ocr WHERE ocr.status LIKE 'ABERTO' AND\
            ocr.n_ambulancias_necessarias > (\
                SELECT COUNT(*) FROM atendimento_ambulancia WHERE ocorrencia_id = ocr.id\
            ) ORDER BY ocr.data_abertura DESC LIMIT 1", function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows[0] : {});
                callback(null, result);
            }
        });
    };

    this.salvarAtendimento = function(atendimento, callback) {
        db.executarTransacao(self.pool, function(conn) {
            self.obterAtendimento(atendimento, function(err, result) {
                if (err) {
                    return callback(err, {});
                }
                if (result == null) {
                    conn.query("INSERT INTO atendimento_ambulancia(ocorrencia_id, placa_ambulancia) VALUES (?, ?)",
                        [atendimento.ocorrenciaId, atendimento.placaAmbulancia],
                        function (err, rows) {
                            callback(err, {});
                        });
                } else {
                    callback(null, {});
                }
            });
        });
    };

    this.obterAtendimento = function(atendimento, callback) {
        var query = self.pool.query("SELECT * FROM atendimento_ambulancia WHERE placa_ambulancia LIKE ? AND\
             ocorrencia_id = ?", [atendimento.placaAmbulancia, atendimento.ocorrenciaId], function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows[0] : {});
                callback(null, result);
            }
        });
    };

    this.obterBaseSamuAtiva = function(callback){
      var query = self.pool.query("select * from cadastro_samu s\
       where exists (select placa from ambulancia a where s.samu_id=a.samu_id and a.status = 'Ativo')", function (err, rows) {
          if (err) {
              callback(err, {});
          } else {
              var result = (rows ? rows[0] : {});
              callback(null, result);
          }
      });
    };
}

var ocorrenciaDAO = null;

module.exports = function (pool) {
    if (pool != null && ocorrenciaDAO == null) {
        ocorrenciaDAO = new OcorrenciaDAO(pool);
    }
    return ocorrenciaDAO;
};
