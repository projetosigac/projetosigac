ambLista = function () {
    var _init = function () {
        mapa.start();
        _listarAmbulancias();
    }
    var _listarAmbulancias = function () {
        $.ajax({
            url: '/api/show-amb-list',
            type: 'POST',
            async: false,
            contentType: 'application/json; charset=utf-8',
            dataType: 'json',
            success: function (data){
                var objAmb = data.rows;
                var resultHtml = "";
                $('#tableOcorrencia tbody').html('');
                for (var i = 0; i < objAmb.length; i++) {

                    tr = $('<tr/>');
                    tr.append("<td>"+objAmb[i].placa+"</td>");
                    if(objAmb[i].qtd_passageiros == null){
                        tr.append("<td> -- </td>");
                    }
                    else tr.append("<td>"+objAmb[i].qtd_passageiros+"</td>");
                    if(objAmb[i].tipo == null){
                        tr.append("<td> -- </td>");
                    }
                    else tr.append("<td>"+objAmb[i].tipo+"</td>");
                    tr.append("<td>"+objAmb[i].status+"</td>");
                    $('#tableOcorrencia tbody').append(tr);

                    var marker = new google.maps.Marker({
                        map: map,
                        position: new google.maps.LatLng(objAmb[i].latitude, objAmb[i].longitude),
                        title: 'Ambulance Status: '+objAmb[i].status
                    });

                    var infowindow = new google.maps.InfoWindow({
                        maxWidth: 250
                    });
                    var content = "<b>Ambulance License Plate:</b> ".concat(objAmb[i].placa);

                    google.maps.event.addListener(marker,'click', function(marker, content, infowindow){
                        return function() {
                            infowindow.setContent(content);
                            infowindow.open(map, marker);
                        };
                    } (marker, content, infowindow));
                }
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
