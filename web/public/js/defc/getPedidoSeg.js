var alldata = {
    recursos : ["Vehicle", "Ambulance", "Drone", "Extinguishers", "Provisions", "Traffic Signs", "Additional Human Resource"],
    segments : ["FireFighters", "Health", "Police"],
    recursosPorSegmento : {
        FireFighters : ["Vehicle"],
        Health : ["Ambulance", "Vehicle", "Provisions", "Additional Human Resource"],
        Police : ["Vehicle"]
    }
};

// var recursosPorSegmento = {}
// recursosPorSegmento["FireFighters"] = ["Vehicle"];
// recursosPorSegmento["Health"] = ["Ambulance", "Vehicle", "Provisions"];
// recursosPorSegmento["Police"] = ["Vehicle"];

getPedidoSeg = function(){

    var _reg_equip = function(){
        var objForm = $('#formInsertEquip').serializeObject();

        if (!objForm.equipDesc) {
            alert("The field can not be empty");
            return false;
        }

        var requestData = JSON.stringify(objForm);

        alldata.recursos.push(requestData);

        return false;
    }

    var _api_get_equip_amb = function (){


        var aux;
        var objForm = $('#formGetEquipAmb').serializeObject();
        if(!objForm.placaAmbGet){
            alert("The field can not be empty");
            return false;
        }
        var requestData = JSON.stringify(objForm);

        //alert(requestData);
        $.ajax({
            url: '/api/get-equip-amb',
            type: 'POST',
            async: false,
            contentType: 'application/json; charset=utf-8',
            dataType: 'json',
            data: requestData
        }).done(function(data, textStatus, jqXHR) {

            var size;
            //aux = JSON.stringify(data['rows'][1]['equip_descricao']);
            size = JSON.stringify(data['rows'].length);

            size = parseInt(size);

            aux = [""];

            for(i = 0; i<size; i++){
                aux[i] =  JSON.stringify(data['rows'][i]['equip_descricao']);
            }

            //alert(aux);

            aux = JSON.stringify(data['rows'].map(function(elem) {
                return elem['equip_descricao'];
            }));

        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON.message);
        });

        var vtext="";
        $('#tableEquipamentoPlaca tbody').html('');
        var escrita = requestData
        escrita = escrita.substring(16);
        escrita = escrita.substring(0, escrita.length-2);
        
        for(i = 0; i < alldata.recursosPorSegmento[escrita].length; i++){
            tr = $('<tr/>');
        tr.append("<td><i style='cursor:pointer;' class='glyphicon glyphicon-trash';></i></td>");
            tr.append("<td>"+alldata.recursosPorSegmento[escrita][i]+"\n"+"</td>");
            $('#tableEquipamentoPlaca tbody').append(tr);
        }
        

        $("#equipamento_id").val(
                vtext
            );

        return false;
    }

    var _show_equip = function (){
        var jobject = [""];
        var size;
        var textEquip = "";
        var requestData = JSON.stringify($('#lista_equipamentos').serializeObject());
        $.ajax({
            url: '/api/show-equip',
            type: 'POST',
            async: false,
            contentType: 'application/json; charset=utf-8',
            dataType: 'json',
            data: requestData
        }).done(function(data, textStatus, jqXHR) {
            size = parseInt(JSON.stringify(data['rows'].length));

            for (i = 0; i < size; i++) {
                jobject[i] = JSON.stringify(data['rows'][i]['equip_descricao']);
            }

            $('#tableEquipamento tbody').html('');
            $('#nomeEquipamentoAmb').find('option').remove().end().append('<option value="">Select an equipament</option>').val('');

            for (i = 0; i < alldata.recursos.length; i++) {
                //textEquip += jobject[i].replace(/["]/g,"") + "\n";
                //var nomeEquipamento = jobject[i].replace(/["]/g,"");
                var nomeEquipamento = alldata.recursos[i];
                tr = $('<tr/>');
                tr.append("<td><i style='cursor:pointer;' class='glyphicon glyphicon-trash' onclick=cadastroEquipamento.api_delete_equip('"+nomeEquipamento+"');></i></td>");
                tr.append("<td>"+nomeEquipamento+"</td>");
                $('#tableEquipamento tbody').append(tr);

                $('<option>').val(nomeEquipamento).text(nomeEquipamento).appendTo('#nomeEquipamentoAmb');
            }

        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON.message);
        });

        return false;
    }

    var _show_amb = function (){
        var jobject = [""];
        var size;
        var textAmb = "";
        var requestData = JSON.stringify($('#lista_amb').serializeObject());
        $.ajax({
            url: '/api/show-amb',
            type: 'POST',
            async: false,
            contentType: 'application/json; charset=utf-8',
            dataType: 'json',
            data: requestData
        }).done(function(data, textStatus, jqXHR) {
            size = parseInt(JSON.stringify(data['rows'].length));
            for (i = 0; i < size; i++) {
                jobject[i] = JSON.stringify(data['rows'][i]['placa']);
            }

            textAmb = "";
            $('.placa').find('option').remove().end().append('<option value="">Select a segment</option>').val('');
            for (i = 0; i < alldata.segments.length; i++) {
                //textAmb += jobject[i].replace(/["]/g,"") + "\n";
                var placa = alldata.segments[i].replace(/["]/g,"");
                $('<option>').val(placa).text(placa).appendTo('.placa');
            }

        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON.message);
        });

        //$("#lista_amb").val(textAmb);

        return false;
    }

    var _api_insert_equip_amb = function(){
        $("#labelMsg").html("Equipment registered successfully!");
        $("#imgMsg").attr("src","/../images/ok.png");
        $('#myModal').modal('toggle');

        return false;
    }

    return {
        api_get_equip_amb: _api_get_equip_amb,
        show_equip: _show_equip,
        show_amb: _show_amb,
        api_insert_equip_amb: _api_insert_equip_amb
    }
}();
