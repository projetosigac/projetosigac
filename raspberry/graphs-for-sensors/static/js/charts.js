(function(){
    function create_chart(minValue, maxValue, interpolation, labels_disabled, canvas, delay) {
        var chart = new SmoothieChart({
            "grid": {
                "verticalSections": 4,
                "millisPerLine": 5 * 1000
            },
            "timestampFormatter": SmoothieChart.timeFormatter,
            "minValue": minValue,
            "maxValue": maxValue,
            "interpolation": interpolation,
            "millisPerPixel": 50,
            "labels": { "disabled": labels_disabled },
        });
        chart.streamTo(document.getElementById(canvas), delay);

        var stream = new TimeSeries();
        chart.addTimeSeries(stream, { "lineWidth": 3 });

        return stream;
    }

    var streams = {
        "temperature": create_chart(25, 45, "bezier", false, "t_canvas", 1000),
        "heartbeat": create_chart(-10, 10, "linear", true, "hb_canvas", 200),
    }

    // Server Side Events
    function listen(type, suffix) {
        var source = new EventSource("/stream/" + type);
        source.onmessage = function(msg) {
            try {
                var obj = JSON.parse(msg.data);
                var time = parseFloat(obj.time);
                var value = parseFloat(obj.value);

                streams[type].append(time, value);
                document.getElementById(type).value = value.toFixed(2) + suffix;
            } catch (e) {
                console.log(e);
            }
        }
    }

    listen("temperature", " °C");
    listen("heartbeat", "");
})();
