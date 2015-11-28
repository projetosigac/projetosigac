var victimsChart,specialistsChart;

(function panel() {
    $.ajax({
        type: "GET",
        url: '/defc/getParams',
        async: true,
        contentType: 'application/json; charset=utf-8',
        dataType: 'json',
        success: function (data){
            if(typeof data[0].n_ambulancias_necessarias !== undefined){
                specialistsChart.datasets[0].bars[1].value = data[0].n_ambulancias_necessarias;
                specialistsChart.update();
                $('#ambulances').text(data[0].n_ambulancias_necessarias);
            }
            if(typeof data[1].pol_num_missing_people !== undefined){
                victimsChart.datasets[0].bars[1].value = data[1].pol_num_missing_people;
                victimsChart.update();                
               $('#missing').text(data[1].pol_num_missing_people);
            }
            
            if(typeof data[5].stu_temp !== undefined){
               $('#temperature').text(data[5].stu_temp+'˚C'); 
            }
               
            if(typeof data[7].cri_cat !== undefined){
                switch(data[7].cri_cat){
                    case 'Small':
                        $('#classif').text('SMALL');
                        $('#classif').attr("class","small-crisis");
                    break;

                    case 'Medium':
                        $('#classif').text('MEDIUM');
                        $('#classif').attr("class","medium-crisis");

                    break;
                    
                    case 'Large':
                        $('#classif').text('LARGE');
                        $('#classif').attr("class","large-crisis");
                    break;
                }
            }
        },
        error: function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON);
        },
        complete: function(){
            setTimeout(panel, 3000);
        }
      });
})();

function victims(elem){

  var ctx = $('#victims-chart').get(0).getContext('2d');

  var data = {
    labels: [
      'Survivors', 'Missing', 'Dead'
    ],
    datasets: [
      {
          label: 'Number of Victims',
          fillColor: 'rgba(4,151,179,0.5)',
          highlightFill: 'rgba(0,163,124,0.5)',
          data: [28, 48, 40]
      }
    ]
  };
  var options = {
    barStrokeWidth : 1,
    responsive: true,
    animation: true,
    barShowStroke: false,
    scaleOverride : true,
    scaleSteps : 8,
    scaleStepWidth : 10,
    scaleBeginAtZero : true,
    scaleShowGridLines : false,
    scaleShowHorizontalLines: true,
    scaleShowVerticalLines: true,
    barValueSpacing : 5,
    barDatasetSpacing : 1,

  };

  victimsChart = new Chart(ctx).HorizontalBar(data, options);
    $('#victims-chart').css('width','540');
}

function specialists(elem){

  var ctx = $('#specialists-chart').get(0).getContext('2d');
  var data = {
    labels: [
      'Paramedics', 'Ambulances', 'Firemen', 'Policemen'
    ],
    datasets: [
      {
          label: 'Number of Specialists',
          fillColor: 'rgba(4,151,179,0.5)',
          highlightFill: 'rgba(0,163,124,0.5)',
          data: [28, 48, 40, 30]
      }
    ]
  };
  var options = {
    barStrokeWidth : 1,
    responsive: true,
    animation: true,
    barShowStroke: false,
    scaleOverride : true,
    scaleSteps : 8,
    scaleStepWidth : 10,    
    scaleBeginAtZero : true,
    scaleShowGridLines : false,
    scaleShowHorizontalLines: true,
    scaleShowVerticalLines: true,
    barValueSpacing : 5,
    barDatasetSpacing : 1,
  };

  specialistsChart = new Chart(ctx).HorizontalBar(data, options);
  $('#specialists-chart').css('width','540');

}

$(function(){
    specialists(null);
    victims(null);
});