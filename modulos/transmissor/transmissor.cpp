#include "transmissor.hpp"

#include <iostream>
#include <string>
#include <bitset>

vector<int> CamadaDeAplicacaoTransmissora(string mensagem);
vector<int> CamadaEnlaceDadosTransmissora(vector<int> &quadro);
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(vector<int> &quadro);
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(vector<int> &quadro);
void CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int> &quadro);

vector<int> AplicacaoTransmissora() {

    string mensagem;
    cout << "Digite uma mensagem: " << endl;
    cin >> mensagem;

    return CamadaDeAplicacaoTransmissora(mensagem);

}

string TextToBinaryString(string words) {

    string binaryString = "";
    
    for (char& _char : words) {
        binaryString +=bitset<8>(_char).to_string();
    }
    
    return binaryString;

}

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


void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(vector<int> &quadro) {

    //

}

void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(vector<int> &quadro) {

    //

}

void CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int> &quadro) {

    //

}

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