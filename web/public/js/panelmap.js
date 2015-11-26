
    var map, heatmap, geocoder;
    var heatmapCircle;
    var pointMvc = new google.maps.MVCArray([]);

    var pointMvcAmb = new google.maps.MVCArray([]);
    var pointMvcSens = new google.maps.MVCArray([]);
    var pointMvcStat = new google.maps.MVCArray([]);
    var pointMvcOpen = new google.maps.MVCArray([]);
    var pointMvcHosp = new google.maps.MVCArray([]);

    var markers = [];

     

    function initialize() {
     
      startMapPanel();
      initMap();
      bindFormToMap(); 

   }


   // Sets the map on all markers in the array.
   function setMapOnAll(map) {
     for (var i = 0; i < markers.length; i++) {
       markers[i].setMap(map);
     }
   }

   // Removes the markers from the map, but keeps them in the array.
   function clearMarkers() {
     setMapOnAll(null);
   }

   // Shows any markers currently in the array.
   function showMarkers() {
     setMapOnAll(map);
   }

   // Deletes all markers in the array by removing references to them.
   function deleteMarkers() {
     clearMarkers();
     markers = [];
   }


    function startGeolocation(){

        var infoWindow = new google.maps.InfoWindow({map: map});

        // Try HTML5 geolocation.
        if (navigator.geolocation) {
          navigator.geolocation.getCurrentPosition(function(position) {
            var pos = {
              lat: position.coords.latitude,
              lng: position.coords.longitude
            };

            infoWindow.setPosition(pos);
            infoWindow.setContent('Location found.');
            map.setCenter(pos);
          }, function() {
            handleLocationError(true, infoWindow, map.getCenter());
          });
        } else {
          // Browser doesn't support Geolocation
          handleLocationError(false, infoWindow, map.getCenter());
        }
      }

 
    function handleLocationError(browserHasGeolocation, infoWindow, pos) {
      infoWindow.setPosition(pos);
      infoWindow.setContent(browserHasGeolocation ?
                            'Error: The Geolocation service failed.' :
                            'Error: Your browser doesn\'t support geolocation.');
    }



    function startMapPanel(){
        $("a[href='#mapa']").on('shown.bs.tab', function(){
          google.maps.event.trigger(map, 'resize');
        });
    }

       function updatePoints(finished) {
          $.ajax({ 
            url: "/defc/getClosOccPositions", 
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

              var points = JSON.parse(resp);

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


 function updatePointsOpen(finished) {
      $.ajax({ 
        url: "/defc/getOccPositions", 
        type: "get",
        data: {
          "r": heatmapCircle.getRadius(),
          "center": {
            "lat": heatmapCircle.getCenter().H,
            "lng": heatmapCircle.getCenter().L
          }
        },
        success: function(resp) {

          var image = '../images/marker-soft-crisis.png';
          var txtTitle = '';

          while(pointMvcOpen.getLength() > 0) pointMvcOpen.pop();

          var points = JSON.parse(resp);

          for (var i=0; i<points.length; i++) {
            var p = points[i];

            if (p.obito == 'S') {
              image = '../images/marker-death.png';
              txtTitle =  ''.concat('Ocorrência: ', p.n_vitimas ,' Vítima(s) - CONSTA ÓBITO');
            }
            else{
              if (p.n_vitimas > 6) {
                image = '../images/marker-hard-crisis.png';
                txtTitle = ''.concat('Ocorrência: ', p.n_vitimas ,' Vítima(s) - SUPER CRÍTICA');
              }else{
                var image = '../images/marker-soft-crisis.png';
                txtTitle = ''.concat('Ocorrência: ', p.n_vitimas ,' Vítima(s) - CRÍTICA');
              }
            }

            var marker = new google.maps.Marker({
                position: new google.maps.LatLng(p.lat, p.lng),
                map: map,
                icon: image,
                animation: google.maps.Animation.DROP,
                //shape: shape,
                title: txtTitle
              }); 

            markers.push(marker);

          }
          if (finished) finished(true);
        },
        error: function() {
          if (finished) finished(false);
        }
      });
    }

function updatePointsHospitals(finished) {
      $.ajax({ 
        url: "/defc/getHospPositions", 
        type: "get",
        data: {
          "r": heatmapCircle.getRadius(),
          "center": {
            "lat": heatmapCircle.getCenter().H,
            "lng": heatmapCircle.getCenter().L
          }
        },
        success: function(resp) {

          var image = '../images/marker-hospital.png';
          var txtTitle = '';

          while(pointMvcHosp.getLength() > 0) pointMvcHosp.pop();

          var points = JSON.parse(resp);

          for (var i=0; i<points.length; i++) {
            var p = points[i];

            txOcupacao = p.leitos_ocupados / p.leitos_total;

            if (txOcupacao <= .7) {
              image = '../images/marker-hospital.png';
              txtTitle =  ''.concat('Hospital: ', p.hospital ,' / Leitos: ', p.leitos_total, ' / Ocup: ', p.leitos_ocupados, ' / ', Math.round(txOcupacao * 100), '% Ocup. - OK');
            }
            else{
              if (p.leitos_ocupados / p.leitos_total > .7) {
                image = '../images/marker-hospital-full.png';
                txtTitle = ''.concat('Hospital: ', p.hospital ,' / Leitos: ', p.leitos_total, ' / Ocup: ', p.leitos_ocupados, ' / ', Math.round(txOcupacao * 100), '% Ocup. - CRÍTICO');
              }
            }

            var marker = new google.maps.Marker({
                position: new google.maps.LatLng(p.lat, p.lng),
                map: map,
                icon: image,
                animation: google.maps.Animation.DROP,
                //shape: shape,
                title: txtTitle
              }); 

            markers.push(marker);

          }
          if (finished) finished(true);
        },
        error: function() {
          if (finished) finished(false);
        }
      });
    }


    function updatePointsAmbulances(finished) {
      $.ajax({ 
        url: "/defc/getAmbPositions", 
        type: "get",
        data: {
          "r": heatmapCircle.getRadius(),
          "center": {
            "lat": heatmapCircle.getCenter().H,
            "lng": heatmapCircle.getCenter().L
          }
        },
        success: function(resp) {

          var image = '../images/marker-ambulance.png';
          var txtTitle = '';

          while(pointMvcAmb.getLength() > 0) pointMvcAmb.pop();

          var points = JSON.parse(resp);

          for (var i=0; i<points.length; i++) {
            var p = points[i];            
            txtTitle =  ''.concat('Ambulância: ', p.ID ,' - OK');
            var marker = new google.maps.Marker({
                position: new google.maps.LatLng(p.lat, p.lng),
                map: map,
                icon: image,
                animation: google.maps.Animation.DROP,
                //shape: shape,
                title: txtTitle
              }); 

            markers.push(marker);

          }
          if (finished) finished(true);
        },
        error: function() {
          if (finished) finished(false);
        }
      });
    }

      function updatePointsStations(finished) {
        $.ajax({ 
          url: "/defc/getStaPositions", 
          type: "get",
          data: {
            "r": heatmapCircle.getRadius(),
            "center": {
              "lat": heatmapCircle.getCenter().H,
              "lng": heatmapCircle.getCenter().L
            }
          },
          success: function(resp) {
             var image = '../images/marker-station.png';
             var txtTitle = '';

            while(pointMvcStat.getLength() > 0) pointMvcStat.pop();

            var points = JSON.parse(resp);

            for (var i=0; i<points.length; i++) {
              var p = points[i];

              txtTitle =  ''.concat('Station: ', p.ID ,'- OK');

              var marker = new google.maps.Marker({
                  position: new google.maps.LatLng(p.lat, p.lng),
                  map: map,
                  icon: image,
                  animation: google.maps.Animation.DROP,
                  //shape: shape,
                  title: txtTitle
                });                    

              markers.push(marker);
       
            }
            if (finished) finished(true);
          },
          error: function() {
            if (finished) finished(false);
          }
        });
    }

   
      function updatePointsSensors(finished) {
        $.ajax({ 
          url: "/defc/getSensPositions", 
          type: "get",
          data: {
            "r": heatmapCircle.getRadius(),
            "center": {
              "lat": heatmapCircle.getCenter().H,
              "lng": heatmapCircle.getCenter().L
            }
          },
          success: function(resp) {
           var image = '../images/marker-sensor.png';
           var txtTitle = '';

             while(pointMvcSens.getLength() > 0) pointMvcSens.pop();

             var points = JSON.parse(resp);

             for (var i=0; i<points.length; i++) {
               var p = points[i];

              txtTitle =  ''.concat('Sensor: ', p.ID ,'- OK');

               var marker = new google.maps.Marker({
                   position: new google.maps.LatLng(p.lat, p.lng),
                   map: map,
                   icon: image,
                   animation: google.maps.Animation.DROP,
                   //shape: shape,
                   title: txtTitle
                 });  

                 markers.push(marker);
         
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
      var center = new google.maps.LatLng(-23.1848566, -45.8888397);
      map = new google.maps.Map(document.getElementById('map'), {
        zoom: 13,
        center: center,
        mapTypeId: google.maps.MapTypeId.HYBRID,
        streetViewControl: true
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
        fillColor: '#ff8080',
        strokeColor: '#1E90FF',
        fillOpacity: 0.2,
        strokeOpacity: 0.4,
        strokeWeight: 2,
        radius: 3000,
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
          //updatePoints(updateViewsForHeatmap);
          clearMarkers();   

          switch ($('#occurrence_type :selected').text()) {
              case "All":
                  updatePointsAmbulances(updateViewsForHeatmap);
                  updatePointsSensors(updateViewsForHeatmap);
                  updatePointsStations(updateViewsForHeatmap);
                  updatePointsOpen(updateViewsForHeatmap);
                  updatePointsHospitals(updateViewsForHeatmap);
                  break;
              case "Ambulances":
                  updatePointsAmbulances(updateViewsForHeatmap);
                  break;
              case "Sensors":
                  updatePointsSensors(updateViewsForHeatmap);
                  break;
              case "Stations":
                  updatePointsStations(updateViewsForHeatmap);
                  break;
              case "Occurrences":
                  updatePointsOpen(updateViewsForHeatmap);
                  break;
              case "Hospitals":
                  updatePointsHospitals(updateViewsForHeatmap);
                  break;
              case "None":  
                  break;            
          }
          

        } else {
          while (pointMvc.getLength() > 0) pointMvc.pop();
          updateViewsForHeatmap(false);
        }
        return false;
      });
    }

    function updateViewsForHeatmap(generated) {
      $('#generate_heatmap').text(generated ? 'New Search' : 'Generate Map');
      heatmapCircle.setVisible(!generated);
     
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

    function toggleHeatmap() {
     
      updatePoints(false);
      heatmap.setMap(heatmap.getMap() ? null : map);
    }

    function changeGradient() {
      var gradient = [
        'rgba(0, 255, 255, 0)',
        'rgba(0, 255, 255, 1)',
        'rgba(0, 191, 255, 1)',
        'rgba(0, 127, 255, 1)',
        'rgba(0, 63, 255, 1)',
        'rgba(0, 0, 255, 1)',
        'rgba(0, 0, 223, 1)',
        'rgba(0, 0, 191, 1)',
        'rgba(0, 0, 159, 1)',
        'rgba(0, 0, 127, 1)',
        'rgba(63, 0, 91, 1)',
        'rgba(127, 0, 63, 1)',
        'rgba(191, 0, 31, 1)',
        'rgba(255, 0, 0, 1)'
      ]
      heatmap.set('gradient', heatmap.get('gradient') ? null : gradient);
    }

    function changeRadius() {
      heatmap.set('radius', heatmap.get('radius') ? null : 20);
    }

    function changeOpacity() {
      heatmap.set('opacity', heatmap.get('opacity') ? null : 0.2);
    }

    function fullScreenMap() {    

      mapForm = document.getElementById('mapForm');
      mapContainer = document.getElementById('mapContainer');

       if (mapForm.style.display != 'none') {
            mapForm.style.display = 'None';
            mapContainer.style.width = '100%';
            google.maps.event.trigger(map, 'resize');

            $('#btnFullScreen').text('Full Screen Map' ? 'Exit Full Screen' : 'Exit Full Screen');

        }
      else{
          mapForm.style.display = 'inline-block';
          mapContainer.style.width = '75%';
          google.maps.event.trigger(map, 'resize');

          $('#btnFullScreen').text('Exit Full Screen' ? 'Full Screen Map' : 'Full Screen Map');

        }



      
    }