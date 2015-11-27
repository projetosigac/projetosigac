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
                            if(req.body.obito != 'S')
                            {
                                var i = req.body.token;
                                var queryStr = "select hospital from vitimas where token = " + i;
                                console.log(queryStr);
                                var query = connection.query(queryStr, function(err, rows, fields) {
                                if (err)
                                console.log('Error while performing Query.' + err);
                                else
                                {
                                    //console.log("executou a query");
                                    //console.log("o resultado eh ");
                                    var nome_hospital = console.log(rows[0].hospital);
                                    //console.log(nome_hospital);
                                    var queryStr2 = "select leitos_ocupados from hospitais where hospital = " + "'" + rows[0].hospital + "'";
                                    //console.log("queryStr2 eh " + queryStr2);
                                    query = connection.query(queryStr2, function(err, rows, fields) {
                                    if (err)
                                    console.log('Error while performing Query.' + err);
                                    else
                                    {   /*
                                        console.log("executou a query2");
                                        console.log("o resultado eh ");*/
                                        nome_hospital = console.log(rows[0].leitos_ocupados - 1);
                                        var leitos_final = rows[0].leitos_ocupados;
                                        queryStr3=queryStr2.split("'")[1];
                                        //console.log(queryStr2.split("'")[1]);
                                        queryStr3 = "UPDATE hospitais set leitos_ocupados = "
                                        //console.log(queryStr3);
                                        queryStr3 = queryStr3.concat(leitos_final-1);
                                        //console.log(queryStr3);
                                        queryStr3 = queryStr3 + " where hospital =" + "'" +queryStr2.split("'")[1] +"'";
                                        //console.log(queryStr3);
                                        query = connection.query(queryStr3, function(err, rows, fields) {
                                        if (err)
                                        console.log('Error while performing Query.' + err);
                                        });



                                    }
                                    });
                                }
                                });
                                
                                queryStr = "UPDATE vitimas set obito = 'S' where token = " + req.body.token;
                                var query = connection.query(queryStr, function(err, rows, fields) {
                                if (err)
                                console.log('Error while performing Query.' + err);
                                }) 
                            }
            });
            res.redirect(req.get('referer'));
        };

