//Segundo o manual de medicina de desastres, é necessária uma
//unidade de resgate para cada paciente de alto risco (utilizei
//o intervalo de triagem cramp de 2 a 6 para estes), 
//e para pacientes de mediana gravidade são enviadas ambulâncias 
//que evacuam, em média, 6 pacientes.
//Assumi que recebe-se um vetor onde cada posição possui a
//classificação de triagem de uma das vítimas.

var numeroAmbulancias = function(vitimasCramp)
{
	var ocupacaoAmbulancia = 0;
	var numAmbulancias = 0;
	for(var i = 0; i < vitimasCramp.length; i++)
	{
		if(vitimasCramp[i] >= 2 && vitimasCramp[i] <= 6)
			numAmbulancias++;
		else if(vitimasCramp[i] >= 7 && ocupacaoAmbulancia == 0)
		{
			numAmbulancias++;
			ocupacaoAmbulancia++;
		}
		else if(vitimasCramp[i] >= 7)
			ocupacaoAmbulancia++;

		if(ocupacaoAmbulancia == 6)
			ocupacaoAmbulancia = 0;
	}
	return numAmbulancias;
}