var express    = require('express');
var morgan = require('morgan')
var bodyParser = require('body-parser');
var Storage = require('node-storage');


var entryList = new Storage('entries');
var database = new Storage('database');
var app        = express();
var port = process.env.PORT || 8080;

entryList.put("last_port", port);

var rfidEntriesTag = 'rfid_entries';
var rfidEntries = entryList.get(rfidEntriesTag);

if (rfidEntries === undefined)
{
    rfidEntries = [];
    entryList.put(rfidEntriesTag, rfidEntries);
}

var lookupRfid = {};
for (var i = 0, len = rfidEntries.length; i < len; i++) {
    lookupRfid[rfidEntries[i]['rfid_code']] = rfidEntries[i];
}

var databaseEntriesTag = 'entries';
var databaseEntries = database.get(databaseEntriesTag);

if (databaseEntries === undefined)
{
    databaseEntries = [];
    database.put(databaseEntriesTag, databaseEntries);
}

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(morgan('dev'))

var apiRouter = express.Router();

apiRouter.get('/check', function(req, res) {
    return res.json({'time_stamp': Date.now(), 'status': 'alive'});
});

////////////////////////
// RFID Create
////////////////////////
apiRouter.post('/rfid/create', function(req, res) {
    var rfidCode = req.body.code;

    if (lookupRfid[rfidCode])
        return res.json({'time_stamp': Date.now(), 'operation': 'fail', 'message': 'already_exists'});

    var entry = {'time_stamp': Date.now(), 'rfid_code': rfidCode};
    rfidEntries.push(entry);
    lookupRfid[rfidCode] = entry;
    entryList.put(rfidEntriesTag, rfidEntries);
    return res.json({'time_stamp': Date.now(), 'operation': 'ok'});
});

////////////////////////
// RFID Read
////////////////////////
apiRouter.get('/rfid/read', function(req, res) {
    if (rfidEntries.length > 0)
        return res.json({'operation': 'ok', 'rfid_entry': rfidEntries[0], 'index': 0, 'remaining': rfidEntries.length});

    return res.json({'time_stamp': Date.now(), 'operation': 'ok', 'remaining': rfidEntries.length});
});

////////////////////////
// RFID Read by ID
////////////////////////
apiRouter.get('/rfid/read/:id', function(req, res) {
    var id = req.params.id;
    if (isNaN(id))
        return res.json({'time_stamp': Date.now(), 'operation': 'fail', 'message': 'invalid_id'});

    id = parseInt(id);
    if (rfidEntries.length <= id)
        return res.json({'time_stamp': Date.now(), 'operation': 'fail', 'message': 'out_of_range'});

    return res.json({'time_stamp': Date.now(), 'operation': 'ok', 'rfid_entry': rfidEntries[id], 'index': id, 'remaining': rfidEntries.length});
});

////////////////////////
// Entry Update
////////////////////////
apiRouter.post('/entry/update', function(req, res) {
    var rfidCode = req.body.code;

    if(!rfidCode)
        return res.json({'time_stamp': Date.now(), 'operation': 'fail', 'message': 'invalid_rfid_code'});

    var sex = req.body.sex;
    var type = req.body.type;
    var state = req.body.state;

    if (lookupRfid[rfidCode]) {
        var index = rfidEntries.indexOf(lookupRfid[rfidCode]);
        rfidEntries.splice(index, 1);
        delete lookupRfid[rfidCode];
    }
    var index = databaseEntries.indexOf(rfidCode);
    if(index === -1)
        databaseEntries.push(rfidCode);

    database.put(rfidCode, {'rfid_code': rfidCode, 'sex': sex, 'type': type, 'state': state, 'last_update': Date.now()});

    return res.json({'time_stamp': Date.now(), 'operation': 'ok'});
});

////////////////////////
// Entry Read All
////////////////////////
apiRouter.get('/entry/read', function(req, res) {
    var allEntries = databaseEntries.map(function(code) { return database.get(code); });

    return res.json({'time_stamp': Date.now(), 'operation': 'ok', 'entries': allEntries});
});

////////////////////////
// Remove Entry
////////////////////////
apiRouter.post('/entry/delete/', function(req, res) {
    var rfidCode = req.body.code;

    if(!rfidCode)
        return res.json({'time_stamp': Date.now(), 'operation': 'fail', 'message': 'invalid_rfid_code'});

    var index = databaseEntries.indexOf(rfidCode);
    if(index === -1)
        return res.json({'time_stamp': Date.now(), 'operation': 'fail', 'message': 'entry_not_found'});

    databaseEntries.splice(index, 1);
    database.remove(rfidCode);

    return res.json({'time_stamp': Date.now(), 'operation': 'ok'});
});

app.use('/api', apiRouter);

app.listen(port);
console.log('Embedded API listening on port ' + port + '.');