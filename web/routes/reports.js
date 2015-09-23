exports.list_all = function(req, res){

  req.getConnection(function(err,connection){


        data = {
          'row1': 'value1',
          'row2': 10,
        }
        res.send(JSON.stringify(data, null, 3));

        // TODO(andresnds): toogle this when database is ready
        // var query = connection.query('SELECT * FROM boletim',function(err,rows)
        // {

        //     if(err)
        //         console.log("Error Selecting : %s ",err );

        //     res.send(JSON.stringify(rows, null, 3));

        //  });

         //console.log(query.sql);
    });

};
