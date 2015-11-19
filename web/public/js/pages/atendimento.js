atendimento = function () {

    var _init = function () {
        _passoMensagem(1);
        mapa.start();
    }

    var _pesquisarEndereco = function () {
        if($("#localEmergencia").val()) {
            mapa.carregarNoMapa($("#localEmergencia").val());
            _passoMensagem(2);
        }

        return false;
    }

    var _chamarAmbulancia = function () {
        $.ajax({
            url:          '/atendimento/carregar-base-samu',
            type:         'GET',
            contentType:  'application/json; charset=utf-8',
            dataType:     'json',
        }).done(function(data, textStatus, jqXHR) {
            //futuro: calcular a base mais próxima da ocorrência, hoje é sempre a primeira
            //var enderecoSamuMaisProxima = _analisarEnderecoProximo(enderecoAtendimento, listaEnderecos);

            mapa.deleteMarkers();
            mapa.calcularRota($("#enderecoAtendimentoGoogle").val(), data[0].samu_endereco);

            _numeroAmbulancias($("#qtdVitimas").val());
            _numeroMedicos($("#qtdVitimas").val());

            $("#btnRegistrarOcorrencia").attr('disabled',false);

            _passoMensagem(3);
        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON);
        });
    }

    var _numeroAmbulancias = function(qtdVitimas) {
        $("#qtdAmb").val(Math.ceil(2*qtdVitimas*0.12));
    }

    var _numeroMedicos = function(qtdVitimas) {
        $("#qtdMed").val(Math.ceil(1.5*qtdVitimas));
    }

    var _salvarOcorrencia = function () {
        var requestData = JSON.stringify($('#formOcorrencia').serializeObject());
        $.ajax({
            type: "POST",
            url: '/atendimento/salvar-ocorrencia',
            async: false,
            contentType: 'application/json; charset=utf-8',
            dataType: 'json',
            data: requestData,
            success: function (data) {
                $('#myModal').modal('toggle');
            },
            error: function(jqXHR, textStatus, errorThrown) {
                alert(jqXHR.responseJSON);
            }
        });
        //$('#myModal').modal('toggle');
    }

    var _clearForm = function () {
        _passoMensagem(1);
        $('form input[type=text]').val('');
        $('#btnChamarAmbulancia').prop( "disabled", true);
        $('#btnRegistrarOcorrencia').prop( "disabled", true);
        directionsDisplay.setMap(null);
    }

    var _passoMensagem = function (passo) {
        switch(passo) {
            case 1:
                $("#passo").html("<b>1º Step:</b> Enter the Emergency address.");
                break;
            case 2:
                $("#passo").html("<b>2º Step:</b> Enter the number of victims and calculate ambulances.");
                break;
            case 3:
                $("#passo").html("<b>3º Step:</b> Click Register Occurrence to forward the call.'");
                break;
        }
    }

     var _show_crisis = function (){
       var jobject = [""];
        var size;
        var textAmb = "";
        var requestData = JSON.stringify($('#lista_amb').serializeObject());
        $.ajax({
            url: '/api/show-crisis',
            type: 'POST',
            async: false,
            contentType: 'application/json; charset=utf-8',
            dataType: 'json',
            data: requestData
        }).done(function(data, textStatus, jqXHR) {
            size = parseInt(JSON.stringify(data['rows'].length));
            for (i = 0; i < size; i++) {
                jobject[i] = JSON.stringify(data['rows'][i]['cri_id']);
            }

            textAmb = "";
            $('.crise').find('option').remove().end().append('<option value="">Select a crisis</option>').val('');
            for (i = 0; i < size; i++) {
                //textAmb += jobject[i].replace(/["]/g,"") + "\n";
                var criseid = jobject[i].replace(/["]/g,"");
                $('<option>').val(criseid).text(criseid).appendTo('.crise');
            }

        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON.message);
        });

        //$("#lista_amb").val(textAmb);

        return false;
    }


    var _api_get_crisis = function (){
        var jobject = [""];
        var objForm = $('#formOcorrencia').serializeObject();
        if(!objForm.listaCriseSelecao){
            alert("The field can not be empty");
            return false;
        }
        var requestData = JSON.stringify(objForm);

        $.ajax({
            url: '/api/get-crisis',
            type: 'POST',
            async: false,
            contentType: 'application/json; charset=utf-8',
            dataType: 'json',
            data: requestData
        }).done(function(data, textStatus, jqXHR) {

            jobject[0] = parseInt(JSON.stringify(data['rows'][0]['cri_afetados']));

            $('#qtdVitimas').val(jobject[0]);

        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON.message);
        });

        return false;
    }



    return {
        init: _init,
        pesquisarEndereco: _pesquisarEndereco,
        chamarAmbulancia: _chamarAmbulancia,
        numeroAmbulancias: _numeroAmbulancias,
        numeroMedicos: _numeroMedicos,
        clearForm: _clearForm,
        salvarOcorrencia: _salvarOcorrencia,
        show_crisis: _show_crisis,
        api_get_crisis: _api_get_crisis
    }
}();

$('#myModal').on('hidden.bs.modal', function (e) {
    atendimento.clearForm();
});
