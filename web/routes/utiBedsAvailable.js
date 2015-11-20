/*
 * Mostra camas de UTI disponiveis nos hospitais
 */
exports.carregarPagina = function(req, res){

	req.getConnection(function(err,connection){  
		var queryStr = 'SELECT hospital, leitos_total, leitos_ocupados FROM sigac.hospitais';
        var query = connection.query(queryStr, function(err,rows,fields)
        {
            if(err)
                console.log("Error Query : %s ",err );

            else
            {
				res.render('uti/bedsAvailable', { dados: rows });              
            }                
        });
    }); 


    
};