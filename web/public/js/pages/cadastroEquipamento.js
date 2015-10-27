cadastroEquipamento = function(){
	var _api_insert_equip = function (){

		var requestData = JSON.stringify($('#formInsertEquip').serializeObject());
		//alert(requestData);
		$.ajax({
			url: '/api/insert-equip',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: requestData
		}).done(function(data, textStatus, jqXHR) {
			//window.location.href = '/dashboard';
			alert("Equipamento Cadastrado");
		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});

		

		

		return false;
	}
	return {
		api_insert_equip: _api_insert_equip
	}
}();
