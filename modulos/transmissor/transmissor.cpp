#include "transmissor.hpp"

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

#define TIPO_CONTROLE_ERRO 2

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
vector<int> generateHammingCode(vector<int> msgBits, int m, int r);
vector<int> findHammingCode(vector<int>& msgBit);
string vecToStr(vector<int> v);

// Le a entrada do usuario
vector<int> AplicacaoTransmissora() {

    string mensagem;
    cout << "Digite uma mensagem: " << endl;
    cin >> mensagem;

    return CamadaDeAplicacaoTransmissora(mensagem);

}

// Converte a entrada do usuario para binario
vector<int> CamadaDeAplicacaoTransmissora(string mensagem) {

    vector<int> quadro = stringToBinary(mensagem);

    return CamadaEnlaceDadosTransmissora(quadro);

}

// Adiciona bits para controle de erros
vector<int> CamadaEnlaceDadosTransmissora(vector<int> &quadro) {

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

    vector<int> hammingTable = findHammingCode(quadro);

    for (vector<int>::const_iterator i = quadro.begin(); i != quadro.end(); ++i)
        cout << *i << ' ';
    cout << endl;

    for (vector<int>::const_iterator i = hammingTable.begin(); i != hammingTable.end(); ++i)
        cout << *i << ' ';
    cout << endl;

    quadro = hammingTable;

}

// Adiciona o metodo de paridade impar para controle de erros
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(vector<int> &quadro) {

    vector<int> hammingTable = findHammingCode(quadro);

    quadro = hammingTable;

}

// Adiciona o metodo CRC para controle de erros
void CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int> &quadro) {

    

}

// Converte caracteres para binario
vector<int> stringToBinary(string words) {

    string binaryString = "";
    
    for (char& _char : words) {

        binaryString += bitset<8>(_char).to_string();
    
    }

    int stringLength = binaryString.length();
    vector<int> binaryData;

    int i = 0;
    for(i=0; i < stringLength; i++) {

        binaryData.push_back( binaryString[i] == '1' );

    }

    return binaryData;

}

// https://www.geeksforgeeks.org/hamming-code-implementation-in-c-cpp/

// Function to generate hamming code
vector<int> generateHammingCode(vector<int> msgBits, int m, int r) {

    // Stores the Hamming Code
    vector<int> hammingCode(r + m);
 
    // Find positions of redundant bits
    for (int i = 0; i < r; ++i) {
 
        // Placing -1 at redundant bits
        // place to identify it later
        hammingCode[pow(2, i) - 1] = -1;

    }
 
    int j = 0;
 
    // Iterate to update the code
    for (int i = 0; i < (r + m); i++) {
 
        // Placing msgBits where -1 is
        // absent i.e., except redundant
        // bits all positions are msgBits
        if (hammingCode[i] != -1) {

            hammingCode[i] = msgBits[j];
            j++;

        }

    }
 
    for (int i = 0; i < (r + m); i++) {
 
        // If current bit is not redundant
        // bit then continue
        if (hammingCode[i] != -1)
            continue;
 
        int x = log2(i + 1);
        int one_count = 0;
 
        // Find msg bits containing
        // set bit at x'th position
        for (int j = i + 2; j <= (r + m); ++j) {
 
            if (j & (1 << x)) {
                if (hammingCode[j - 1] == 1) {
                    one_count++;
                }
            }
            
        }
 
        // Generating hamming code for
        // even parity
        if (one_count % 2 == 0) {

            hammingCode[i] = 0;

        } else {

            hammingCode[i] = 1;

        }
        
    }
 
    // Return the generated code
    return hammingCode;

}
 
// Function to find the hamming code
// of the given message bit msgBit[]
vector<int> findHammingCode(vector<int>& msgBit) {
 
    // Message bit size
    int m = msgBit.size();
 
    // r is the number of redundant bits
    int r = 1;
 
    // Find no. of redundant bits
    while (pow(2, r) < (m + r + 1)) {

        r++;

    }
 
    // Generating Code
    vector<int> hammingCode = generateHammingCode(msgBit, m, r);
 
    return hammingCode;

}

string vecToStr(vector<int> v){
    string str;
    for(int x: v){
        str.push_back((char) x + 48);
    }

    return str;
}