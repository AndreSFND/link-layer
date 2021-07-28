#include "./modulos/transmissor/transmissor.hpp"
#include "./modulos/receptor/receptor.hpp"
#include "./modulos/comunicacao/comunicacao.hpp"

#include <vector>

using namespace std;

int main() {

    // Le a entrada do usuario e a transforma num vetor de binarios
    vector<int> fluxoBrutoDeBitsPontoA = AplicacaoTransmissora();

    // Simula o fluxo dos dados de um ponto A ate um ponto B
    vector<int> fluxoBrutoDeBitsPontoB = MeioDeComunicacao(fluxoBrutoDeBitsPontoA);
    
    // Le os dados binarios e os transforma de volta numa mensagem
    CamadaEnlaceDadosReceptora(fluxoBrutoDeBitsPontoB);

    return 0;

}