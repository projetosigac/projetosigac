var express = require('express');
var url = require('url');
var app = express();
var pg = require('pg');

app.set('port', (process.env.PORT || 5000));
app.use(express.static(__dirname + '/public'));

// TODO
// Connect to database

app.get('/', function(request, response) {

	var url_parts = url.parse(request.url, true);
	var query = url_parts.query.q;

	if (typeof query == 'undefined') {
		response.send('query is not defined');
	}

	// TODO
	// Send query to database and get response
	pg.connect(process.env.DATABASE_URL, function(err, client, done) {
    client.query(query, function(err, result) {
      done();
      if (err)
       { console.error(err); response.send("Error " + err); }
      else
       { response.json(result.rows);}
    });
  });

	// TODO
	// Send json response

	// TODO access
})

app.listen(app.get('port'), function() {
  console.log("Node app is running at localhost:" + app.get('port'))
})
