#instalar requests e parse para executar o código

import requests
import json
from parse import *

#função que recebe dois vetores de strings, um deles com as origens de onde as
#ambulâncias estão licalizadas e o outro com o destino final ao qual elas devem
#chegar. Supõe-se que tais parâmetros estão no formato que se deve inserir no
#Google Maps, de modo que a função seguinte converte para o formato necessário
#para se inserir na url. Exemplo de string: Rua H8A, Sao Jose dos Campos
def ambulanciaMaisProxima(origem, destino):
    
    #a variável site, criada a seguir, irá conter a url da API do Google Maps    
    site = 'https://maps.googleapis.com/maps/api/distancematrix/json?origins='

    #o loop a seguir quebra as strings localizadas no vetor origem e as insere
    #na url da forma adequada    
    for x in range (0, len(origem)):
        var = origem[x].split(' ')
        for y in range (0, len(var)):
            site = site + var[y]
            if y < len(var) - 1:
                site = site + '+'
        if x < len(origem) - 1:
            site = site + '|'
    site = site + '&destinations='

    #o loop a seguir quebra a única string localizada no vetor destino e a insere
    #na url da forma adequada 
    for x in range (0, len(destino)):
        var = destino[x].split(' ')
        for y in range (0, len(var)):
            site = site + var[y]
            if y < len(var) - 1:
                site = site + '+'
        if x < len(destino) - 1:
            site = site + '|'

    #a seguir, insere-se em site o restante da url, com a chave existente em uma
    #determinada conta
    site = site + '&mode=driving&language=pt-BR&key=AIzaSyAiHgGCX1tmUv9eQCvhgy05kpcGHUzTKhY'
    caminhos = requests.get(site)

    #converte-se o pacote recebido para o formato json
    caminhos_json = caminhos.json()    
    melhor_endereco = origem[0]
    tempo_minimo = 0
    encontrou = False

    #o loop a seguir verifica todos os tempos existentes no json e retorna o endereço
    #de origem associado ao menor destes tempos, correspondente à ambulância mais
    #próxima do acidente
    for x in range (0, len(origem)):
        if caminhos_json['rows'][x]['elements'][0]['status'] == 'OK':
            if encontrou == False or caminhos_json['rows'][x]['elements'][0]['duration']['value'] < tempo_minimo:
                tempo_minimo = caminhos_json['rows'][x]['elements'][0]['duration']['value']
                melhor_endereco = origem[x]
                encontrou = True
    return melhor_endereco
    
    


    
