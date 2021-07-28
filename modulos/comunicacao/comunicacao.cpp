#include "comunicacao.hpp"

// Utilizadas para gerar numeros aleatorios
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define PORCENTAGEM_ERROS 5

// Simula o meio de comunicacao entre dois pontos, gerando erros aleatorios
vector<int> MeioDeComunicacao(vector<int> &fluxoBrutoDeBits) {

    // Inicializa os vetores que armazenam os dados nos pontos A e B
    vector<int> fluxoBrutoDeBitsPontoA, fluxoBrutoDeBitsPontoB;
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

    // Inicializa a seed para numeros aleatorios
    srand( (unsigned)time(NULL) );
    
    // Realiza uma iteracao para transferencia dos dados do ponto A ao ponto B
    for (int i=0; i<fluxoBrutoDeBitsPontoA.size(); i++) {

        int r = rand() % 100;

        // Gera erros aleatorios na transferencia
        int bit = r >= PORCENTAGEM_ERROS ? fluxoBrutoDeBitsPontoA[i] : !fluxoBrutoDeBitsPontoA[i];
        fluxoBrutoDeBitsPontoB.push_back(bit);

    }

    // Retorna os dados no ponto B
    return fluxoBrutoDeBitsPontoB;

}