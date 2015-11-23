document.getElementById('station' + station.id).addEventListener("click", function() {
    console.log('teste');
    map.zoom = station.map_zoom;
}, false);