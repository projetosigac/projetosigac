(function panel() {
    $.ajax({
        type: "GET",
        url: '/defcivil/getParams',
        async: true,
        contentType: 'application/json; charset=utf-8',
        dataType: 'json',
        success: function (data){
            if(data[0].n_ambulancias_necessarias)
                $('#ambulances').text(data[0].n_ambulancias_necessarias);
            if(data[1].pol_num_missing_people)
                $('#missing').text(data[1].pol_num_missing_people);
            //data[2].stu_lat
            //data[3].stu_long
            //data[4].n_vitimas
            
            if(data[5].stu_temp)
                $('#temperature').text(data[5].stu_temp+'˚C');
            //data[6].stu_umid
            if(data[7].cri_cat){
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