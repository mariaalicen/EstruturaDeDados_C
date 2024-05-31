#include <stdio.h>

struct no {
    char letra;
    int filhos[3];
};

void exibir(struct no exemplo1[8]) {
    for (int i = 0; i < 8; i++) {
        printf("\n pai: %c \n", exemplo1[i].letra);
        for (int j = 0; j < 3; j++) {
            printf("filho %d: %d - ", j, exemplo1[i].filhos[j]);
        }
    }
}

void inserir(struct no exemplo1[8]) {
    exemplo1[0].letra = 'A';
    exemplo1[0].filhos[0] = 1;
    exemplo1[1].letra = 'B';
    exemplo1[2].letra = 'C';
}

void buscaProfundidade(struct no exemplo1[8], int indice) {
    if (indice >= 0 && indice < 8 && exemplo1[indice].letra != '\0') {
        printf("%c ", exemplo1[indice].letra);

        for (int i = 0; i < 3; i++) {
            if (exemplo1[indice].filhos[i] != -1) {
                buscaProfundidade(exemplo1, exemplo1[indice].filhos[i]);
            }
        }
    }
}

int main() {
    struct no exemplo1[8];

    for (int i = 0; i < 8; i++) {
        exemplo1[i].letra = '\0'; // Nós vazios
        for (int j = 0; j < 3; j++) {
            exemplo1[i].filhos[j] = -1; // Filhos vazios
        }
    }

    inserir(exemplo1);
    exibir(exemplo1);

    printf("\n\n --------- Busca em Profundidade ---------------\n\n");
    buscaProfundidade(exemplo1, 0); // Começa a busca a partir do nó raiz

    return 0;
}
