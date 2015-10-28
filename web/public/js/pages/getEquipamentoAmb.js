getEquipamentoAmb = function(){
	var _api_get_equip_amb = function (){

		var aux;

		var requestData = JSON.stringify($('#formGetEquipAmb').serializeObject());
		//alert(requestData);
		$.ajax({
			url: '/api/get-equip-amb',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: requestData
		}).done(function(data, textStatus, jqXHR) {

			var size;
			//aux = JSON.stringify(data['rows'][1]['equip_descricao']);
			size = JSON.stringify(data['rows'].length);

			size = parseInt(size);

			aux = [""];

			for(i = 0; i<size; i++){
				aux[i] =  JSON.stringify(data['rows'][i]['equip_descricao']);
			}

			//alert(aux);

			aux = JSON.stringify(data['rows'].map(function(elem) {
				return elem['equip_descricao'];
			}));
			
		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});

		var vtext="";


		for(i = 0; i<aux.length;i++){


			if(aux[i] == "\""){

				for(j = i+1; aux[j] != "\"";j++ ){
					vtext += aux[j];
				}
				vtext+="\n";
				i=j;
			}

		}



		$("#equipamento_id").val(
				vtext
			);

		return false;
	}


	var _show_equip = function (){
		var jobject = [""];
		var size;
		var textEquip = "";
		var requestData = JSON.stringify($('#lista_equipamentos').serializeObject());
		$.ajax({
			url: '/api/show-equip',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: requestData
		}).done(function(data, textStatus, jqXHR) {
			size = parseInt(JSON.stringify(data['rows'].length));

			for(i = 0; i < size; i++){
				jobject[i] = JSON.stringify(data['rows'][i]['equip_descricao']);
			}

			textEquip = "";
			for(i = 0; i < size; i++){
				textEquip += jobject[i].replace(/["]/g,"") + "\n";
			} 

		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});

		$("#lista_equipamentos").val(
			textEquip
		);

		return false;
	}


	var _show_amb = function (){
		var jobject = [""];
		var size;
		var textAmb = "";
		var requestData = JSON.stringify($('#lista_amb').serializeObject());
		$.ajax({
			url: '/api/show-amb',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: requestData
		}).done(function(data, textStatus, jqXHR) {
			size = parseInt(JSON.stringify(data['rows'].length));
			for(i = 0; i < size; i++){
				jobject[i] = JSON.stringify(data['rows'][i]['placa']);
			}
			

			textAmb = "";
			for(i = 0; i < size; i++){
				textAmb += jobject[i].replace(/["]/g,"") + "\n";
			} 

		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});

		$("#lista_amb").val(
			textAmb
		);

		return false;
	}

	return {
		api_get_equip_amb: _api_get_equip_amb,
		show_equip: _show_equip,
		show_amb: _show_amb
	}
}();
