#include "receptor.hpp"

#include <iostream>
#include <string>
#include <bitset>

#define TIPO_CONTROLE_ERRO 1
#define TAMANHO_PARIDADE 8

// Camadas receptoras
void CamadaEnlaceDadosReceptora(vector<int> &quadro);
void CamadaDeAplicacaoReceptora(vector<int> &quadro);
void AplicacaoReceptora(string mensagem);

// Controle de erros
void CamadaEnlaceDadosReceptoraControleDeErroBitParidade(vector<int> &quadro, int _paridade);
void CamadaEnlaceDadosReceptoraControleDeErroCRC(vector<int> &quadro);

// Utilidades
string binaryToString(vector<int> quadro);



// Trata os erros que surgiram na transmissao dos dados
void CamadaEnlaceDadosReceptora(vector<int> &quadro) {

    // Seleciona o tipo de controle de erro
    switch( TIPO_CONTROLE_ERRO ) {

        case 0:
        
            CamadaEnlaceDadosReceptoraControleDeErroBitParidade(quadro, 0);
        
        break;

        case 1:
        
            CamadaEnlaceDadosReceptoraControleDeErroBitParidade(quadro, 1);
        
        break;

        case 2:

            CamadaEnlaceDadosReceptoraControleDeErroCRC(quadro);

        break;

    }

    // Chama a proxima camada
    CamadaDeAplicacaoReceptora(quadro);

}

// Converte o fluxo binario de dados para a mensagem original
void CamadaDeAplicacaoReceptora(vector<int> &quadro) {

    // Imprime os dados finais
    cout << endl << "Dados finais:" << endl;

    int length = quadro.size();
    for( int i=0; i<length; i++ ) {

        cout << quadro[i] << ' ';

        if( (i+1) % 8 == 0 ) cout << endl;

    }

    cout << endl << endl;

    // Transforma os dados binarios numa string
    string mensagem = binaryToString(quadro);

    // Chamada a proxima camada
    AplicacaoReceptora(mensagem);

}

// Imprime a entrada vinda do ponto A
void AplicacaoReceptora(string mensagem) {

    // Imprime a mensagem final
    cout << "A mensagem recebida foi: " << mensagem << endl;

}

// Adiciona o metodo de paridade impar para controle de erros
void CamadaEnlaceDadosReceptoraControleDeErroBitParidade(vector<int> &quadro, int _paridade) {

    // Inicializa as variaveis de armazenamento das somas das linhas e colunas
    int horizontalSum = 0;
    vector<int> verticalSum(TAMANHO_PARIDADE+1);

    // Inicializa os vetores de armazenamento das linhas e colunas erradas
    vector<int> linhasErradas, colunasErradas;

    cout << "Dados após o envio:" << endl;
    int length = quadro.size();

    // Inicia a iteracao pelo vetor de dados
    for( int i=0; i<length; i++ ) {

        // Le e imprime o bit atual
        int bit = quadro[i];
        cout << bit << " ";

        // Soma o bit atual
        horizontalSum += bit;

        // Verifica se a linha esta correta
        if( (i+1) % (TAMANHO_PARIDADE+1) == 0 ) {

            if( horizontalSum % 2 == _paridade ) {
                
                // Se a soma nao esta correta, adiciona a linha ao vetor de linhas incorretas
                linhasErradas.push_back( (int)(i / (TAMANHO_PARIDADE+1)) );
            
            }

            cout << endl;

        }

        // Atualiza o vetor de soma das colunas
        verticalSum[ i%(TAMANHO_PARIDADE+1) ] += bit;

    }

    // Verifica quais colunas possuem paridade incorreta
    for( int i=0; i<(TAMANHO_PARIDADE+1); i++ ) {

        if( verticalSum[i] % 2 == _paridade ) {

            colunasErradas.push_back(i);

        }

    }

    // Imprime os dados incorretos
    cout << endl << "Linhas erradas:" << endl;
    for (vector<int>::const_iterator i = linhasErradas.begin(); i != linhasErradas.end(); ++i)
        cout << *i << ' ';
    cout << endl;

    cout << "Colunas erradas:" << endl;
    for (vector<int>::const_iterator i = colunasErradas.begin(); i != colunasErradas.end(); ++i)
        cout << *i << ' ';
    cout << endl;

    // Se ha apenas 1 bit errado, o corrige
    if( linhasErradas.size() == 1 && colunasErradas.size() == 1 ) {

        int i = linhasErradas[0];
        int j = colunasErradas[0];

        cout << "Alterando bit " << j + (i*(TAMANHO_PARIDADE+1)) << endl;
        quadro[j + (i*(TAMANHO_PARIDADE+1))] = !quadro[j + (i*(TAMANHO_PARIDADE+1))];

    } else {

        cout << endl << "Mais de um erro encontrado, nao foi possivel corrigi-los!" << endl;

    }


    vector<int> quadroFinal;

    // Retorna ao formato original dos dados
    for( int i=0; i<length-(TAMANHO_PARIDADE+1); i++ ) {

        if( (i+1) % (TAMANHO_PARIDADE+1) != 0 ) quadroFinal.push_back(quadro[i]);

    }

    quadro = quadroFinal;

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