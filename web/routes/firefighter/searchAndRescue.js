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
        return res.render('firefighter/searchandrescue/index', commonOptions);
    });
}