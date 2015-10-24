getEquipamentoAmb = function(){
	var _api_get_equip_amb = function (){

		var requestData = JSON.stringify($('#formGetEquipAmb').serializeObject());
		alert(requestData);
		$.ajax({
			url: '/api/get-equip-amb',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: requestData
		}).done(function(data, textStatus, jqXHR) {
			//window.location.href = '/dashboard';
			alert("Equipamento Obtido com Sucesso");
		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});

		return false;
	}
	return {
		api_get_equip_amb: _api_get_equip_amb
	}
}();
