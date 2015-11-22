//função que retorna o número de ambulâncias conforme o número e a classificação das vítimas do local.
//Para isso, tal função recebe a quantidade de vítimas e uma matriz com a classificação de 
//triagem para cada vítima, retornando o número de ambulâncias a serem enviadoa.
var numAmbulancias = function (qtdeVitimas, cramp) {
	var numeroDeAmbulancias = 0;
	
	for(var i=0 ; i < qtdeVitimas ; i++) {
		for(var j = 0; j < 5; j++) {
			if (cramp[i][j] != 0) {
				if (j == 1 || j == 2) {
					numeroDeAmbulancias += 1;
				}
				else numeroDeAmbulancias += 0.5;
			}
		}
	}
	
	return Math.ceiling(numeroDeAmbulancias);
}