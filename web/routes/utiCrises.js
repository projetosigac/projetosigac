/*
 * Funcionalidades envolvendo a página de atendimento
 */
exports.carregarPagina = function(req, res){

	req.getConnection(function(err,connection){  
        var queryStr;
        if (req.params.cId)
            queryStr = 'SELECT * FROM sigac.crise WHERE cri_id=' + req.params.cId;
        else
            queryStr = 'SELECT * FROM sigac.crise';
        var query = connection.query(queryStr, function(err,rows,fields)
        {
            if(err)
                console.log("Error Query : %s ",err );

            else
            {
				res.render('uti/crises', { dados: rows });              
            }                
        });
    }); 

};
