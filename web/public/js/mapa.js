mapa = function(){
	var _start = function(){
		google.maps.event.addDomListener(window, 'load', _initialize());
		
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
		
	}
	var _initialize = function (){
			
		var latlng = new google.maps.LatLng(-23.19586486253487, -45.89185186132812);
		var options = {
			zoom: 10,
			center: latlng,
			mapTypeId: google.maps.MapTypeId.ROADMAP
		};
		map = new google.maps.Map(document.getElementById("map"), options);
		geocoder = new google.maps.Geocoder();
		marker = new google.maps.Marker({
			map: map,
			draggable: true,
		});
		marker.setPosition(latlng);
				
	}
	var _carregarNoMapa = function (endereco) {
		geocoder.geocode({ 'address': endereco + ', Brasil', 'region': 'BR' }, function (results, status) {
			if (status == google.maps.GeocoderStatus.OK) {
				if (results[0]) {
					var latitude = results[0].geometry.location.lat();
					var longitude = results[0].geometry.location.lng();
		
					//$('#txtEndereco').val(results[0].formatted_address);
					//$('#txtLatitude').val(latitude);
                   	//$('#txtLongitude').val(longitude);
		
					var location = new google.maps.LatLng(latitude, longitude);
					marker.setPosition(location);
					map.setCenter(location);
					map.setZoom(16);
				}
			}
		})
	}
	var _pesquisarEndereco = function(){
		_carregarNoMapa($("#localEmergencia").val());
		return false;
	}
	return {
		start: _start,
		initialize: _initialize,
		carregarNoMapa: _carregarNoMapa,
		pesquisarEndereco: _pesquisarEndereco
	}
}();