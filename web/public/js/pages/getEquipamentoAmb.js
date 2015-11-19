getEquipamentoAmb = function(){
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

        for(i = 0; i<aux.length;i++){
            if(aux[i] == "\""){
                vtext=""

                for(j = i+1; aux[j] != "\"";j++ ){
                    vtext += aux[j];
                }

                i=j;

                tr = $('<tr/>');
                            tr.append("<td><i style='cursor:pointer;' class='glyphicon glyphicon-trash' onclick=cadastroEquipamentoAmb.api_delete_equip_amb('"+objForm.placaAmbGet+"','"+vtext.replace(' ', '_')+"');></i></td>");
                            tr.append("<td>"+vtext+"</td>");
                $('#tableEquipamentoPlaca tbody').append(tr);
            }
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

            for (i = 0; i < size; i++) {
                //textEquip += jobject[i].replace(/["]/g,"") + "\n";
                var nomeEquipamento = jobject[i].replace(/["]/g,"");
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
            $('.placa').find('option').remove().end().append('<option value="">Select a plate</option>').val('');
            for (i = 0; i < size; i++) {
                //textAmb += jobject[i].replace(/["]/g,"") + "\n";
                var placa = jobject[i].replace(/["]/g,"");
                $('<option>').val(placa).text(placa).appendTo('.placa');
            }

        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON.message);
        });

        //$("#lista_amb").val(textAmb);

        return false;
    }

    return {
        api_get_equip_amb: _api_get_equip_amb,
        show_equip: _show_equip,
        show_amb: _show_amb
    }
}();
