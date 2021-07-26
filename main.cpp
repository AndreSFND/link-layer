#include <iostream>
#include <string>

using namespace std;

void AplicacaoTransmissora();
void CamadaDeAplicacaoTransmissora(string mensagem);
void CamadaEnlace(int quadro[]);

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

void CamadaDeAplicacaoTransmissora(string mensagem) {

    //int quadro [] = mensagem;
    //CamadaEnlaceDadosTransmissora(quadro);

}

void CamadaEnlaceDadosTransmissora(int quadro[]) {

    CamadaEnlaceDadosTransmissoraControleDeErro(quadro);

}

void CamadaEnlaceDadosTransmissoraControleDeErro(int quadro[]) {

    int tipoDeControleDeErro = 0;

    switch( tipoDeControleDeErro ) {

        case 0:
        break;

        case 1:
        break;

        case 2:
        break;

    }

}

void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(int quadro[]) {
}
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(int quadro[]) {
}
void CamadaEnlaceDadosTransmissoraControleDeErroCRC(int quadro[]) {
}

void MeioDeComunicacao(int fluxoBrutoDeBits[]) {

    int erro, porcentagemDeErros;
    int fluxoBrutoDeBitsPontoA [], fluxoBrutoDeBitsPontoB [];

    porcentagemDeErros = 0;
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

    while( fluxoBrutoDeBitsPontoA.length != fluxoBrutoDeBitsPontoB.length ) {

        if( (rand() % 100) == ? ) {

            fluxoBrutoDeBitsPontoB += fluxoBrutoDeBitsPontoA;

        } else {

            fluxoBrutoDeBitsPontoA = fluxoBrutoDeBitsPontoB == 0 ? fluxoBrutoDeBitsPontoB++ : fluxoBrutoDeBitsPontoB--;

        }

    }

    CamadaEnlaceDadosReceptora(fluxoBrutoDeBitsPontoB);

}

void CamadaEnlaceDadosReceptora(int quadro[]) {



}

void CamadaDeAplicacaoReceptora(int quadro[]) {

    //string mensagem = quadro[];
    //AplicacaoReceptora(mensagem);

}

void AplicacaoReceptora(string mensagem) {

    cout << "A mensagem recebida foi: " << mensagem << endl;

}