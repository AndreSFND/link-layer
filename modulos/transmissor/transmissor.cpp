#include "transmissor.hpp"

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

#define TIPO_CONTROLE_ERRO 1
#define TAMANHO_PARIDADE 8

// Camadas transmissoras
vector<int> AplicacaoTransmissora();
vector<int> CamadaDeAplicacaoTransmissora(string mensagem);
vector<int> CamadaEnlaceDadosTransmissora(vector<int> &quadro);

// Controle de erros
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(vector<int> &quadro);
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(vector<int> &quadro);
void CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int> &quadro);

// Utilidades
vector<int> stringToBinary(string words);


// Le a entrada do usuario
vector<int> AplicacaoTransmissora() {

    // Le a entrada do usuario
    string mensagem;
    cout << "Digite uma mensagem: " << endl;
    cin >> mensagem;

    // Chama a proxima camada
    return CamadaDeAplicacaoTransmissora(mensagem);

}

// Converte a entrada do usuario para binario
vector<int> CamadaDeAplicacaoTransmissora(string mensagem) {

    // Converte a mensagem do usuario para um vetor binario
    vector<int> quadro = stringToBinary(mensagem);

    // Chama a proxima camada
    return CamadaEnlaceDadosTransmissora(quadro);

}

// Adiciona bits para controle de erros
vector<int> CamadaEnlaceDadosTransmissora(vector<int> &quadro) {

    // Seleciona o tipo de controle de erro
    switch( TIPO_CONTROLE_ERRO ) {

        case 0:
        
            CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(quadro);
        
        break;

        case 1:
        
            CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(quadro);
        
        break;

        case 2:

            CamadaEnlaceDadosTransmissoraControleDeErroCRC(quadro);

        break;

    }

    return quadro;

}

// Adiciona o metodo de paridade par para controle de erros
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(vector<int> &quadro) {

    // Inicializa o vetor auxiliar que armazena os dados com bits de controle de erros
    vector<int> quadroFinal;

    // Inicializa as variaveis que armazenam as somas das linhas e colunas
    int horizontalSum = 0;
    vector<int> linhaFinal(TAMANHO_PARIDADE+1);

    // Le o comprimento do vetor de dados
    int length = quadro.size();

    // Realiza uma iteracao pelo vetor de dados
    for( int i=0; i<length; i++ ) {

        // Le o bit atual
        int bit = quadro[i];

        // Soma o bit atual e o insere no vetor auxiliar
        horizontalSum += bit;
        quadroFinal.push_back(bit);

        // Ao acabar um byte (8 bits), 
        if( (i+1) % TAMANHO_PARIDADE == 0 ) {

            // Verifica se a linha eh par ou impar
            int paridade = horizontalSum % 2;

            // Insere o bit de paridade no vetor auxiliar
            quadroFinal.push_back( paridade );
            horizontalSum = 0;

            // Atualiza o vetor de soma da linha final
            linhaFinal[TAMANHO_PARIDADE] += paridade;

        }

        // Atualiza o vetor de soma da linha final
        linhaFinal[ i%TAMANHO_PARIDADE ] += bit;

    }

    // Atualiza o vetor da linha final, defininindo os bits de paridade com base nas somas das colunas
    for( int i=0; i<(TAMANHO_PARIDADE+1); i++ ) {

        linhaFinal[ i ] = linhaFinal[ i ] % 2;

    }

    // Concatena o vetor auxiliar ao vetor da linha final
    quadroFinal.insert( quadroFinal.end(), linhaFinal.begin(), linhaFinal.end() );

    // Atualiza o vetor de dados
    quadro = quadroFinal;

    // Imprime os dados antes do envio ao ponto B
    cout << endl << "Dados antes do envio:" << endl;

    length = quadroFinal.size();
    for( int i=0; i<length; i++ ) {

        cout << quadroFinal[i] << ' ';

        if( (i+1) % (TAMANHO_PARIDADE+1) == 0 ) cout << endl;

    }

    cout << endl;

}

// Adiciona o metodo de paridade impar para controle de erros
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(vector<int> &quadro) {

    // Inicializa o vetor auxiliar que armazena os dados com bits de controle de erros
    vector<int> quadroFinal;

    // Inicializa as variaveis que armazenam as somas das linhas e colunas
    int horizontalSum = 0;
    vector<int> linhaFinal(TAMANHO_PARIDADE+1);

    // Le o comprimento do vetor de dados
    int length = quadro.size();

    // Realiza uma iteracao pelo vetor de dados
    for( int i=0; i<length; i++ ) {

        // Le o bit atual
        int bit = quadro[i];

        // Soma o bit atual e o insere no vetor auxiliar
        horizontalSum += bit;
        quadroFinal.push_back(bit);

        // Ao acabar um byte (8 bits), 
        if( (i+1) % TAMANHO_PARIDADE == 0 ) {

            // Verifica se a linha eh par ou impar
            int paridade = horizontalSum % 2 == 1;

            // Insere o bit de paridade no vetor auxiliar
            quadroFinal.push_back( paridade );
            horizontalSum = 0;

            // Atualiza o vetor de soma da linha final
            linhaFinal[TAMANHO_PARIDADE] += paridade;

        }

        // Atualiza o vetor de soma da linha final
        linhaFinal[ i%TAMANHO_PARIDADE ] += bit;

    }

    // Atualiza o vetor da linha final, defininindo os bits de paridade com base nas somas das colunas
    for( int i=0; i<(TAMANHO_PARIDADE+1); i++ ) {

        linhaFinal[ i ] = linhaFinal[ i ] % 2 == 1;

    }

    // Concatena o vetor auxiliar ao vetor da linha final
    quadroFinal.insert( quadroFinal.end(), linhaFinal.begin(), linhaFinal.end() );

    // Atualiza o vetor de dados
    quadro = quadroFinal;

    // Imprime os dados antes do envio ao ponto B
    cout << endl << "Dados antes do envio:" << endl;

    length = quadroFinal.size();
    for( int i=0; i<length; i++ ) {

        cout << quadroFinal[i] << ' ';

        if( (i+1) % (TAMANHO_PARIDADE+1) == 0 ) cout << endl;

    }

    cout << endl;

}

// Adiciona o metodo CRC para controle de erros
void CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int> &quadro) {

    //

}

// Converte caracteres para binario
vector<int> stringToBinary(string words) {

    // Converte a string para uma string binaria
    string binaryString = "";
    
    for (char& _char : words) {

        binaryString += bitset<8>(_char).to_string();
    
    }

    // Converte a string para um vetor binario
    int stringLength = binaryString.length();
    vector<int> binaryData;

    int i = 0;
    for(i=0; i < stringLength; i++) {

        binaryData.push_back( binaryString[i] == '1' );

    }

    return binaryData;

}