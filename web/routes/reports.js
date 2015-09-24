exports.list_all = function(req, res){

  req.getConnection(function(err,connection){


        data = {
          'reports': [
            {'id': 1,
             'lat': -23.200801,
             'lng': -45.892596},
            {'id': 2,
             'lat': -23.200106,
             'lng': -45.892260},
            {'id': 3,
             'lat': -23.199333,
             'lng': -45.891882},
            {'id': 4,
             'lat': -23.199458,
             'lng': -45.893147},
            {'id': 5,
             'lat': -23.200246,
             'lng': -45.892246},
            {'id': 6,
             'lat': -23.201785,
             'lng': -45.892933},
            {'id': 7,
             'lat': -23.202021,
             'lng': -45.894692},
            {'id': 8,
             'lat': -23.199221,
             'lng': -45.889328}
          ]
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
