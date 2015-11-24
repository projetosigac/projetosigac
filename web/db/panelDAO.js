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
      var queryString = this.queryGenerateBatch("id,latitude as lat,longitude as lng","ocorrencia","id","Where status = 'ABERTO'");
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
      var queryString = this.queryGenerateBatch("placa_ambulancia as id, latitude As lat, longitude As lng","localizacao_ambulancia","placa_ambulancia","");
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
      var queryString = this.queryGenerateBatch("stu_id as id, stu_lat as lat,stu_long as lng","SenTempUmid","stu_id","");
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
      var queryString = this.queryGenerateBatch(" station_name As id, station_lat As lat, station_lon As lng","stations","station_name","");
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