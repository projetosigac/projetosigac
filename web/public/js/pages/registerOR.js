registerOR = function() {
    var _api_insert_OR = function () {
        var objForm = $('#formInsertOR').serializeObject();

        if (!objForm.officerid) {
            alert("The field can not be empty");
            return false;
        }

        var requestData = JSON.stringify(objForm);

        $.ajax({
            url: '/api/insert-OR',
            type: 'POST',
            async: false,
            contentType: 'application/json; charset=utf-8',
            dataType: 'json',
            data: requestData
        }).done(function(data, textStatus, jqXHR) {
            //$("#labelMsg").html("Equipment registered successfully!");
            $( '#formInsertOR' ).each(function(){
                this.reset();
            });
        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON.message);
        });

        return false;
    }

    return {
        api_insert_OR: _api_insert_OR
    }
}();
