/**
 * Arquivo com funções de acesso a base de dados.
 * @author vinicius
 */

exports.obterOcorrenciaAberta = function(conn, oncomplete) {
    var query = conn.query("SELECT * FROM ocorrencia AS ocr WHERE ocr.status LIKE 'ABERTO' AND\
            ocr.n_ambulancias_necessarias > (\
                SELECT COUNT(*) FROM dd atendimento_ambulancia WHERE ocorrencia_id = ocr.id\
            ) ORDER BY ocr.data_abertura DESC LIMIT 1", function (err, rows) {
        if (err) {
            oncomplete(err, {});
        } else {
            var result = (rows ? rows[0] : {});
            oncomplete(null, result);
        }
    });
};

exports.salvarAtendimento = function(conn, oncomplete, atendimento) {
    exports.executarTransacao(conn, function() {
        conn.query("INSERT INTO atendimento_ambulancia(ocorrencia_id, placa_ambulancia) VALUES (?, ?)",
            [atendimento.ocorrenciaId, atendimento.placaAmbulancia],
            function (err, rows) {
                oncomplete(err, {});
            });
    });
};

exports.executarTransacao = function(conn, cmd, onError) {
    try {
        conn.beginTransaction(function (err) {
            if (err) {
                throw err;
            }
            cmd(conn);
            conn.commit(function(err) {
                if (err) {
                    return conn.rollback(function() {
                        throw err;
                    });
                }
            });
        });
    } catch (err) {
        if (onError != null) {
            onError(err);
        }
        return conn.rollback(function() {
           throw err;
        });
    }
};