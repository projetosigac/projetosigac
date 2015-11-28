var db = require("./db");

function PanelDAO(pool) {
    var self = this;
    if (pool != null) {
        this.pool = pool;
    }

    this.getMissing = function(callback) {
      var queryString = this.queryGenerate("pol_num_missing_people","PoliceReport","pol_id");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows[0] : {});
                callback(null, result);
            }
        });
    };
    this.getAmbulances = function(callback) {
      var queryString = this.queryGenerate("n_ambulancias_necessarias","ocorrencia","id");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows[0] : {});
                callback(null, result);
            }
        });
    };
    this.getLatitude = function(callback) {
      var queryString = this.queryGenerate("stu_lat","SenTempUmid","stu_id");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows[0] : {});
                callback(null, result);
            }
        });
    };
    this.getLongitude = function(callback) {
      var queryString = this.queryGenerate("stu_long","SenTempUmid","stu_id");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows[0] : {});
                callback(null, result);
            }
        });
    };
    this.getVictims = function(callback) {
      var queryString = this.queryGenerate("n_vitimas","ocorrencia","id");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows[0] : {});
                callback(null, result);
            }
        });
    };

    this.getTemperature = function(callback) {
      var queryString = this.queryGenerate("stu_temp","SenTempUmid","stu_id");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows[0] : {});
                callback(null, result);
            }
        });
    };

    this.getHumidity = function(callback) {
      var queryString = this.queryGenerate("stu_umid","SenTempUmid","stu_id");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows[0] : {});
                callback(null, result);
            }
        });
    };            

    this.getClassification = function(callback) {
      var queryString = this.queryGenerate("cri_cat","crise","cri_id");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows[0] : {});
                callback(null, result);
            }
        });
    };

    this.getOccurrencesPositions = function(callback) {
      var queryString = this.queryGenerateBatch("ocorrencia.id As ID, obito,  n_vitimas, latitude As lat, longitude As lng"," ocorrencia Left Join crise On ocorrencia.id_crise = crise.cri_id Left Join vitimas On vitimas.crise = crise.cri_id ","id","WHERE ocorrencia.status = 'ABERTO'");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows : {});
                callback(null, result);
            }
        });
    };




    this.getClosedOccurrencesPositions = function(callback) {
      var queryString = this.queryGenerateBatch("ID,latitude as lat,longitude as lng","ocorrencia","id","Where status = 'FECHADO'");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows : {});
                callback(null, result);
            }
        });
    };

    this.getAmbulancesPositions = function(callback) {
      var queryString = this.queryGenerateBatch("placa_ambulancia as ID, latitude As lat, longitude As lng","localizacao_ambulancia","placa_ambulancia","");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows : {});
                callback(null, result);
            }
        });
    };

    this.getSensorsPositions = function(callback) {
      var queryString = this.queryGenerateBatch("stu_id as ID, stu_lat as lat,stu_long as lng, stu_temp, stu_umid ","SenTempUmid","stu_id","");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows : {});
                callback(null, result);
            }
        });
    };

    this.getStationsSensorsPositions = function(callback) {
      var queryString = this.queryGenerateBatch("device_id,station_name,device_name,device_last_reading,device_latitude as lat ,device_longitude as lng","stations Inner Join station_devices On stations.station_id = station_devices.station_id","device_id","Where  station_devices.device_latitude <> '' And   station_devices.device_longitude <> ''");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows : {});
                callback(null, result);
            }
        });
    };

    this.getStationsPositions = function(callback) {
      var queryString = this.queryGenerateBatch(" station_name As ID, station_lat As lat, station_lon As lng","stations","station_name","");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows : {});
                callback(null, result);
            }
        });
    };

    this.getHospitalsPositions = function(callback) {
      var queryString = this.queryGenerateBatch(" id_hospital As ID, hospital, leitos_total,leitos_ocupados,latitude As lat, longitude As lng ","hospitais","ID","");
        var query = self.pool.query(queryString, function (err, rows) {
            if (err) {
                callback(err, {});
            } else {
                var result = (rows ? rows : {});
                callback(null, result);
            }
        });
    };




    this.queryGenerate = function(col,table,id){
      var queryString = "SELECT " + col +" FROM " + table + " ORDER BY " + id + " DESC LIMIT 1";
      return queryString;
    };

    this.queryGenerateBatch = function(cols,table,id,criteria){
      var queryString = "SELECT " + cols + " FROM " + table + " " + criteria + " ORDER by " + id;
      return queryString;
    };                      
}

var panelDAO = null;

module.exports = function (pool) {
    if (pool != null && panelDAO == null) {
        panelDAO = new PanelDAO(pool);
    }
    return panelDAO;
};