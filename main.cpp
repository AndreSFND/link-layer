#include "./modulos/transmissor/transmissor.hpp"
#include "./modulos/receptor/receptor.hpp"
#include "./modulos/comunicacao/comunicacao.hpp"

#include <vector>

using namespace std;

int main() {

    vector<int> fluxoBrutoDeBitsPontoA = AplicacaoTransmissora();
    vector<int> fluxoBrutoDeBitsPontoB = MeioDeComunicacao(fluxoBrutoDeBitsPontoA);
    CamadaEnlaceDadosReceptora(fluxoBrutoDeBitsPontoB);

    return 0;

}