    //variaveis globais
    var listaHospitais;
    var numeroVitimasSemHospital;
    var processarRotas = [];

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
        $("#btnChamarAmbulancia").button('loading');
        $("#listaHospitais").html("");
        $.ajax({
            url:          '/atendimento/carregar-base-samu',
            type:         'GET',
            contentType:  'application/json; charset=utf-8',
            dataType:     'json',
        }).done(function(data, textStatus, jqXHR) {
            //futuro: calcular a base mais próxima da ocorrência, hoje é sempre a primeira
            //var enderecoSamuMaisProxima = _analisarEnderecoProximo(enderecoAtendimento, listaEnderecos);
            mapa.clearMap();
            //mapa.deleteMarkers();
            iconCustom = [];
            iconCustom.push({title: 'Base Ambulance', image: '../images/marker-ambulance.png', address: data[0].samu_endereco});
            iconCustom.push({title: 'Local Crisis', image: '../images/marker-crisis.png', address: $("#enderecoAtendimentoGoogle").val()});
            mapa.calcularRota(data[0].samu_endereco, $("#enderecoAtendimentoGoogle").val(), iconCustom);

            _numeroAmbulancias($("#qtdVitimas").val());
            _numeroMedicos($("#qtdVitimas").val());

            $("#btnRegistrarOcorrencia").attr('disabled',false);

            _listarHospital();

            _passoMensagem(3);

        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON);
            $("#btnChamarAmbulancia").button('reset');
        });
    }

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
    var _ordernarHospitalDistancia = function (response){
      var hospitaisOrdenados = [];
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
      processarRotas = [];
      var nroHospitais = 0;
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
          iconCustom.push({
            title: 'Hospital: '+ hospitaisOrdenados[i].identificacao.hospital,
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
      if(numeroVitimasSemHospital > 0){
        $('#myModal2').modal('toggle');
      }
      _calcularMultiRotas();

      $("#nroHospitais").val(nroHospitais);

    };
    var _calcularMultiRotas = function (deleteObj){
      if(deleteObj)
        processarRotas.splice(0, 1);

      if(processarRotas.length > 0)
        mapa.calcularRota(processarRotas[0].addressOrigin, processarRotas[0].addressDestination, processarRotas[0].detail, _calcularMultiRotas);
        else {
          $("#btnChamarAmbulancia").button('reset');
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
        $("#qtdVitimas").val(1);
        $('#btnChamarAmbulancia').prop( "disabled", true);
        $('#btnRegistrarOcorrencia').prop( "disabled", true);
        mapa.clearMap();
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

    return {
        init: _init,
        pesquisarEndereco: _pesquisarEndereco,
        chamarAmbulancia: _chamarAmbulancia,
        numeroAmbulancias: _numeroAmbulancias,
        numeroMedicos: _numeroMedicos,
        clearForm: _clearForm,
        salvarOcorrencia: _salvarOcorrencia
    }
}();

$('#myModal').on('hidden.bs.modal', function (e) {
    atendimento.clearForm();
});
