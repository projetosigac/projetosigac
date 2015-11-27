var util = require('../utils');

module.exports = function (app) {
    //TODO remove hard-coded data
    var commonOptions =
    {
        'title': 'SIGAC Web - Integrated Management System for Crisis and Incidents',
        'description': 'Sistema para Gerenciamento de Crises e sinais de pacientes',
        'author': 'SI-GAC Team',
        'navbarbrand': 'SIGAC Web - Firefighter - Search and Rescue',
        'toprightlinks':
        [
            /*{
                'text': 'On Field Stations',
                'href': '/dashboard/firefighter/raa/onfieldstations',
                'faicon': 'fa-wifi',
            },*/
            {
                'text': 'Dashboard',
                'href': '/dashboard',
                'faicon': 'fa-users',
            },
        ]
    };

    app.get('/dashboard/firefighter/sar', /*util.autenticarSessao,*/ function(req, res) {
        req.getConnection(function(err, connection) {
            connection.query('SELECT * FROM vitimas', function(err, victms) {
                if (err) {
                    console.log("Error Selecting : %s ", err);
                    res.status(500);
                    res.send();
                    return;
                }

                console.log(victms);

                var options = Object.create(commonOptions);
                options.victms = victms;
                res.render('firefighter/searchandrescue/index', options);
            });
        });
    });

    app.post('/dashboard/firefighter/sar', function(req, res) {
        var data = req.body;

        req.getConnection(function(err, connection) {
            var token = data.token;
            var nome = data.name;
            var sexo = data.gender;

            var values = '\"' + token + '\", \"' + nome + '\", \"' + sexo + '\"';
            var query = 'INSERT INTO vitimas (token, nome, sexo) VALUES (' + values + ')';

            connection.query(query, function(err) {
                if (err) {
                    console.log("Error Selecting : %s ", err);
                    res.status(500);
                    res.send('ERROR');
                    return;
                }



                connection.query('SELECT * FROM vitimas', function(err, victms) {
                    if (err) {
                        console.log("Error Selecting : %s ", err);
                        res.status(500);
                        res.send();
                        return;
                    }

                    // console.log(victms);

                    var options = Object.create(commonOptions);
                    options.victms = victms;
                    res.render('firefighter/searchandrescue/index', options);
                });
            });
        });
    });
}