#include "ponto.h"
#include <math.h>

float calcularDistancia(Ponto ponto1, Ponto ponto2) {
    return sqrt(pow(ponto2.X - ponto1.X, 2) + pow(ponto2.Y - ponto1.Y, 2));
}
