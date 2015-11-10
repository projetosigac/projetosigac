/*
 * Funcionalidades envolvendo a página de atendimento
 */
exports.carregarPagina = function(req, res){
    var lock = 1;
    var pacientes = [];

    var finishRequest = function() {
        res.render('uti/vitimas', { pacientes: pacientes });
    }

    req.getConnection(function(err,connection) {
        var queryStr = 'SELECT DISTINCT paciente_id FROM sigac.paciente_status';
        var query = connection.query(queryStr, function(err,rows,fields) {
            if (err) {
                console.log("Error Query : %s ",err );
            } else {
                lock = rows.length;

                for (var i in rows) {
                    var id = rows[i].paciente_id;
                    queryStr = 'SELECT * FROM sigac.paciente_status WHERE paciente_id=' + id + ' ORDER BY timestamp DESC LIMIT 1';

                    var query = connection.query(queryStr, function(err,rows,fields) {
                        if(err) {
                            console.log("Error Query : %s ",err );
                        } else {
                            pacientes.push(rows[0]);
                            lock -=1;
                        }
                        if (lock === 0) {
                            finishRequest();
                        }
                    });
                }
            }
        });
    }); 
};
