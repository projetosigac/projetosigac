cadastroEquipamento = function(){
	var _api_insert_equip = function (){
		var objForm = $('#formInsertEquip').serializeObject();
		if(!objForm.equipDesc)
		{
			alert("The field can not be empty");
			return false;
		}

		var requestData = JSON.stringify(objForm);
		$.ajax({
			url: '/api/insert-equip',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: requestData
		}).done(function(data, textStatus, jqXHR) {
				//equipamento incluído com sucesso
				$("#labelMsg").html("Equipment included with successfully!");
				$("#imgMsg").attr("src","/../images/ok.png");
				$('#myModal').modal('toggle');
		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});

		return false;
	}

	var _api_delete_equip = function (item){

		var requestData = JSON.stringify($('#formInsertEquip').serializeObject());
		//alert(requestData);
		$.ajax({
			url: '/api/delete-equip',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: JSON.stringify({'equipDesc': item})
		}).done(function(data, textStatus, jqXHR) {
				//equipamento excluído com sucesso
				$("#labelMsg").html("Equipment excluded with successfully!");
				$("#imgMsg").attr("src","/../images/remove.png");
				$('#myModal').modal('toggle');

				getEquipamentoAmb.show_equip();

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
