ambLista = function () {

    var enderecosAmbulancias = [];

    var _init = function () {
        mapa.start();
        _carregarAmbulancias();
    }
    var _listarOcorrencia = function () {
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

                //tr.append("<td>"+_maisProxima(data[i])+"</td>");
                        
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
                /*marker.addListener('click', function(){
                        $('#accordion .panel-collapse.collapse').collapse('hide');
                        $('#collapse'+i).collapse('show');
                });*/
                }
            },
            error: function(jqXHR, textStatus, errorThrown) {
                alert(jqXHR.responseJSON);
            }
        });
    }
    /*
        A ideia da função abaixo é retornar o endereço de uma ambulância
        com base em sua latitude e longitude, caso esse endereço não seja
        armazenado no banco de dados. O endereço é necessário para o cálculo
        de ambulância mais próxima a uma dada ocorrência
    */
    var _enderecoLatLng = function (callback, ambLista) {
        var latlng = {lat: Number(ambLista.latitudeBoxValue), lng: Number(ambLista.LongitudeBoxValue)};
        var geocoder = new google.maps.Geocoder();
        geocoder.geocode({'location': latlng}, function(results, status) {
            if (status == google.maps.GeocoderStatus.OK) {
                if (results[0]) {
                    callback(results[0].formatted_address, ambLista);
                }
            }
            else if (status == google.maps.GeocoderStatus.OVER_QUERY_LIMIT) {
                setTimeout(function() {
                    _enderecoLatLng(callback, lat, lng);
                }, 200);
            }
            else {
                window.alert('Geocoder failed due to: ' + status);
            }
        });
    }
    /*
        Função que retira todos os endereços (ou latitude e longitude)
        das ambulâncias no banco de dados.
    */
    var _carregarAmbulancias = function () {

        /*$.ajax({
            type: "GET",
            url: '/ambulancia/localizacao-ambulancias',
            async: false,
            contentType: 'application/json; charset=utf-8',
            dataType: 'json',
            success: function (data){
                for (var i = 0; i < 10; i++)
                {
                    if(data.length == 1 || i == 9) {
                        _enderecoLatLng(function(address) {
                            enderecosAmbulancias.push(address);
                            _listarOcorrencia();
                        }, data[i].latitude, data[i].longitude);
                    }
                    else {
                        _enderecoLatLng(function(address) {
                            enderecosAmbulancias.push(address);
                        }, data[i].latitude, data[i].longitude);
                    }
                }
            },
            error: function(jqXHR, textStatus, errorThrown) {
               alert(jqXHR.responseJSON);
            }
        });*/

       // enderecosAmbulancias.push("Rua H8B, 232");
        enderecosAmbulancias.push("Avenida 9 de Julho, 200");
        enderecosAmbulancias.push("R. Dr. José Cândido de Souza - Jardim Novo Mundo");
        enderecosAmbulancias.push("Av. Andrômeda - São José dos Campos");
        enderecosAmbulancias.push("Av. Silva Jardim, 340");
        _listarOcorrencia();
    }

    var _maisProxima = function (ocorrencia) {
        return util.calcularLocalMaisProximo(enderecosAmbulancias, ocorrencia);
    }

    return{
        init: _init
    }
}();
