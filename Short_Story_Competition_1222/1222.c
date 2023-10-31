#include <stdio.h>
#include <string.h>

#define MAXSIZE 70

void main () {

	int i, l, c, n, x;
	int linhas, paginas, letras;
	char palavra[MAXSIZE + 1];

	while (scanf("%d %d %d", &n, &l, &c) != EOF) {
    	paginas = linhas = 1; //Reseta o texto
    	scanf("%s", palavra);
    	letras = strlen(palavra);

		n--;
		for (i = 0; i < n; ++i)	{

			scanf("%s", palavra);

			x = strlen(palavra);
			// Testa se é possível adicionar a palavra lida na mesma linha de antes
			if ((letras + x + 1) <= c)
				letras += x + 1;
			else { //Precisou de outra linha
				++linhas;
				if (linhas > l) //Precisou de outra página
					++paginas, linhas = 1; //Página++, Reset do numero de linhas

				letras = x;

			}

		}

		printf("%d\n", paginas);

	}

}