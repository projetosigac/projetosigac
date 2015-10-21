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
			window.location.href = '/dashboard';
		}).fail(function(jqXHR, textStatus, errorThrown) {
			alert(jqXHR.responseJSON.message);
		});

		return false;
	}
	return {
		api_user_login: _api_user_login
	}
}();
