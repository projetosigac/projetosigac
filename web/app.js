/**
 * Module dependencies.
 */

var express = require('express');
var session	= require('express-session');
var routes = require('./routes');
var http = require('http');
var path = require('path');

var app = express();

var connection  = require('express-myconnection');
var mysql = require('mysql');

//criamos instancia do body-parser, usado nos handlers
var bodyParser = require('body-parser');
var jsonParser = bodyParser.json();

// all environments
app.set('port', process.env.PORT || 4300);
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');
//app.use(express.favicon());
app.use(express.logger('dev'));
app.use(express.json());
app.use(express.urlencoded());
app.use(express.methodOverride());

app.use(session({secret: 'ssshhhhh',saveUninitialized: true,resave: true}));
var sess;

app.use(express.static(path.join(__dirname, 'public')));

/**
 * Pool usado nos componentes de acesso a dados.
 */
var connConfig = {
    connectionLimit    : 10,
    multipleStatements : true,
    host               : 'sigac.cc8r8un1zbjy.sa-east-1.rds.amazonaws.com',
    user               : 'admin',
    password           : 'adminsigac',
    database           : 'sigac'
};

var pool  = mysql.createPool(connConfig);

app.use(
/*conexao remota*/
    connection(mysql,connConfig,'pool') //or single
);

// inicia os DAOs.
require("./db/ocorrenciaDAO")(pool);
require("./db/localizacaoAmbulanciaDAO")(pool);
require("./db/hospitalDAO")(pool);
require('./db/stationDAO')(pool);
require("./db/panelDAO")(pool);

//load routes
// The routes MUST be loaded AFTER ALL the DAO components.
var dashboard = require('./routes/dashboard');
var utiCrises = require('./routes/utiCrises');
var utiVitimas = require('./routes/utiVitimas');
var utiRegisteredVictims = require('./routes/utiRegisteredVictims');
var utiVitima = require('./routes/utiVitima');
var utiBedsAvailable = require('./routes/utiBedsAvailable');
var customers = require('./routes/customers');
var api = require('./routes/api');
var apiBombeiro = require('./routes/bombeiro')
var util = require('./routes/utils');
var atendimento = require('./routes/atendimento');
var hospital = require('./routes/hospital');
var ambEquipamento = require('./routes/ambEquipamento');
var defc = require('./routes/defc');
var reports = require('./routes/reports');

app.get('/', routes.index);
app.get('/dashboard', util.autenticarSessao, dashboard.carregarPagina);
app.get('/uti/crises', util.autenticarSessao, utiCrises.carregarPagina);
app.get('/uti/crises:cId', util.autenticarSessao, utiCrises.carregarPagina);
app.get('/uti/vitimas', util.autenticarSessao, utiVitimas.carregarPagina);
app.get('/uti/registeredVictims', util.autenticarSessao, utiRegisteredVictims.carregarPagina);
app.get('/uti/registeredVictims:cId', util.autenticarSessao, utiRegisteredVictims.carregarPagina);
app.get('/uti/vitima:pId', util.autenticarSessao, utiVitima.carregarPagina);
app.get('/uti/bedsAvailable', util.autenticarSessao, utiBedsAvailable.carregarPagina);
app.get('/ambulancia/ambulancias', util.autenticarSessao, routes.ambulancias);
app.get('/ambulancia/atendimento', util.autenticarSessao, atendimento.carregarPagina);
app.get('/ambulancia/chamados', util.autenticarSessao, routes.chamados);
app.get('/ambulancia/ambEquipamento', util.autenticarSessao, ambEquipamento.carregarPagina);
app.get('/defc', util.autenticarSessao, defc.carregarPagina);
app.get('/defc/panel', util.autenticarSessao, defc.carregarPainel);
app.get('/defc/getParams', util.autenticarSessao, defc.getParameters);
app.get('/defc/getOccPositions', util.autenticarSessao, defc.getOccurrencesPositions);
app.get('/defc/getAmbPositions', util.autenticarSessao, defc.getAmbulancesPositions);
app.get('/defc/getSensPositions', util.autenticarSessao, defc.getSensorsPositions);
app.get('/defc/getStaPositions', util.autenticarSessao, defc.getStationsPositions);
app.get('/defc/getClosOccPositions', util.autenticarSessao, defc.getClosedOccurrencesPositions);
app.get('/defc/getHospPositions', util.autenticarSessao, defc.getHospitalsPositions);


//var policia = require('./routes/policia');
//app.get('/policia/BO', util.autenticarSessao, policia.carregarPagina);

/*
métodos internos do sistema que necessita de sessão
*/
app.get('/atendimento/carregar-ambulancia-ativa', util.autenticarSessao, atendimento.carregarAmbulanciaAtiva);
app.post('/atendimento/salvar-ocorrencia', util.autenticarSessao, atendimento.salvarOcorrencia);
app.get('/atendimento/listar-hospital-leito-disponivel', util.autenticarSessao, hospital.listarLeitoDisponivel);
app.get('/ambulancia/listar-ocorrencias', util.autenticarSessao, atendimento.listarOcorrencia);
app.get('/ambulancia/localizacao-ambulancias', util.autenticarSessao, atendimento.localizacaoAmbulancias);

app.post('/uti/comunicarObito', util.autenticarSessao, utiRegisteredVictims.registrarObito);

/*
***Exemplo de criação de rota passando parametros
app.get('/customers', customers.list);
app.get('/customers/add', customers.add);
app.post('/customers/add', customers.save);
app.get('/customers/delete/:id', customers.delete_customer);
app.get('/customers/edit/:id', customers.edit);
app.post('/customers/edit/:id',customers.save_edit);
*/

//apis
app.get('/api/leituraSinais', api.leituraSinais);
app.post('/api/leituraSinais', api.leituraSinais);

//app.post('/api/leituraSinais', api.leituraSinais);

app.post('/api/login-sistema', api.loginSistema);
app.get('/logout', api.logout);
app.get('/api/verificarOcorrencia', api.verificarOcorrencia);
app.post('/api/confirmarAtendimento', api.confirmarAtendimento);

app.post('/api/insert-equip', util.autenticarSessao, api.insertEquip);
app.post('/api/insert-equip-amb', util.autenticarSessao, api.insertEquipAmb);
app.post('/api/get-equip-amb', util.autenticarSessao, api.getEquipAmb);
app.post('/api/show-equip', util.autenticarSessao, api.showEquip);
app.post('/api/show-amb', util.autenticarSessao, api.showAmb);

app.post('/api/delete-equip', util.autenticarSessao, api.deleteEquip);
app.post('/api/delete-equip-amb', util.autenticarSessao, api.deleteEquipAmb);

app.post('/api/show-crisis', util.autenticarSessao, api.showCrisis);
app.post('/api/get-crisis', util.autenticarSessao, api.getCrisis);
app.post('/api/show-amb-list', util.autenticarSessao, api.showAmbList);

app.use(app.router);

//apis bombeiros

app.post('/tag',apiBombeiro.iniVictim)
app.get('/api/bombeiro/getVictimList',apiBombeiro.getVictimList)
app.get('/api/bombeiro/getBraceletList',apiBombeiro.getBraceletList)
//app.post('/api/bombeiro/',apiBombeiro.classifyVictim)
app.get('/api/bombeiro/victimsOfColor/:color',apiBombeiro.getVictimsOfColor) //typeof(getNames) = boolean
app.get('/api/bombeiro/countVictims/:color',apiBombeiro.colorCounter)
//app.get('/api/bombeiro/:token',apiBombeiro.deleteBracelet)



/**
 * Requires Firefigther: Rescue and Aftermath endpoints definition file.
 * @author Paulo Henrique Aguiar(https://github.com/PauloAguiar)
 */
require('./routes/firefighter/rescueAndAftermathWeb')(app);
require('./routes/firefighter/rescueAndAftermathApi')(app);

/**
 * Requires Firefigther: Search and Rescue endpoints definition file.
 * @author
 */
require('./routes/firefighter/searchAndRescue')(app);



/**
 * Requires Police OR
 * @author
 */
require('./routes/police/OR')(app);

// apis Police
app.post('/api/insert-OR', util.autenticarSessao, api.insertOR);
app.post('/api/show-ORs', util.autenticarSessao, api.showORs);



// API error handler
//app.use(function(err, req, res, next) {
//    if (req.path.indexOf('api') > 0) {
//        res.status(500).json({message: err.message});
//    } else {
//        next(err);
//    }
//
//});


// development error handler
// will print stacktrace
if (app.get('env') === 'development') {

    app.use(function(err, req, res, next) {
        res.status(err.status || 500);
        res.render('error', {
            message: err.message,
            error: err
        });
    });

}


http.createServer(app).listen(app.get('port'), function(){
  console.log('Express server listening on port ' + app.get('port'));
});
