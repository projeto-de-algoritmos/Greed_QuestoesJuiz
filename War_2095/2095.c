#include <stdio.h>
#include <stdlib.h>

int main() {
    int S, *Q, *N, i, j, counter = 0;
    
    scanf("%d", &S);
    
    Q = malloc(S * sizeof(int));
    N = malloc(S * sizeof(int));
    
    for (i=0; i<S; i++){
        scanf("%d", &Q[i]);
    }
    for (i=0; i<S; i++){
        scanf("%d", &N[i]);
    }
    
    for (i=0; i<S; i++){
        j=0; 
        do {
            if (N[j]> Q[i]) counter++;
            j++;
        } while (N[j]<=Q[i]);
    }
    
    printf("%d\n", counter);

    return 0;
}
