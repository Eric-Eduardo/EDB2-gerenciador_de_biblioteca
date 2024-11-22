#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "arvoreBinaria.h"
#include "livro.h"

int main() {
    No* raiz = inicializar_arvore();

    Livro* livro = newlivro(9864,"Era uma vez","Emily Brontë","Romance",1847,"Penguin Classics",400);

    inserir_livro(&raiz, livro);

    carregar_livros("dados.csv", raiz);


    printf("==================\nDADOS ARMAZENADOS\n==================\n");
    exibir_arvore(raiz);

    
    printf("==================\nROMANCES\n==================\n");
    buscar_por_genero(raiz, "Romance");

    liberar_arvore(raiz);
    
    return 0;
}