#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "arvoreBinaria.h"
#include "livro.h"

int main() {
    No* raiz = inicializar_arvore();
    Livro* l1 = newlivro(123, "Título 1", "Autor 1", "Aventura", 2015, "Editora 1", 38);

    inserir_livro(raiz, l1);

    printf("%d", raiz->key);

    liberar_arvore(raiz);

    /*
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
    */
    return 0;
}