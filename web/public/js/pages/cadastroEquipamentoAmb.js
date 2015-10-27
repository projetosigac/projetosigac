cadastroEquipamentoAmb = function(){
	var _api_insert_equip_amb = function (){

		var requestData = JSON.stringify($('#formInsertEquipAmb').serializeObject());
		//$("#lista_equipamentos").html("testando");
		//alert(requestData);
		
		$.ajax({
			url: '/api/insert-equip-amb',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: requestData
		}).done(function(data, textStatus, jqXHR) {
			//window.location.href = '/dashboard';
			alert("Equipamento Inserido na Ambulância");

		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});

		

		return false;
	}
	return {
		api_insert_equip_amb: _api_insert_equip_amb
	}
}();
