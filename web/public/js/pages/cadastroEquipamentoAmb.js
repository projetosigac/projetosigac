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
			//Equipamento Inserido na Ambulância
				$("#labelMsg").html("Equipment included in ambulance with successfully!");
				$("#imgMsg").attr("src","/../images/ok.png");
				$('#myModal').modal('toggle');
		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});



		return false;
	}
	var _api_delete_equip_amb = function (){

		var requestData = JSON.stringify($('#formInsertEquipAmb').serializeObject());
		//$("#lista_equipamentos").html("testando");
		//alert(requestData);

		$.ajax({
			url: '/api/delete-equip-amb',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: requestData
		}).done(function(data, textStatus, jqXHR) {
			//Equipamento Deletado da Ambulância
			$("#labelMsg").html("Equipment excluded with successfully the ambulance!");
			$("#imgMsg").attr("src","/../images/remove.png");
			$('#myModal').modal('toggle');


		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});



		return false;
	}
	return {
		api_insert_equip_amb: _api_insert_equip_amb,
		api_delete_equip_amb: _api_delete_equip_amb
	}
}();
