/*
 * Funcionalidades envolvendo a página de atendimento
 */
exports.carregarPagina = function(req, res){

	req.getConnection(function(err,connection){  
		var queryStr = 'SELECT * FROM sigac.vitimas_status WHERE id_vitima=' + req.params.pId + ' ORDER BY timestamp DESC';
        var query = connection.query(queryStr, function(err,rows,fields)
        {
            if(err)
                console.log("Error Query : %s ",err );

            else
            {
				res.render('uti/vitima', { dados: rows });              
            }                
        });
    }); 


    
};
