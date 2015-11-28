google.load("visualization", "1", {packages:["corechart"]});
google.setOnLoadCallback(drawChart);
function drawChart() {
	var charts = {};
	function loadData(){
		$.get("/api/firefighter/raa/station/deviceswithreadings/" + content, function(response){
			var devices = response.devices;
			for (device_id in response.readings) {
				var data = google.visualization.arrayToDataTable([
				  ['Timestamp', 'Value']
				].concat(response.readings[device_id].map(function(reading){
					return [reading.timestamp, reading.value];
				})));

				var options = {
				  title: devices[device_id].name,
				  hAxis: {title: 'Timestamp',  titleTextStyle: {color: '#333'}},
				  vAxis: {minValue: 0},
				  animation:{
			        duration: 1000,
			        easing: 'out'
			      },
			      legend: {position: 'none'}
				};
				var chart;
				if (charts[device_id]){	
					chart = charts[device_id];
				} else {
					var id = 'device#' + device_id;
					var chartContainer = $('<div id="' + id + '"/>');
					$('#chart_div').append(chartContainer)
					chart = new google.visualization.AreaChart(chartContainer[0]);
					charts[device_id] = chart;	
				}
				chart.draw(data, options);	
			}
		});
		setTimeout(loadData, 2000);
	}
	loadData();
	
	
	
	
}