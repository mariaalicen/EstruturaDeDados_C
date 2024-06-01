#include <stdio.h>

struct no {
    char letra;
    int filhos[3];
};

struct no exemplo1[15];

void exibir(struct no exemplo1[15]) {
    for (int i = 0; i < 8; i++) {
        printf("\n pai: %c \n", exemplo1[i].letra);
        for (int j = 0; j < 3; j++) {
            printf("filho %d: %d - ", j, exemplo1[i].filhos[j]);
        }
    }
}

void inserir(struct no exemplo1[15]) {
    exemplo1[0].letra = 'A';
    exemplo1[0].filhos[0] = 1;
    exemplo1[1].letra = 'B';
    exemplo1[1].filhos[0] = 5;
    exemplo1[2].letra = 'C';
    exemplo1[3].letra = 'D';
    exemplo1[4].letra = 'E';
    exemplo1[5].letra = 'F';
    exemplo1[6].letra = 'G';
    exemplo1[7].letra = 'H'; 
}

void inserirInoE(struct no exemplo1[15]){
    exemplo1[8].letra = 'I';
    exemplo1[4].filhos[0] = 2; 
}

void inserirJnoG(struct no exemplo1[15]){
    exemplo1[9].letra = 'J';
    exemplo1[6].filhos[0] = 3; 
}

void remover(struct no exemplo1[15], int indice) {
    exemplo1[indice].letra = '\0';
    for (int j = 0; j < 3; j++) {
        exemplo1[indice].filhos[j] = -1;
    }
}

void buscaProfundidade(struct no exemplo1[15], int indice) {
    if (indice >= 0 && indice < 15 && exemplo1[indice].letra != '\0') {
        printf("%c ", exemplo1[indice].letra);

        for (int i = 0; i < 3; i++) {
            if (exemplo1[indice].filhos[i] != -1) {
                buscaProfundidade(exemplo1, exemplo1[indice].filhos[i]);
            }
        }
    }
}

int main() {
    for (int i = 0; i < 15; i++) {
        exemplo1[i].letra = '\0'; // Nós vazios
        for (int j = 0; j < 3; j++) {
            exemplo1[i].filhos[j] = -1; // Filhos vazios
        }
    }

    inserir(exemplo1);
    exibir(exemplo1);
    buscaProfundidade(exemplo1, 0); // Começa a busca a partir do nó raiz
    inserirInoE(exemplo1);
    inserirJnoG(exemplo1);
    exibir(exemplo1);
    remover(exemplo1, 7); 
    remover(exemplo1, 3); 
    
    return 0;
}
