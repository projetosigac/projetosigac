var map;
var markers = [];
var directionsService = new google.maps.DirectionsService;
var directionsDisplay = new google.maps.DirectionsRenderer;

mapa = function(){
    var _start = function(){

    google.maps.event.addDomListener(window, 'load', _initialize());
    /*
        google.maps.event.addListener(marker, 'drag', function () {
        geocoder.geocode({ 'latLng': marker.getPosition() }, function (results, status) {
            if (status == google.maps.GeocoderStatus.OK) {
                if (results[0]) {
                    //$('#txtEndereco').val(results[0].formatted_address);
                    //$('#txtLatitude').val(marker.getPosition().lat());
                    //$('#txtLongitude').val(marker.getPosition().lng());
                }
            }
        });
    });
    */
    }

    var _initialize = function (){

        var latlng = new google.maps.LatLng(-23.19586486253487, -45.89185186132812);
        var options = {
            zoom: 10,
            center: latlng,
            mapTypeId: google.maps.MapTypeId.ROADMAP
        };
        map = new google.maps.Map(document.getElementById("map"), options);

        google.maps.event.addDomListener(window, 'resize', _initialize);
        //google.maps.event.addDomListener(window, 'load', _initialize);

    }

    var _calcularRota = function (enderecoDestino, enderecoPartida) {
        directionsDisplay.setMap(map);
        directionsService.route({
            origin: enderecoDestino,
            destination: enderecoPartida,
            travelMode: google.maps.TravelMode.DRIVING
        }, function(response, status) {
            if (status === google.maps.DirectionsStatus.OK) {
                directionsDisplay.setDirections(response);
            } else {
                window.alert('Directions request failed due to ' + status);
            }
        });
    }

    var _carregarNoMapa = function (endereco) {

        _deleteMarkers();
        geocoder = new google.maps.Geocoder();

        geocoder.geocode({ 'address': endereco + ', Brasil', 'region': 'BR' }, function (results, status) {
            if (status == google.maps.GeocoderStatus.OK) {
                if (results[0]) {
                    var latitude = results[0].geometry.location.lat();
                    var longitude = results[0].geometry.location.lng();
                    var enderecoFormatado = results[0].formatted_address;

                    $("#enderecoAtendimentoGoogle").val(enderecoFormatado);
                    $("#btnChamarAmbulancia").prop("disabled", false);

                    $("#mapaLegenda").html("Posição geográfica da emergência, latitude: ".concat(latitude," e longitude: ",longitude,"."));
                    $("#latitudeEmergencia").val(latitude);
                    $("#longitudeEmergencia").val(longitude);

                    var location = new google.maps.LatLng(latitude, longitude);
                    var marker = _addMarker(location);

                    _createInfoWindow('Local da emergência', enderecoFormatado, marker);
/*
                    marker = new google.maps.Marker({
                        map: map,
                        draggable: false,
                    });
                    marker.setPosition(location);
                    marker.setVisible(true);*/

                    map.setCenter(location);
                    map.setZoom(16);

                    google.maps.event.addDomListener(window, 'resize', _initialize);
                    google.maps.event.addDomListener(window, 'load', _initialize)


                }
            }
        });
    }

    var _createInfoWindow = function (title, address, marker){
      var infowindow = new google.maps.InfoWindow({
          content: "<b>"+title+"</b><br/>".concat(address),
          maxWidth: 250
      });

      marker.addListener('click', function() {
          infowindow.open(map, marker);
      });
    }
    // Adds a marker to the map and push to the array.
    var _addMarker = function (location, callback) {
      var marker = new google.maps.Marker({
        position: location,
        draggable: false,
        visible: true,
        map: map
      });
      markers.push(marker);
      return marker;
    }

    // Sets the map on all markers in the array.
    var _setMapOnAll = function (map) {
      for (var i = 0; i < markers.length; i++) {
        markers[i].setMap(map);
      }
    }

    // Removes the markers from the map, but keeps them in the array.
    var _clearMarkers = function () {
      _setMapOnAll(null);
    }

    // Deletes all markers in the array by removing references to them.
    var _deleteMarkers = function () {
      _clearMarkers();
      markers = [];
    }
    return {
        start: _start,
        initialize: _initialize,
        carregarNoMapa: _carregarNoMapa,
        calcularRota:_calcularRota,
        deleteMarkers: _deleteMarkers
    }

}();
