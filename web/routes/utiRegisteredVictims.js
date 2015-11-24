/*
 * Mostra vitimas cadastradas
 */
 var util = require('util');
exports.carregarPagina = function(req, res){

	req.getConnection(function(err,connection){  
        var queryStr;
        if (req.params.cId)
            queryStr = 'SELECT * FROM sigac.vitimas as v INNER JOIN sigac.crise as c ON c.cri_id = v.crise WHERE crise=' + req.params.cId;
        else
            queryStr = 'SELECT * FROM sigac.vitimas';
        var query = connection.query(queryStr, function(err,rows,fields)
        {
            if(err)
                console.log("Error Query : %s ",err );

            else
            {
				res.render('uti/registeredVictims', { dados: rows });              
            }                
        });
    });}; 
 exports.registrarObito = function (req,res)
        {
            console.log(util.inspect(req.body, {showHidden: true, depht: null}));
            req.getConnection(function(err,connection)
            {
                            console.log("o token eh " + req.body + "   " + req.body.token);
                            var i = req.body.token;
                            var queryStr = "UPDATE vitimas set obito = 'S' where token = " + i;
                            var query = connection.query(queryStr, function(err, rows, fields) {
              if (err)
                console.log('Error while performing Query.' + err);
            })
            });
            res.redirect('uti/registeredVictims');
        };

