#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

void AplicacaoTransmissora();
void CamadaDeAplicacaoTransmissora(string mensagem);
void CamadaEnlaceDadosTransmissora(vector<int> &quadro);
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(vector<int> &quadro);
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(vector<int> &quadro);
void CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int> &quadro);

void CamadaDeAplicacaoReceptora(vector<int> &quadro);
void AplicacaoReceptora(string mensagem);

int main() {

    AplicacaoTransmissora();
    return 0;

}

void AplicacaoTransmissora() {

    string mensagem;
    cout << "Digite uma mensagem: " << endl;
    cin >> mensagem;

    CamadaDeAplicacaoTransmissora(mensagem);

}

string TextToBinaryString(string words) {

    string binaryString = "";
    
    for (char& _char : words) {
        binaryString +=bitset<8>(_char).to_string();
    }
    
    return binaryString;

}

void CamadaDeAplicacaoTransmissora(string mensagem) {

    string binaryString = TextToBinaryString(mensagem);

    int stringLength = binaryString.length();
    vector<int> quadro;

    int i = 0;
    for(i=0; i < stringLength; i++) {

        quadro.push_back( binaryString[i] == '1' );

    }

    CamadaEnlaceDadosTransmissora(quadro);

}

void CamadaEnlaceDadosTransmissora(vector<int> &quadro) {

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

    CamadaDeAplicacaoReceptora(quadro);

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

// void MeioDeComunicacao(int fluxoBrutoDeBits[]) {

//     int erro, porcentagemDeErros;
//     int fluxoBrutoDeBitsPontoA [], fluxoBrutoDeBitsPontoB [];

//     porcentagemDeErros = 0;
//     fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

//     while( fluxoBrutoDeBitsPontoA.length != fluxoBrutoDeBitsPontoB.length ) {

//         if( (rand() % 100) == ? ) {

//             fluxoBrutoDeBitsPontoB += fluxoBrutoDeBitsPontoA;

//         } else {

//             fluxoBrutoDeBitsPontoA = fluxoBrutoDeBitsPontoB == 0 ? fluxoBrutoDeBitsPontoB++ : fluxoBrutoDeBitsPontoB--;

//         }

//     }

//     CamadaEnlaceDadosReceptora(fluxoBrutoDeBitsPontoB);

// }

// void CamadaEnlaceDadosReceptora(vector<int> &quadro) {



// }

string binaryToString(vector<int> quadro) {

    string mensagem = "";

    int chars = quadro.size() / 8;
    for(int j=0; j<chars; j++) {

        char parsed = 0;

        for (int i = 0; i < 8; i++) {

            if (quadro[ i + (j*8) ] == 1) {

                parsed |= 1 << (7 - i);
            
            }

        }

        mensagem.append( string(1, parsed) );

    }

    return mensagem;

}

void CamadaDeAplicacaoReceptora(vector<int> &quadro) {

    string mensagem = binaryToString(quadro);
    AplicacaoReceptora(mensagem);

}

void AplicacaoReceptora(string mensagem) {

    cout << "A mensagem recebida foi: " << mensagem << endl;

}