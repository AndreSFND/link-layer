#include "receptor.hpp"

#include <iostream>
#include <string>
#include <bitset>

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

    int tipoDeControleDeErro = 0;

    switch( tipoDeControleDeErro ) {

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

    //

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