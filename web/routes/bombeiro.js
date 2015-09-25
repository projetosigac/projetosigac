
/*
 * GET firefighter functions.
 */

exports.list = function(req, res){

  req.getConnection(function(err,connection){
       
        var query = connection.query('SELECT * FROM bracelet_info',function(err,rows)
        {
            connection.connect();
            if(err)
                console.log("Error Selecting : %s ",err );
     
            res.render('edit_customer',{page_title:"Vitimas",data:rows});
                
            connection.end();
           
         });
         
         console.log(query.sql);
    });
  
};

exports.classifyVictim = function(req, res){
    
    var input = JSON.parse(JSON.stringify(req.body));
    
  req.getConnection(function(err,connection){
       
        var data = {
            
            //bra_trans_id    : input.color,
            bra_barcode     : input.barcode,
            bra_color       : input.color,
            bra_token       : input.token,
        
        };
        
         var query = connection.query("INSERT INTO bracelet_info set pes_bra_token ? ",data, function(err, rows)
        {
  
          if (err)
              console.log("Error inserting : %s ",err );          
        });
        
        query = connection.query("INSERT INTO customer set pes_bra_token ? ",data.bra_token, function(err, rows)
        {
  
          if (err)
              console.log("Error inserting : %s ",err );
         
          res.redirect('/customers');
          
        });
         console.log(query.sql);
    });
  
};

exports.getVictimsOfColor = function(req, res){
    
    var color = req.query.color;
    var getNames = req.query.getNames;
    
    req.getConnection(function(err,connection){
            
            if(getNames){
                var query = connection.query('SELECT bra_trans_id,bra_token FROM bracelet_info WHERE bra_color = ? INNER JOIN customer ON bracelet_info.bra_token = customer.pes_id',color,function(err,rows)
                {
                    
                    if(err)
                        console.log("Error Selecting : %s ",err );
            
                
                });
                
                console.log(query.sql);
            }

        });
  
};

exports.colorCounter = function(req, res){
    
    var color = req.query.color;
    
    req.getConnection(function(err,connection){
        
            var query = connection.query('SELECT COUNT(bra_trans_id)FROM bracelet_info WHERE bra_color = ?',color,function(err,rows)
            {
                
                if(err)
                    console.log("Error Selecting : %s ",err );
  
            });
            
            console.log(query.sql);
        });
  
};

exports.deleteBracelet = function(req, res){
    
    var token = req.query.token;
    
    req.getConnection(function(err,connection){
        
            var query = connection.query('DELETE FROM bracelet_info WHERE bra_token = ?',token,function(err,rows)
            {
                
                if(err)
                    console.log("Error Selecting : %s ",err );

            });
            
            query = connection.query('DELETE FROM customer WHERE pes_bra_token = ?',token,function(err,rows)
            {
                
                if(err)
                    console.log("Error Selecting : %s ",err );

            });
            
            console.log(query.sql);
        });
  
};
