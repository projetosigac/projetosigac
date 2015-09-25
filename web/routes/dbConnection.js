// Database configuration
var HOST            = 'localhost';
var PORT            = 3306;
var MYSQL_USER      = 'root';
var MYSQL_PASS      = 'mysql';
var DATABASE        = 'sigac';
//end of configuration

var mysql = require('mysql');

var db = null;

exports.getDb = function(){
    if(!db) {
        db = mysql.createClient({
            host:       HOST,
            port:       PORT,
            user:       MYSQL_USER,
            password:   MYSQL_PASS
        });
    };
    return db;
}

/*
var connection = mysql.createConnection({
  host     : 'localhost',
  user     : 'me',
  password : 'secret',
  database : 'my_db'
});
 
connection.connect();
 
connection.query('SELECT 1 + 1 AS solution', function(err, rows, fields) {
  if (err) throw err;
 
  console.log('The solution is: ', rows[0].solution);
});
 
connection.end();
*/

/*module.exports = function () {
    if(!db) {
        db = mysql.createClient({
            host:       HOST,
            port:       PORT,
            user:       MYSQL_USER,
            password:   MYSQL_PASS
        });
    };
    return db;
};*/