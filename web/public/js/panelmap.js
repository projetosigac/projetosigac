
    var map, heatmap, geocoder;
    var heatmapCircle;
    var pointMvc = new google.maps.MVCArray([]);

     

    function initialize() {
      initMap();
      bindFormToMap();
    }

    function updatePoints(finished) {
      $.ajax({ 
        url: "reports/get_list", 
        type: "get",
        data: {
          "r": heatmapCircle.getRadius(),
          "center": {
            "lat": heatmapCircle.getCenter().H,
            "lng": heatmapCircle.getCenter().L
          }
        },
        success: function(resp) {
          while(pointMvc.getLength() > 0) pointMvc.pop();

          var points = JSON.parse(resp).reports;

          for (var i=0; i<points.length; i++) {
            var p = points[i];
            pointMvc.push(new google.maps.LatLng(p.lat, p.lng));
          }
          if (finished) finished(true);
        },
        error: function() {
          if (finished) finished(false);
        }
      });
    }

    function roundDecimal(num, decplaces) {
        var multiplier = 1;
        while (decplaces-- > 0) multiplier *= 10;
        return Math.round(num * multiplier) / multiplier;
    }

    function initMap() {
      var center = new google.maps.LatLng(-23.200809, -45.892521);
      map = new google.maps.Map(document.getElementById('map'), {
        zoom: 15,
        center: center,
        mapTypeId: google.maps.MapTypeId.HYBRID,
        streetViewControl: false
      });
      geocoder = new google.maps.Geocoder();

      heatmap = new google.maps.visualization.HeatmapLayer({
        data: pointMvc,
        map: map,
        radius: 16
      });

      heatmapCircle = new google.maps.Circle({
        center: center,
        clickable: true,
        editable: true,
        draggable: false,
        fillColor: '#1E90FF',
        strokeColor: '#1E90FF',
        fillOpacity: 0.2,
        strokeOpacity: 0.4,
        strokeWeight: 2,
        radius: 1000,
        zIndex: 1,
        map: map,
      });
    }

    var editingCircle = false;

    function setHeatmapCircleRadius(radius) {
      editingCircle = true;
      heatmapCircle.setRadius(radius);
      editingCircle = false;
    }

    function setHeatmapCircleCenter(center) {
      editingCircle = true;
      heatmapCircle.setCenter(center);
      editingCircle = false;
    }

    function bindFormToMap() {
      // Heatmap search radius
      google.maps.event.addListener(heatmapCircle, 'radius_changed', function() {
        if (editingCircle) return;

        var radius = Math.round(heatmapCircle.getRadius() / 100) * 100;
        if (radius < 500) {
          radius = 500;
        }
        setHeatmapCircleRadius(radius);
        $('#searchRadius').val(radius / 1000.0);
        updateMapZoomLevel();
      });

      $('#searchRadius').change(function() {
        var radius = $(this).val();
        if (isNaN(radius)) {
          $(this).val(radius = 1);
        } else if (radius < 0.5) {
          $(this).val(radius = 0.5);
        }

        setHeatmapCircleRadius(1000 * radius);
        updateMapZoomLevel();
      });

      // Heatmap search center
      google.maps.event.addListener(heatmapCircle, 'center_changed', function() {
        if (editingCircle) return;

        var c = heatmapCircle.getCenter();
        map.panTo(c);

        $('#heatmapCenter').val(roundDecimal(c.lat(), 6) + " " + roundDecimal(c.lng(), 6));
        getFriendlyAddress(c, function(address) {
          $('#heatmapCenter').val(address);
        });
      });

      $('#searchCenterButton').click(function() {
        searchHeatmapLocation($('#heatmapCenter').val(), function(location) {
          setHeatmapCircleCenter(location);
          map.setCenter(location);
          updateMapZoomLevel();
        });
      });

      $('#heatmapCenter').keypress(function(e) {
        if(e.keyCode == 13) {
          e.preventDefault();
          $("#searchCenterButton").click();
        }
      });
      $('#searchRadius').keypress(function(e) {
        if(e.keyCode == 13) {
          e.preventDefault();
          $(this).change();
        }
      });

      $('#heatmap_form').submit(function() {
        var btn = $('#generate_heatmap');
        if (heatmapCircle.getVisible()) {
          // heatmap not generated yet, do it now
          btn.text('Working...');
          updatePoints(updateViewsForHeatmap);
        } else {
          while (pointMvc.getLength() > 0) pointMvc.pop();
          updateViewsForHeatmap(false);
        }
        return false;
      });
    }

    function updateViewsForHeatmap(generated) {
      $('#generate_heatmap').text(generated ? 'Redo Search' : 'Gerar Heatmap');
      heatmapCircle.setVisible(!generated);
      map.setOptions({
        zoomControl: !generated,
        mapTypeControl: !generated,
        draggable: !generated,
        scrollwheel: !generated,
        disableDoubleClickZoom: generated
      });
      $('#occurrence_type, #searchRadius, #heatmapCenter, #searchCenterButton').prop('disabled', generated);
    }

    function zoomLevelForRadius(loc, radius) {
        var meters_per_pixel = radius / $('#map').height();
        var zoom = Math.log2(156543.03392 * Math.cos(loc.lat() * Math.PI / 180) / meters_per_pixel);
        return Math.floor(zoom) - 1;
    }

    function updateMapZoomLevel() {
        var zoom = zoomLevelForRadius(heatmapCircle.getCenter(), heatmapCircle.getRadius());
        if (zoom != map.getZoom()) {
            map.setZoom(zoom);
            map.setCenter(heatmapCircle.getCenter());
        }
    }

    function searchHeatmapLocation(address, callback) {
        geocoder.geocode({
            address: address,
            region: 'BR',
            bounds: map.getBounds(),
            componentRestrictions: {country: 'BR'}
        }, function (results, status) {
            if (status == google.maps.GeocoderStatus.OK && results[0]) {
                var location = results[0].geometry.location;
                callback(location);
            }
        });
    }

    function getFriendlyAddress(location, callback) {
      geocoder.geocode({
        location: location
      }, function (results, status) {
          if (status == google.maps.GeocoderStatus.OK && results[0]) {
            var address = results[0].formatted_address;
            callback(address);
          }
      });
    }
