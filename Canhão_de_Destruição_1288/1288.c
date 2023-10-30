#include <stdio.h>

int main() {
    int ans[55][105];
    int n;
    int m;
    int dano;
    int peso;
    int res;
    int cases;
    
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            ans[i][0] = 0;
        for (int i = 0; i <= 100; i++)
            ans[0][i] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &dano, &peso);
            for (int j = 1; j <= 101; j++) {
                if (j < peso)
                    ans[i][j] = ans[i - 1][j];
                else
                    ans[i][j] = (ans[i - 1][j] > ans[i - 1][j - peso] + dano) ? ans[i - 1][j] : ans[i - 1][j - peso] + dano;
            }
        }
        scanf("%d %d", &m, &res);
        if (ans[n][m] >= res)
            printf("Missao completada com sucesso\n");
        else
            printf("Falha na missao\n");
    }
    return 0;
}
