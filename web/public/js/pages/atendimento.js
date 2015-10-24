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
        var endereco = $("#enderecoAtendimentoGoogle").val();

        mapa.calcularRota(endereco);
        $("#btnRegistrarOcorrencia").attr('disabled',false);
        _numeroAmbulancias($("#qtdVitimas").val());
        _numeroMedicos($("#qtdVitimas").val());
    }
    var _numeroAmbulancias = function(qtdVitimas){
        $("#qtdAmb").val(Math.ceil(2*qtdVitimas*0.12));
    }
    var _numeroMedicos = function(qtdVitimas){
        $("#qtdMed").val(Math.ceil(1.5*qtdVitimas));
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
        numeroMedicos: _numeroMedicos
    }
}();
