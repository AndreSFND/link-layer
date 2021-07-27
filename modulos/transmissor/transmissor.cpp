#include "transmissor.hpp"

#include <iostream>
#include <string>
#include <bitset>

// Camadas transmissoras
vector<int> AplicacaoTransmissora();
vector<int> CamadaDeAplicacaoTransmissora(string mensagem);
vector<int> CamadaEnlaceDadosTransmissora(vector<int> &quadro);

// Controle de erros
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(vector<int> &quadro);
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(vector<int> &quadro);
void CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int> &quadro);

// Utilidades
string TextToBinaryString(string words);



// Le a entrada do usuario
vector<int> AplicacaoTransmissora() {

    string mensagem;
    cout << "Digite uma mensagem: " << endl;
    cin >> mensagem;

    return CamadaDeAplicacaoTransmissora(mensagem);

}

// Converte a entrada do usuario para binario
vector<int> CamadaDeAplicacaoTransmissora(string mensagem) {

    string binaryString = TextToBinaryString(mensagem);

    int stringLength = binaryString.length();
    vector<int> quadro;

    int i = 0;
    for(i=0; i < stringLength; i++) {

        quadro.push_back( binaryString[i] == '1' );

    }

    return CamadaEnlaceDadosTransmissora(quadro);

}

// Adiciona bits para controle de erros
vector<int> CamadaEnlaceDadosTransmissora(vector<int> &quadro) {

    int tipoDeControleDeErro = 0;

    switch( tipoDeControleDeErro ) {

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

    //

}

// Adiciona o metodo de paridade impar para controle de erros
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(vector<int> &quadro) {

    //

}

// Adiciona o metodo CRC para controle de erros
void CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int> &quadro) {

    //

}

// Converte caracteres para binario
string TextToBinaryString(string words) {

    string binaryString = "";
    
    for (char& _char : words) {
        binaryString +=bitset<8>(_char).to_string();
    }
    
    return binaryString;

}