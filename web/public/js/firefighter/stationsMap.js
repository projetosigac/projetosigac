(function() {
    var defaultZoom = 4;
    var defaultLatLng = new google.maps.LatLng(-13.8171903, -52.9525207);
    var perimeter = null;
    var sensorMarkers = [];

    $(document).ready(function() {
        var map = new google.maps.Map(document.getElementById('map'), {
            zoom: defaultZoom,
            center: defaultLatLng,
        });

        google.maps.event.addListener(map, 'click', function(event) {
            console.log(event.latLng.toString());
        });

        google.maps.event.addListener(map, 'zoom_changed', function(event) {
            var zoom = map.getZoom();
            // iterate over markers and call setVisible
            for (i = 0; i < sensorMarkers.length; i++) {
                sensorMarkers[i].setVisible(zoom >= 13);
            }
        });

        $('#stations-map-view-all-button').bind('click', function() {
            if(perimeter != null)
            {

            }
            perimeter = null;
            map.setZoom(defaultZoom);
            map.setCenter(defaultLatLng);
        });

        $.get('/api/firefighter/raa/stations', function(data) {
            data.forEach(function(station) {
                var zoom =  station.map_zoom;
                var latlng = new google.maps.LatLng(station.latitude, station.longitude);
                var id = station.id;

                var linkHtml = $('<a>',
                {
                    text:  station.name,
                    class: 'list-group-item',
                    href: '#',
                    click: function() {
                        map.setZoom(zoom);
                        map.setCenter(latlng);
                    }
                });
                $('#stations-map-list')
                    .append(linkHtml);

                $.get('/api/firefighter/raa/station/perimeter/' + id, function(data) {
                    var perimeter = new google.maps.Polygon({
                        paths: data,
                        strokeColor: '#FF0000',
                        strokeOpacity: 0.8,
                        strokeWeight: 3,
                        fillColor: '#FF0000',
                        fillOpacity: 0.35
                    });
                    perimeter.setMap(map);
                    perimeter.addListener('click', function(event) {
                        console.log(event.latLng.toString());
                    });
                });

                $.get('/api/firefighter/raa/station/devices/' + id, function(data) {
                    var image = 'http://maps.google.com/mapfiles/kml/shapes/earthquake.png';
                    data.forEach(function(device) {
                        var latLng = new google.maps.LatLng(device.lat, device.lng);

                         var marker = new google.maps.Marker({
                            position: latLng,
                            map: map,
                            title: device.name,
                            visible: false,
                            icon: image,
                        });

                         sensorMarkers.push(marker);
                    });
                });
                var image = 'http://maps.google.com/mapfiles/kml/shapes/caution.png';
                var marker = new google.maps.Marker({
                    position: latlng,
                    map: map,
                    title: station.name,
                    icon: image,
                });

                marker.addListener('click', function() {
                    map.setZoom(zoom);
                    map.setCenter(latlng);
                });

                marker.addListener('dblclick', function() { location.href = '/dashboard/firefighter/raa/station/' + id; });
            });
        });
    });
})();