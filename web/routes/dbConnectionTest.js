var mysql = require('mysql');

exports.getDBtest = function(req,res){
    var connection = mysql.createConnection(
        {
            host: 'localhost',
            user: 'root',
            password : 'mysql',
            port : 3306, //port mysql
            database:'sigac'
        }
    );
    
    connection.connect();
    
    var queryString = 'SELECT * FROM wp_posts';
    
    connection.query(queryString, function(err, rows, fields) {
        if (err) throw err;
    
        for (var i in rows) {
            console.log('Post Titles: ', rows[i].post_title);
        }
    });
    
    connection.end();
}

