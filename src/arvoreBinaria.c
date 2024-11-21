#include "arvoreBinaria.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "livro.h"

No *inicializar_arvore() { return NULL; }

void inserir_livro(No *raiz, Livro* livro) {
    if (raiz == NULL) {
        printf("\nInserindo livro");
        raiz = (No *)malloc(sizeof(No));
        raiz->livro = livro;
        raiz->key = livro->codigo;
        raiz->left = NULL;
        raiz->right = NULL;
    } else if (livro->codigo < raiz->livro->codigo) {
        printf("\nInserindo na esquerda");
        inserir_livro(raiz->left, livro);
    } else {
        printf("\nInserindo na direita");
        inserir_livro(raiz->right, livro);
    }
}

void buscar_por_genero(No *raiz, char genero[]) {}

No *carregar_livros(char *nome_arquivo, No *raiz) {
    FILE *arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return raiz;
    }

    char linha[512];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Livro* livro;
        // Parse a linha do CSV
        sscanf(linha, "%d;%99[^,];%99[^,];%99[^,];%d;%99[^,];%d",
               livro->codigo, livro->titulo, livro->autor, livro->genero,
               livro->ano, livro->editora, livro->numPag);
        // Inserir o livro na árvore
        inserir_livro(raiz, livro);
    }

    fclose(arquivo);
    return raiz;
}

void exibir_arvore(No *raiz) {
    if (raiz != NULL) {
        printf("\nMostrando árvore:");
        mostrarLivro(raiz->livro);
        exibir_arvore(raiz->left);
        exibir_arvore(raiz->right);
    }
}

void liberar_arvore(No *raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->left);
        liberar_arvore(raiz->right);
        free(raiz->livro);
        free(raiz);
    }
}
