var map;
var markers = [];
var directionsService = new google.maps.DirectionsService;
var directionsDisplay = new google.maps.DirectionsRenderer;
var geocoder = new google.maps.Geocoder();

mapa = function(){
    var _start = function(){
    google.maps.event.addDomListener(window, 'load', _initialize());
    }

    var _initialize = function (callback){

        var latlng = new google.maps.LatLng(-23.19586486253487, -45.89185186132812);
        var options = {
            zoom: 10,
            center: latlng,
            mapTypeId: google.maps.MapTypeId.ROADMAP
        };
        map = new google.maps.Map(document.getElementById("map"), options);

        google.maps.event.addDomListener(window, 'resize', _initialize);
        //google.maps.event.addDomListener(window, 'load', _initialize);
        if(callback)
          callback();
    }

    var _calcularRota = function (origin, destination, customIcon, callback) {

        var rendererOptions = {map : map};

        if(customIcon)
          rendererOptions["suppressMarkers"] = true;

        directionsDisplay = new google.maps.DirectionsRenderer(rendererOptions);

        //directionsDisplay.setMap(rendererOptions);
        directionsService.route({
            origin: origin,
            destination: destination,
            travelMode: google.maps.TravelMode.DRIVING
        }, function(response, status) {
            if (status === google.maps.DirectionsStatus.OK) {
                directionsDisplay.setDirections(response);
                if(customIcon){
                  for(var i in customIcon){
                    var address = customIcon[i].address;
                    if(typeof address != 'string'){
                      address = response.routes[0].legs[0].end_address;
                    }
                    _setMarkerDirections(customIcon[i], address);
                  }
                }
                if(callback)
                  callback();

            } else {
                window.alert('Directions request failed due to ' + status);
            }
        });

    }
    var _setMarkerDirections = function (customIcon, address){

      geocoder = new google.maps.Geocoder();
      geocoder.geocode({ 'address': address, 'region': 'BR' }, function (results, status) {
        if (status == google.maps.GeocoderStatus.OK) {
          if (results[0]) {
            var lat = results[0].geometry.location.lat();
            var long = results[0].geometry.location.lng();

            var marker = _addMarker(new google.maps.LatLng(lat, long), customIcon.image);

            _createInfoWindow(customIcon.title, results[0].formatted_address, marker);

          }
        }
      });
    }
    var _carregarNoMapa = function (endereco, callback) {

        _deleteMarkers();

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
                    var marker = _addMarker(location, '../images/marker-crisis.png');

                    _createInfoWindow('Local crises', enderecoFormatado, marker);

                    map.setCenter(location);
                    map.setZoom(16);

                    google.maps.event.addDomListener(window, 'resize', _initialize);
                    google.maps.event.addDomListener(window, 'load', _initialize)

                    if(callback)
                      callback();
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
    var _addMarker = function (location, iconCustom, callback) {

      var properties = {
        position: location,
        draggable: false,
        visible: true,
        map: map
      };
      if(iconCustom)
        properties["icon"] = iconCustom;

      var marker = new google.maps.Marker(properties);
      markers.push(marker);
      if(callback)
        callback(marker);

      return marker;
    }

    var _geocodeLatLng = function (lat, long, callback) {
      var latlng = {lat: parseFloat(lat), lng: parseFloat(long)};
      geocoder.geocode({'location': latlng}, function(results, status) {
        if (status === google.maps.GeocoderStatus.OK) {
          if (results[1]) {
            callback(results[1]);
          } else {
            window.alert('No results found');
          }
        }
      });
    };

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
    var _clearMap = function(callback){
      $("#map").html("");
      mapa.initialize(callback);
    }
    return {
        start: _start,
        initialize: _initialize,
        carregarNoMapa: _carregarNoMapa,
        calcularRota:_calcularRota,
        deleteMarkers: _deleteMarkers,
        clearMap: _clearMap,
        geocodeLatLng: _geocodeLatLng
    }

}();
