//fun��o que retorna o n�mero de m�dicos conforme o n�mero de v�timas do local.
//Para isso, tal fun��o recebe a quantidade de v�timas e uma matriz com a classifica��o de 
//triagem para cada v�tima, retornando o n�mero de m�dicos a serem enviados.
var numeroMedicos = function(qtdeVitimas, cramp) {
    var numMedicos = 0;
    var valorCramp;

    for (var i=0 ; i < qtdeVitimas ; i++) {
        valorCramp = 0;
        
        for (var j = 0; j < 5; j++) {
            valorCramp += cramp[i][j];
        }
        
        if(valorCramp < 3) {
            numMedicos += 2;
        } else if(valorCramp < 7) {
            numMedicos += 1.5;
        } else if(valorCramp < 9) {
            numMedicos += 1.2;
        } else {
            numMedicos += 1;
        }
    }

    if(numMedicos > 12) {
        numMedicos = 12;
    }

    return Math.floor(numMedicos);
}
