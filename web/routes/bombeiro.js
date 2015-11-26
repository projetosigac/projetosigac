
/*
 * GET firefighter functions.
 */

//var o2x = require('object-to-xml')

exports.iniVictim = function(req, res){
    
  var input = JSON.parse(JSON.stringify(req.body));
    
  req.getConnection(function(err,connection){
       
        var data = {
            
            bra_tag     : input.tag,
        
        };
        
        var flagCommit = true
        
        var query = connection.query('SELECT COUNT(bra_token) AS braceletCount FROM bracelet_info WHERE bra_token = ?',[data.bra_tag],function(err, rows)
        {
            console.log('Query result: ', rows[0].braceletCount);
            if(err)
            {
                console.log("Error counting Bracelet Token %s!",[data.bra_tag])
                res.status(404).send("Error counting Bracelet Token %s!",[data.bra_tag])
                flagCommit = true
            }
            if(rows[0].braceletCount>=1)
            {
                console.log("Bracelet Token %s already exists!",[data.bra_tag])
                res.status(400).send("Bracelet Token  already exists!")//,[data.bra_tag])
                flagCommit = true
            }
                
        })
        
        if(!flagCommit)
        {
            var query = connection.query("INSERT INTO bracelet_info (bra_token) VALUES (?)",[data.bra_tag], function(err, rows)
        {
  
          if (err)
              console.log("Error inserting : %s ",err );          
        });
        console.log(query.sql);
        
        query = connection.query("INSERT INTO vitimas (token) VALUES (?) ",[data.bra_tag], function(err, rows)
        {
  
          if (err)
              console.log("Error inserting : %s ",err );
          res.json(true);
          
        });
         console.log(query.sql);
        }
         
    });
  
};

exports.getBraceletList = function(req, res){
    
  req.getConnection(function(err,connection){

        var query = connection.query('SELECT * FROM bracelet_info',function(err,rows)
        {

            if(err)
                console.log("Error Selecting : %s ",err );
            
            res.json(rows)
            //res.render('bombeiro',{page_title:"Bombeiro - Node.js",data:rows});

         });
         
         console.log(query.sql);
    });
  
};

exports.getVictimList = function(req, res){
    
  req.getConnection(function(err,connection){
      
        var query = connection.query('SELECT * FROM vitimas',function(err,rows)
        {

            if(err)
                console.log("Error Selecting : %s ",err );
     
            res.json(rows)
            
         });
         
         console.log(query.sql);
    });
  
};

exports.classifyVictim = function(req, res){
    
    var input = JSON.parse(JSON.stringify(req.body));
    
  req.getConnection(function(err,connection){
       
        var data = {
           
            bra_barcode     : input.barcode,
            bra_color       : input.color,
            bra_token       : input.token,
        
        };
        
         var query = connection.query("INSERT INTO bracelet_info set pes_bra_token ? ",data, function(err, rows)
        {
  
          if (err)
              console.log("Error inserting : %s ",err );          
        });
        
        query = connection.query("INSERT INTO customer set pes_bra_token ? ",[data.bra_token], function(err, rows)
        {
  
          if (err)
              console.log("Error inserting : %s ",err );
         
          res.json(true);
          
        });
         console.log(query.sql);
    });
  
};

exports.getVictimsOfColor = function(req, res){
    
    var color = req.query.color;
    
    req.getConnection(function(err,connection){
            
            var query = connection.query('SELECT bra_trans_id,bra_token FROM bracelet_info WHERE bra_color = ? INNER JOIN customer ON bracelet_info.bra_token = customer.pes_bra_token',[color],function(err,rows)
            {
                
                if(err)
                    console.log("Error Selecting : %s ",err );

                res.json(rows[0]);
            
            });
            
            console.log(query.sql);
        });
  
};

exports.colorCounter = function(req, res){
    
    var color = req.query.color;
    
    req.getConnection(function(err,connection){
        
            var query = connection.query('SELECT COUNT(bra_color) FROM bracelet_info WHERE bra_color = ?',[color],function(err,rows) //
            {
                
                if(err)
                    console.log("Error Selecting : %s ",err );
                
                res.json(rows[0]);
  
            });
            
            console.log(query.sql);
        });
  
};

exports.deleteBracelet = function(req, res){
    
    var token = req.query.token;
    
    req.getConnection(function(err,connection){
        
            var query = connection.query('DELETE FROM bracelet_info WHERE bra_token = ?',[token],function(err,rows)
            {
                
                if(err)
                    console.log("Error Selecting : %s ",err );

            });
            
            query = connection.query('DELETE FROM customer WHERE pes_bra_token = ?',[token],function(err,rows)
            {
                
                if(err)
                    console.log("Error Selecting : %s ",err );

            });
            
            console.log(query.sql);
        });
  
};
