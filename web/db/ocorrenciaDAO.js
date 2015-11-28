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

    this.obterOcorrenciaAberta = function(placaAmbulancia, callback) {
        var query = self.pool.query("SELECT * FROM ocorrencia AS ocr WHERE ocr.status LIKE 'ABERTO' \
            AND ocr.n_ambulancias_necessarias > (\
                SELECT COUNT(*) FROM atendimento_ambulancia WHERE ocorrencia_id = ocr.id\
            ) AND (SELECT COUNT(*) FROM atendimento_ambulancia WHERE ocorrencia_id = ocr.id \
                AND placa_ambulancia = ?) = 0 \
                ORDER BY ocr.data_abertura DESC LIMIT 1",
            [placaAmbulancia],
            function (err, rows) {
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
      var query = self.pool.query("SELECT * FROM cadastro_samu s\
       WHERE EXISTS (SELECT placa FROM ambulancia a WHERE s.samu_id=a.samu_id AND a.status = 'Ativo')", function (err, rows) {
          if (err) {
              callback(err, {});
          } else {
              var result = (rows ? rows : {});
              callback(null, result);
          }
      });
    };

    this.listarOcorrencia = function(obj, callback){
      var sql = "SELECT * FROM ocorrencia";
      if(obj.status)
        sql = sql + " WHERE status='"+obj.status+"'";

      var query = self.pool.query(sql, function (err, rows) {
          if (err) {
              callback(err, {});
          } else {
              var result = (rows ? rows : {});
              callback(null, result);
          }
      });
    };

    this.salvarOcorrencia = function(obj, callback) {
      var query = self.pool.query("INSERT INTO ocorrencia(data_abertura, status, n_ambulancias_necessarias, n_vitimas,\
         latitude, longitude, endereco, comentarios) VALUES (NOW(),'ABERTO',?,?,?,?,?,?)", [obj.qtdAmb, obj.qtdVitimas, obj.latitude,
           obj.longitude, obj.endereco, obj.observacao], function (err, rows) {
          if (err) {
              callback(err, {});
          } else {
              callback(null, {status: 'OK'});
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
