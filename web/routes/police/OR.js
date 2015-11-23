var util = require('../utils');

module.exports = function (app) {
    //TODO remove hard-coded data
    var commonOptions =
    {
        'title': 'SIGAC Web - Integrated Management System for Crisis and Incidents',
        'description': 'Sistema para Gerenciamento de Crises e sinais de pacientes',
        'author': 'SI-GAC Team',
        'navbarbrand': 'SIGAC Web - Police - OR',
        'toprightlinks':
        [
            {
                'text': 'Dashboard',
                'href': '/dashboard',
                'faicon': 'fa-users',
            },
        ]
    };

    app.get('/dashboard/police/OR', /*util.autenticarSessao,*/ function(req, res) {
        var options = Object.create(commonOptions);

        options.contentTemplate = 'OR_view';
        return res.render('police/OR/index', options);
    });
}