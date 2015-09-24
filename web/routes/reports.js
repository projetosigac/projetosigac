exports.get_list = function(req, res){

  var distancePoints = function(p1, p2) {
    var rad = function(x) {
      return x * Math.PI / 180;
    };

    var R = 6378137;
    var dLat = rad(p2.lat - p1.lat);
    var dLong = rad(p2.lng - p1.lng);
    var a = Math.sin(dLat / 2) * Math.sin(dLat / 2) +
    Math.cos(rad(p1.lat)) * Math.cos(rad(p2.lat)) *
    Math.sin(dLong / 2) * Math.sin(dLong / 2);
    var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
    var d = R * c;
    return d;
  };

  var r = req.query.r;
  var p1 = JSON.parse(req.query.center);


  if (typeof(r) == "undefined" || typeof(p1) == "undefined") {
    r = 99999999;
    p1 = {'lat':0, 'lng':0};
  }

  req.getConnection(function(err,connection) {

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

    var filtered_reports = [];
    for (var i=0; i<data.reports.length; i++) {
      var p2 = data.reports[i];
      if (distancePoints(p1, p2) < r)
        filtered_reports.push(p2);
    }

    var filtered_data = {'reports': filtered_reports};

    res.send(JSON.stringify(filtered_data, null, 3));

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
