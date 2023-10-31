#include <stdio.h>
#include <stdlib.h>

// Função de comparação para o quicksort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int S, *Q, *N, i, counter = 0;

    scanf("%d", &S);

    Q = malloc(S * sizeof(int));
    N = malloc(S * sizeof(int));

    for (i = 0; i < S; i++) {
        scanf("%d", &Q[i]);
    }
    for (i = 0; i < S; i++) {
        scanf("%d", &N[i]);
    }

    // Ordenar os arrays de habilidades de combate
    qsort(Q, S, sizeof(int), compare);
    qsort(N, S, sizeof(int), compare);

    // Comparar as habilidades de combate para determinar o número máximo de vitórias
    int j = 0;
    for (i = 0; i < S && j < S; i++) {
        while (j < S && N[j] <= Q[i]) {
            j++;
        }
        if (j < S) {
            counter++;
            j++;
        }
    }

    printf("%d\n", counter);

    free(Q);
    free(N);

    return 0;
}