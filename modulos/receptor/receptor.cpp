#include "receptor.hpp"

#include <iostream>
#include <string>
#include <bitset>

void CamadaDeAplicacaoReceptora(vector<int> &quadro);
void AplicacaoReceptora(string mensagem);

void CamadaEnlaceDadosReceptora(vector<int> &quadro) {

    CamadaDeAplicacaoReceptora(quadro);

}

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