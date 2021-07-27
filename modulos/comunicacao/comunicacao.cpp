#include "comunicacao.hpp"

// Utilizadas para gerar numeros aleatorios
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define PORCENTAGEM_ERROS 0

// Simula o meio de comunicacao entre dois pontos, gerando erros aleatorios
vector<int> MeioDeComunicacao(vector<int> &fluxoBrutoDeBits) {

    vector<int> fluxoBrutoDeBitsPontoA, fluxoBrutoDeBitsPontoB;
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

    srand( (unsigned)time(NULL) );

    for (int i=0; i<fluxoBrutoDeBitsPontoA.size(); i++) {

        int r = rand() % 100;

        int bit = r >= PORCENTAGEM_ERROS ? fluxoBrutoDeBitsPontoA[i] : !fluxoBrutoDeBitsPontoA[i];
        fluxoBrutoDeBitsPontoB.push_back(bit);

    }

    return fluxoBrutoDeBitsPontoB;

}