#include "receptor.hpp"

#include <iostream>
#include <string>
#include <bitset>

#define TIPO_CONTROLE_ERRO 0

// Camadas receptoras
void CamadaEnlaceDadosReceptora(vector<int> &quadro);
void CamadaDeAplicacaoReceptora(vector<int> &quadro);
void AplicacaoReceptora(string mensagem);

// Controle de erros
void CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(vector<int> &quadro);
void CamadaEnlaceDadosReceptoraControleDeErroBitParidadeImpar(vector<int> &quadro);
void CamadaEnlaceDadosReceptoraControleDeErroCRC(vector<int> &quadro);

// Utilidades
string binaryToString(vector<int> quadro);



// Trata os erros que surgiram na transmissao dos dados
void CamadaEnlaceDadosReceptora(vector<int> &quadro) {

    switch( TIPO_CONTROLE_ERRO ) {

        case 0:
        
            CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(quadro);
        
        break;

        case 1:
        
            CamadaEnlaceDadosReceptoraControleDeErroBitParidadeImpar(quadro);
        
        break;

        case 2:

            CamadaEnlaceDadosReceptoraControleDeErroCRC(quadro);

        break;

    }

    CamadaDeAplicacaoReceptora(quadro);

}

// Converte o fluxo binario de dados para a mensagem original
void CamadaDeAplicacaoReceptora(vector<int> &quadro) {

    string mensagem = binaryToString(quadro);
    AplicacaoReceptora(mensagem);

}

// Imprime a entrada vinda do ponto A
void AplicacaoReceptora(string mensagem) {

    cout << "A mensagem recebida foi: " << mensagem << endl;

}

// Adiciona o metodo de paridade par para controle de erros
void CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(vector<int> &quadro) {

    // data.map((item, i) => item ? i : null ).filter( item => item != null ).reduce( (a, b) => a ^ b )

}

// Adiciona o metodo de paridade impar para controle de erros
void CamadaEnlaceDadosReceptoraControleDeErroBitParidadeImpar(vector<int> &quadro) {

    //

}

// Adiciona o metodo CRC para controle de erros
void CamadaEnlaceDadosReceptoraControleDeErroCRC(vector<int> &quadro) {

    //

}

string binaryToString(vector<int> quadro) {

    string mensagem = "";

    int chars = quadro.size() / 8;
    for(int i=0; i<chars; i++) {

        char parsed = 0;

        for (int j = 0; j<8; j++) {

            if (quadro[ j + (i*8) ] == 1) {

                parsed |= 1 << (7 - j);
            
            }

        }

        mensagem.append( string(1, parsed) );

    }

    return mensagem;

}