#include <stdio.h>
#include <stdlib.h>

#include "arvoreBinaria.h"
#include "livro.h"

int main() {
    No* raiz = inicializar_arvore();
    if (raiz == NULL) {
        printf("Arvore inicializada com sucesso (vazia).\n");
    }

    Livro livro1;
    livro1.codigo = 10;
    strcpy(livro1.titulo, "O Senhor dos Anéis");  // Use strcpy to copy strings
    strcpy(livro1.autor, "J.R.R. Tolkien");
    strcpy(livro1.genero, "Fantasia");
    livro1.ano = 1954;
    strcpy(livro1.editora, "Martins Fontes");
    livro1.numPag = 1178;

    inserir_livro(&raiz, livro1);

    printf("Livro inserido com sucesso!\n");
    return 0;
}