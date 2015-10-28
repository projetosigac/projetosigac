chamados = function () {
    var _init = function (){
        mapa.start();
        _listarOcorrencia();
    }
    var _listarOcorrencia = function (){
      $.ajax({
        type: "GET",
        url: '/ambulancia/listar-ocorrencias',
        async: false,
        contentType: 'application/json; charset=utf-8',
        dataType: 'json',
        data: {status:'ATIVO'},
        success: function (data){
            var resultHtml = "";
            for (var i = 0; i < data.length; i++) {
              resultHtml = resultHtml + "<div class='panel panel-default'><div class='panel-heading' role='tab' id='heading"+i+"'><h4 class='panel-title'>";
              resultHtml = resultHtml + "<a role='button' data-toggle='collapse' href='#collapse"+i+"' aria-expanded='true' aria-controls='collapse"+i+"'>";
              resultHtml = resultHtml + "Ocurrence ID "+ data[i].id;
              resultHtml = resultHtml + "</a></h4></div>";
              resultHtml = resultHtml + "<div id='collapse"+i+"' class='panel-collapse collapse' role='tabpanel' aria-labelledby='heading"+i+"'><div class='panel-body'>";
              resultHtml = resultHtml + "<p> <b> Victims: </b> "+data[i].n_vitimas+" </p>";
              resultHtml = resultHtml + "<p> <b> Ambulances on the way: </b> "+data[i].n_ambulancias_necessarias+" </p>";
              resultHtml = resultHtml + "<p> <b> Firefighters notified: </b> Yes </p>";
              resultHtml = resultHtml + "<p> <b> Rescue Team notified: </b> Yes </p>";
              resultHtml = resultHtml + "<p> <b> Police notified: </b> Yes </p>";
              resultHtml = resultHtml + "<p> <b> Address ocurrence: </b> "+data[i].endereco+" </p>";
              resultHtml = resultHtml + "</div></div></div>";

              var marker = new google.maps.Marker({
            			map: map,
            			position: new google.maps.LatLng(data[i].latitude, data[i].longitude),
            			title: 'Ocurrence ID '+data[i].id
            		});

                var infowindow = new google.maps.InfoWindow({
                    content: "<b>Ocurrence ID:</b> ".concat(data[i].id),
                    maxWidth: 250
                });
                marker.addListener('click', function() {
                    infowindow.open(map, marker);
                });

            	marker.addListener('click', function(){
            			$('#accordion .panel-collapse.collapse').collapse('hide');
            			$('#collapse'+i).collapse('show');
            		});

            }
            $("#accordion").html(resultHtml);
        },
        error: function(jqXHR, textStatus, errorThrown) {
    			alert(jqXHR.responseJSON);
        }
      });
    }
    return{
        init: _init
    }
}();
