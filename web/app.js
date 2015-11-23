/**
 * Module dependencies.
 */

var express = require('express');
var session	= require('express-session');
var routes = require('./routes');
var http = require('http');
var path = require('path');

//temporary heatmap route - rshigemura
var reports = require('./routes/reports');

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
    connectionLimit : 10,
    host            : 'sigac.cc8r8un1zbjy.sa-east-1.rds.amazonaws.com',
    user            : 'admin',
    password        : 'adminsigac',
    database:'sigac'
};

var pool  = mysql.createPool(connConfig);

app.use(
/*conexao remota*/
    connection(mysql,connConfig,'pool') //or single
);

// inicia os DAOs.
require("./db/ocorrenciaDAO")(pool);
require("./db/localizacaoAmbulanciaDAO")(pool);
require("./db/panelDAO")(pool);

//load routes
// The routes MUST be loaded AFTER ALL the DAO components.
var dashboard = require('./routes/dashboard');
var utiCrises = require('./routes/utiCrises');
var utiVitimas = require('./routes/utiVitimas');
var utiVitima = require('./routes/utiVitima');
var customers = require('./routes/customers');
var api = require('./routes/api');
var apiBombeiro = require('./routes/bombeiro')
var util = require('./routes/utils');
var atendimento = require('./routes/atendimento');
var ambEquipamento = require('./routes/ambEquipamento')
var defCivil = require('./routes/defCivil')


app.get('/', routes.index);
app.get('/dashboard', util.autenticarSessao, dashboard.carregarPagina);
app.get('/uti/crises', util.autenticarSessao, utiCrises.carregarPagina);
app.get('/uti/vitimas', util.autenticarSessao, utiVitimas.carregarPagina);
app.get('/uti/vitima/:pId', util.autenticarSessao, utiVitima.carregarPagina);
app.get('/ambulancia/ambulancias', util.autenticarSessao, routes.ambulancias);
app.get('/ambulancia/atendimento', util.autenticarSessao, atendimento.carregarPagina);
app.get('/ambulancia/chamados', util.autenticarSessao, routes.chamados);
app.get('/ambulancia/ambEquipamento', util.autenticarSessao, ambEquipamento.carregarPagina);
app.get('/defcivil', util.autenticarSessao, defCivil.carregarPagina);
app.get('/defcivil/getParams', util.autenticarSessao, defCivil.getParameters);
app.get('/defcivil/getOccPositions', util.autenticarSessao, defCivil.getOccurrencesPositions);

//temporary route for heatmap - rshigemura
app.get('/defcivil/relatorio', util.autenticarSessao, routes.relatorio);
app.get('/reports/get_list', util.autenticarSessao , reports.get_list);

/*
métodos internos do sistema que necessita de sessão
*/
app.get('/atendimento/carregar-base-samu', util.autenticarSessao, atendimento.carregarBaseSamu);
app.post('/atendimento/salvar-ocorrencia', util.autenticarSessao, atendimento.salvarOcorrencia);
app.get('/ambulancia/listar-ocorrencias', util.autenticarSessao, atendimento.listarOcorrencia);
app.get('/ambulancia/localizacao-ambulancias', util.autenticarSessao, atendimento.localizacaoAmbulancias);

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

app.use(app.router);

//apis bombeiros

app.post('/tag',apiBombeiro.iniVictim)
app.get('/api/bombeiro',apiBombeiro.list)
app.get('/api/bombeiro/getBraceletList',apiBombeiro.getList)
app.post('/api/bombeiro/',apiBombeiro.classifyVictim)
app.get('/api/bombeiro/victimsOfColor/:color',apiBombeiro.getVictimsOfColor) //typeof(getNames) = boolean
app.get('/api/bombeiro/countVictims/:color',apiBombeiro.colorCounter)
//app.get('/api/bombeiro/:token',apiBombeiro.deleteBracelet)


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
