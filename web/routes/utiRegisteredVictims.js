/*
 * Mostra vitimas cadastradas
 */
exports.carregarPagina = function(req, res){

	req.getConnection(function(err,connection){  
		var queryStr = 'SELECT * FROM sigac.vitimas';
        var query = connection.query(queryStr, function(err,rows,fields)
        {
            if(err)
                console.log("Error Query : %s ",err );

            else
            {
				res.render('uti/registeredVictims', { dados: rows });              
            }                
        });
    }); 


    
};
