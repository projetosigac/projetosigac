index = function(){
	var _api_user_login = function (){
			
		var requestData = JSON.stringify($('#formLogin').serializeObject());
		
		$.ajax({
			url: '/api/login-sistema',
			type: 'POST',
			async: false,
			contentType: 'application/json; charset=utf-8',
			dataType: 'json',
			data: requestData
		}).done(function(data, textStatus, jqXHR) {
			//$.sessionStorage.setItem('userToken', data.token);
			window.location.href = '/atendimento';
		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(textStatus);
		});
		
		return false;
	}
	return {
		api_user_login: _api_user_login
	}
}();