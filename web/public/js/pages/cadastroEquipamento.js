cadastroEquipamento = function(){
	var _api_insert_equip = function (){

		var requestData = JSON.stringify($('#formInsertEquip').serializeObject());
		$.ajax({
			url: '/api/insert-equip',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: requestData
		}).done(function(data, textStatus, jqXHR) {
			alert("Equipamento Cadastrado");
		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});

		return false;
	}

	var _api_delete_equip = function (){

		var requestData = JSON.stringify($('#formInsertEquip').serializeObject());
		//alert(requestData);
		$.ajax({
			url: '/api/delete-equip',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: requestData
		}).done(function(data, textStatus, jqXHR) {
			alert("Equipamento Deletado");
		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});

		return false;
	}


	return {
		api_insert_equip: _api_insert_equip,
		api_delete_equip: _api_delete_equip
	}
}();
