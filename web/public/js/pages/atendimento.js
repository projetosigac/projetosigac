    //variaveis globais
    var listaHospitais;
    var listaAmbulancias;
    var numeroVitimasSemHospital;
    var numeroVitimasSemAmbulancia;
    var objCrise;

atendimento = function () {

    var _init = function () {
        _passoMensagem(1);
        mapa.start();

        _show_crisis();
    }

    var _preencherCrise = function(id){
      if(id != ''){
        var obj = objCrise.filter(function(x){return x.cri_id == id});
        mapa.geocodeLatLng(obj[0].latitudeBoxValue, obj[0].LongitudeBoxValue, _preencherLocalEmergencia);
        $("#latitudeEmergencia").val(obj[0].latitudeBoxValue);
        $("#longitudeEmergencia").val(obj[0].LongitudeBoxValue);
        $("#qtdVitimas").val(obj[0].cri_afetados);

      }
    };
    var _preencherLocalEmergencia = function (resultGeocode){
      mapa.carregarNoMapa(resultGeocode.formatted_address);
      $("#localEmergencia").val(resultGeocode.formatted_address);
      $("#enderecoAtendimentoGoogle").val(resultGeocode.formatted_address);
    };

    var _pesquisarEndereco = function (callback) {
        if($("#localEmergencia").val() && $("#listaCriseSelecao").val()) {
            mapa.carregarNoMapa($("#localEmergencia").val());
            _passoMensagem(2);
            if(callback)
              callback();
        }

        return false;
    }

    var _chamarAmbulancia = function () {
        $("#btnChamarAmbulancia").button('loading');
        $("#listaHospitais").html("");
        $.ajax({
            url:          '/atendimento/carregar-ambulancia-ativa',
            type:         'GET',
            contentType:  'application/json; charset=utf-8',
            dataType:     'json',
        }).done(function(data, textStatus, jqXHR) {
            listaAmbulancias = data;
            numeroVitimasSemAmbulancia = parseInt($("#qtdVitimas").val());

            var ambulancias = [];
            var localEmergencia = [];
            //laço pra agrupar por pipe
            for (var i = 0; i < data.length; i++) {
              ambulancias.push(new google.maps.LatLng(data[i].latitude, data[i].longitude));
              localEmergencia.push($("#enderecoAtendimentoGoogle").val());
            }
            util.calcularMatrixDistancia(localEmergencia, ambulancias, _ordernarAmbulanciaDistancia);

        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON);
            $("#btnChamarAmbulancia").button('reset');
        });
    }

    var _validaMapa = function (){

        mapa.clearMap(function (){
          _pesquisarEndereco(_chamarAmbulancia);
        });
    };

    var _listarHospital = function (){

        $.ajax({
            url:          '/atendimento/listar-hospital-leito-disponivel',
            type:         'GET',
            contentType:  'application/json; charset=utf-8',
            dataType:     'json',
        }).done(function(data, textStatus, jqXHR) {



          listaHospitais = data;
          numeroVitimasSemHospital = parseInt($("#qtdVitimas").val());
          var hospitaisSelecionados = [];
          var hospitais = [];
          var localEmergencia = [];
          //laço pra agrupar por pipe
          for (var i = 0; i < data.length; i++) {
            hospitais.push(data[i].endereco);
            localEmergencia.push($("#enderecoAtendimentoGoogle").val());
          }
          util.calcularMatrixDistancia(localEmergencia, hospitais, _ordernarHospitalDistancia);

        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON);
            $("#btnChamarAmbulancia").button('reset');
        });


    }
    var _ordernarMatrixDistancia = function (responseAPI, listaObjeto){
      var enderecosOrdenados = [];

      for (var i = 0; i < responseAPI.rows.length; i++) {

        enderecosOrdenados.push(
          {
            identificacao: listaObjeto[i],
            endereco: responseAPI.destinationAddresses[i],
            kmValue: responseAPI.rows[i].elements[i].distance.value,
            kmText: responseAPI.rows[i].elements[i].distance.text,
            tempoValue:responseAPI.rows[i].elements[i].duration.value,
            tempoText:responseAPI.rows[i].elements[i].duration.text
          });
      }
      enderecosOrdenados.sort(function(a, b) {
        return a.kmValue - b.kmValue;
      });

      return enderecosOrdenados;

    };

    var _ordernarAmbulanciaDistancia = function (response){

      var ambulanciasOrdenadas = _ordernarMatrixDistancia(response, listaAmbulancias);
      var processarRotas = [];

      for(var i in ambulanciasOrdenadas){
        if(numeroVitimasSemAmbulancia == 0)
          break;

        if(ambulanciasOrdenadas[i].identificacao.qtd_passageiros >= numeroVitimasSemAmbulancia)
        {
          vitimasAtendidas = numeroVitimasSemAmbulancia;
          numeroVitimasSemAmbulancia = 0;
        }else{
          numeroVitimasSemAmbulancia = numeroVitimasSemAmbulancia - ambulanciasOrdenadas[i].identificacao.qtd_passageiros;
          vitimasAtendidas = ambulanciasOrdenadas[i].identificacao.qtd_passageiros;
        }

          iconCustom = [];
          iconCustom.push({
            title: 'Ambulance: '+ ambulanciasOrdenadas[i].identificacao.placa,
            image: '../images/marker-ambulance.png',
            address: new google.maps.LatLng(ambulanciasOrdenadas[i].identificacao.latitude,ambulanciasOrdenadas[i].identificacao.longitude)
          });

          processarRotas.push(
            {
              detail: iconCustom,
              addressOrigin:$("#enderecoAtendimentoGoogle").val(),
              addressDestination: iconCustom[0].address
            });

      }

      _calcularMultiRotas(processarRotas, function (){
        _numeroAmbulancias($("#qtdVitimas").val());
        _numeroMedicos($("#qtdVitimas").val());
        $("#btnRegistrarOcorrencia").attr('disabled',false);
        _listarHospital();
        _passoMensagem(3);
      });

    };

    var _ordernarHospitalDistancia = function (response){

/*
      for (var i = 0; i < response.rows.length; i++) {

        hospitaisOrdenados.push(
          {
            identificacao: listaHospitais[i],
            endereco: response.destinationAddresses[i],
            kmValue: response.rows[i].elements[i].distance.value,
            kmText: response.rows[i].elements[i].distance.text,
            tempoValue:response.rows[i].elements[i].duration.value,
            tempoText:response.rows[i].elements[i].duration.text
          });
      }
      hospitaisOrdenados.sort(function(a, b) {
        return a.kmValue - b.kmValue;
      });

      */

      var hospitaisOrdenados = _ordernarMatrixDistancia(response, listaHospitais);
      processarRotas = [];
      var nroHospitais = 0;
      var processarRotas = [];

      for(var i in hospitaisOrdenados){
        if(numeroVitimasSemHospital == 0)
          break;

        if(hospitaisOrdenados[i].identificacao.leitos_disponiveis >= numeroVitimasSemHospital)
        {
          vitimasAtendidas = numeroVitimasSemHospital;
          numeroVitimasSemHospital = 0;
        }else{
          numeroVitimasSemHospital = numeroVitimasSemHospital - hospitaisOrdenados[i].identificacao.leitos_disponiveis;
          vitimasAtendidas = hospitaisOrdenados[i].identificacao.leitos_disponiveis;
        }

          //bind no formulário
          ul = "<ul class='list-inline'><li><label>Hospital:</label> \
                <input type='hidden' value='"+hospitaisOrdenados[i].identificacao.id_hospital+"' name='idHospital' /> \
                <input readonly='true' type='text' value='"+hospitaisOrdenados[i].identificacao.hospital+"' class='form-control' name='hospital' id='hospital' /> \
                </li><li><label>Victims Qty:</label> \
                <input readonly='true' type='text' value='"+vitimasAtendidas+"' class='form-control' style='width:60px;' name='qtdVitimaHospital' id='qtdVitimaHospital' /> \
                </li></ul>"
          $("#listaHospitais").append(ul);
          nroHospitais++;

          iconCustom = [];

          var titleTemp = hospitaisOrdenados[i].identificacao.hospital;
          if(titleTemp.indexOf("Hospital") == -1)
            titleTemp = 'Hospital: '+ hospitaisOrdenados[i].identificacao.hospital

          iconCustom.push({
            title: titleTemp,
            image: '../images/marker-hospital.png',
            address: hospitaisOrdenados[i].identificacao.endereco
          });

          processarRotas.push(
            {
              detail: iconCustom,
              addressOrigin:$("#enderecoAtendimentoGoogle").val(),
              addressDestination: hospitaisOrdenados[i].identificacao.endereco
            });

      }
      _calcularMultiRotas(processarRotas);

      $("#nroHospitais").val(nroHospitais);

    };
    var _calcularMultiRotas = function (processarRotas, callback){

      if(processarRotas.length > 0)
      {
        mapa.calcularRota(processarRotas[0].addressOrigin, processarRotas[0].addressDestination, processarRotas[0].detail, function (){_calcularMultiRotas(processarRotas, callback);});
        if(processarRotas)
          processarRotas.splice(0, 1);
      }else {
        if(callback)
          callback();
        else{
            var alerta = false;
            $("#msgLimiteHospital").hide();
            $("#msgLimiteAmbulancia").hide();
            if(numeroVitimasSemHospital > 0){
              $("#msgLimiteHospital").show();
              alerta = true;
            }
            if(numeroVitimasSemAmbulancia > 0){
              $("#msgLimiteAmbulancia").show();
              alerta = true;
            }
            if(alerta)
              $('#myModal2').modal('toggle');

            $("#btnChamarAmbulancia").button('reset');
            }
        }

    }
    var _calcularLocalMaisProximo = function (response){
      var caminhos_json = response;
      var melhor_endereco = origem[0];
      var tempo_minimo = 0;
      var encontrou = false;

      for (var x = 0; x < origem.length; x++) {
          if (caminhos_json['rows'][x]['elements'][0]['status'] == 'OK') {
              if (encontrou == false || caminhos_json['rows'][x]['elements'][0]['duration']['value'] < tempo_minimo) {
                  tempo_minimo = caminhos_json['rows'][x]['elements'][0]['duration']['value'];
                  melhor_endereco = origem[x];
                  encontrou = true;
              }
          }
      }

      //$("#maisProxima"+ocorrencia.id).text(melhor_endereco);
      //return melhor_endereco;
    }
    var _numeroAmbulancias = function(qtdVitimas) {
        $("#qtdAmb").val(Math.ceil(2*qtdVitimas*0.12));
    }

    var _numeroMedicos = function(qtdVitimas) {
        $("#qtdMed").val(Math.ceil(qtdVitimas*0.12));
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
        $("#qtdVitimas").val(1);
        $('#btnChamarAmbulancia').prop( "disabled", true);
        $('#btnRegistrarOcorrencia').prop( "disabled", true);
        _show_crisis();
        mapa.clearMap();
    }

    var _passoMensagem = function (passo) {
        switch(passo) {
            case 1:
                $("#passo").html("<b>1º Step:</b> Select the crisis.");
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
       $("#listaCriseSelecao").find('option').remove();
        $.ajax({
            url: '/api/show-crisis',
            type: 'POST',
            async: false,
            contentType: 'application/json; charset=utf-8',
            dataType: 'json'
        }).done(function(data, textStatus, jqXHR) {
          if(data.status == "OK"){
            $('<option>').val('').text('Select Crisis').appendTo('#listaCriseSelecao');

            for(i in data.rows){
              $('<option>').val(data.rows[i].cri_id).text(data.rows[i].cri_ds).appendTo('#listaCriseSelecao');
            }
            objCrise = data.rows;
          }

        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON.message);
        });


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
        api_get_crisis: _api_get_crisis,
        preencherCrise: _preencherCrise,
        validaMapa: _validaMapa
    }
}();

$('#myModal').on('hidden.bs.modal', function (e) {
    atendimento.clearForm();
});
