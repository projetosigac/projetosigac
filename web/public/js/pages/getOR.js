getOR = function() {
	var _show_OR = function (){
        var size;
        var requestData = JSON.stringify($('#lista_ORs').serializeObject());

        $.ajax({
            url: '/api/show-ORs',
            type: 'POST',
            async: false,
            contentType: 'application/json; charset=utf-8',
            dataType: 'json',
            data: requestData
        }).done(function(data, textStatus, jqXHR) {
            size = parseInt(JSON.stringify(data['rows'].length));

            $('#tableOR tbody').html('');

            $('#tableOR thead').html('');
            tr = $('<tr/>');
            tr.append("<th class=\"col-xs-1\">id</th>");
            tr.append("<th class=\"col-xs-1\">officerid</th>");
            tr.append("<th class=\"col-xs-2\">name</th>");
            tr.append("<th class=\"col-xs-8\">description</th>");
            $('#tableOR thead').append(tr);


            for (i = 0; i < size; i++) {
                var id = JSON.stringify(data['rows'][i]['pol_victim_ident']).replace(/["]/g,"");
                var officerid = JSON.stringify(data['rows'][i]['por_officer_id']).replace(/["]/g,"");
                var name = JSON.stringify(data['rows'][i]['pol_victim_name']).replace(/["]/g,"");
                var description = JSON.stringify(data['rows'][i]['pol_desc']).replace(/["]/g,"");

                tr = $('<tr/>');
                //tr.append("<td><i style='cursor:pointer;' class='glyphicon glyphicon-trash' onclick=cadastroEquipamento.api_delete_equip('"+nomeEquipamento+"');></i></td>");
                tr.append("<td>"+id+"</td>");
                tr.append("<td>"+officerid+"</td>");
                tr.append("<td>"+name+"</td>");
                tr.append("<td>"+description+"</td>");
                $('#tableOR tbody').append(tr);
            }

        }).fail(function(jqXHR, textStatus, errorThrown) {
            alert(jqXHR.responseJSON.message);
        });

        return false;
    }
    return {
        show_OR: _show_OR
    }
}();