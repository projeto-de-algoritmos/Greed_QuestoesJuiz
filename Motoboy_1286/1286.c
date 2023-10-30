#include <stdio.h>
#include <stdlib.h>

#define MAXN 1010
#define MAXS 40

long long int n, s, peso[MAXN], valor[MAXN];
long long int tab[MAXN][MAXS];

long long int knapsack() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (i == 0 || j == 0) {
                tab[i][j] = 0;
            } else if (peso[i] <= j) {
                tab[i][j] = (valor[i] + tab[i - 1][j - peso[i]] > tab[i - 1][j]) ? valor[i] + tab[i - 1][j - peso[i]] : tab[i - 1][j];
            } else {
                tab[i][j] = tab[i - 1][j];
            }
        }
    }
    return tab[n][s];
}

int main() {
    while (1) {
        scanf("%lld", &n);
        if (n == 0) break;

        scanf("%lld", &s);

        for (long long int i = 1; i <= n; i++) {
            scanf("%lld %lld", &valor[i], &peso[i]);
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= s; j++) {
                tab[i][j] = -1;
            }
        }

        printf("%lld min.\n", knapsack());
    }

    return 0;
}
