atendimento = function () {
    var _init = function (){
        _passoMensagem(1);
        mapa.start();
    }
    var _pesquisarEndereco = function (){
        if($("#localEmergencia").val())
        {
		      mapa.carregarNoMapa($("#localEmergencia").val());
          _passoMensagem(2);
        }
		return false;
	}
    var _chamarAmbulancia = function (){
      $.ajax({
  			url: '/atendimento/carregar-base-samu',
  			type: 'GET',
  			contentType: 'application/json; charset=utf-8',
  			dataType: 'json',
  		}).done(function(data, textStatus, jqXHR) {
        //futuro: calcular a base mais próxima da ocorrência, hoje é sempre a primeira
        //var enderecoSamuMaisProxima = _analisarEnderecoProximo(enderecoAtendimento, listaEnderecos);

        marker.setVisible(false);
        mapa.calcularRota($("#enderecoAtendimentoGoogle").val(), data[0].samu_endereco);

        _numeroAmbulancias($("#qtdVitimas").val());
        _numeroMedicos($("#qtdVitimas").val());

        $("#btnRegistrarOcorrencia").attr('disabled',false);

  		}).fail(function(jqXHR, textStatus, errorThrown) {
  			alert(jqXHR.responseJSON);
  		});
    }
    var _numeroAmbulancias = function(qtdVitimas){
        $("#qtdAmb").val(Math.ceil(2*qtdVitimas*0.12));
    }
    var _numeroMedicos = function(qtdVitimas){
        $("#qtdMed").val(Math.ceil(1.5*qtdVitimas));
    }
    var _salvarOcorrencia = function (){
      var requestData = JSON.stringify($('#formOcorrencia').serializeObject());
      $.ajax({
        type: "POST",
        url: '/atendimento/salvar-ocorrencia',
        async: false,
        contentType: 'application/json; charset=utf-8',
        dataType: 'json',
        data: requestData,
        success: function (data){
            $('#myModal').modal('toggle');
        },
        error: function(jqXHR, textStatus, errorThrown) {
    			alert(jqXHR.responseJSON);
        }
      });
    }
    var _clearForm = function (){
      _passoMensagem(1);
      $('form input[type=text]').val('');
      $('form .btn').prop( "disabled", true);
      //mapa.limparRota();
      location.reload();
    }
    var _passoMensagem = function (passo){
        switch(passo) {
            case 1:
                $("#passo").html("<b>1º Passo:</b> Digite no combo de endereço o local da emergência.");
                break;
            case 2:
                $("#passo").html("<b>2º Passo:</b> Informe a quantidade de vítimas e calcule as ambulâncias.");
                break;
            case 3:
                $("#passo").html("<b>3º Passo:</b> Clique em 'Registrar Ocorrência para encaminhar o atendimento.'");
                break;
        }
    }
    return{
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
