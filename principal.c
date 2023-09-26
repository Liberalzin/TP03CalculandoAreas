#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

double calcularArea(int n, Ponto *vertices) {
    double area = 0.0;
    int j;

    for (int i = 0; i < n; i++) {
        j = (i + 1) % n;
        area += (vertices[i].X * vertices[j].Y) - (vertices[j].X * vertices[i].Y);
    }

    return 0.5 * fabs(area);
}

int main() {
    FILE *arquivo;
    int n;

    arquivo = fopen("vertices.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    fscanf(arquivo, "%d", &n);


    Ponto *vertices = (Ponto *)malloc(n * sizeof(Ponto));

    for (int i = 0; i < n; i++) {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(arquivo);

    double area = calcularArea(n, vertices);

    printf("Area: %.2lf\n", area);

    free(vertices);

    return 0;
}
