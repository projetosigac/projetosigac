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
    this.queryGenerate = function(col,table,id){
      var queryString = "SELECT " + col +" FROM " + table + " ORDER BY " + id + " DESC LIMIT 1";
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