$.fn.serializeObject = function()
{
    var o = {};
    var a = this.serializeArray();
    $.each(a, function() {
        if (o[this.name] !== undefined) {
            if (!o[this.name].push) {
                o[this.name] = [o[this.name]];
            }
            o[this.name].push(this.value || '');
        } else {
            o[this.name] = this.value || '';
        }
    });
    return o;
};
$(".btnLoading").click(function() {
    var $btn = $(this);
    $btn.button('loading...');
    // simulating a timeout
    setTimeout(function () {
        $btn.button('reset');
    }, 5000);
});
util = function(){
  /**
   * Retorna o local mais próximo conforme uma origem e vários destinos
   *
   * @author Glauber, César Pereira, Danilo Ramalho
   *
   * @param origem Endereço de partida
   * @param listaDestinos Lista de endereços separados por pipe, podendo ser latitude e longitude ou o endereço completo
   */
  var _calcularMatrixDistancia = function (origem, listaDestinos, callback) {
      var distanceService = new google.maps.DistanceMatrixService();
      distanceService.getDistanceMatrix({
          origins: origem,
          destinations: listaDestinos,
          travelMode: google.maps.TravelMode.DRIVING,
          unitSystem: google.maps.UnitSystem.METRIC,
          durationInTraffic: true,
          avoidHighways: false,
          avoidTolls: false
      },

      function (response, status) {
          if (status == google.maps.DistanceMatrixStatus.OVER_QUERY_LIMIT) {
              setTimeout(function() {
                  _calcularMatrixDistancia(origem, listaDestinos, callback);
              }, 200);
          }

          else if (status != google.maps.DistanceMatrixStatus.OK) {
              console.log('Error:', status);
          }

          else {
              callback(response);
          }
      });
  }
  return{
    calcularMatrixDistancia: _calcularMatrixDistancia
  }
}();
