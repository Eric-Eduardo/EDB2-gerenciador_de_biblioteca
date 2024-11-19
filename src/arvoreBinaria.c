#include "arvoreBinaria.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

No *inicializar_arvore() { return NULL; }

void inserir_livro(No **raiz, Livro livro) {
    if (*raiz == NULL) {
        *raiz = (No *)malloc(sizeof(No));
        (*raiz)->livro = &livro;
        (*raiz)->left = NULL;
        (*raiz)->right = NULL;
    } else if (livro.codigo < (*raiz)->livro->codigo) {
        inserir_livro(((*raiz)->left), livro);
    } else {
        inserir_livro(((*raiz)->right), livro);
    }
}

void buscar_por_genero(No *raiz, char genero[]) {}

No *carregar_livros(char *nome_arquivo, No *raiz) { return NULL; }

void exibir_arvore(No *raiz) {}

void liberar_arvore(No *raiz) {}
