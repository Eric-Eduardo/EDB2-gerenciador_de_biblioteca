#include "arvoreBinaria.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "livro.h"

No *inicializar_arvore() {
    return NULL;
}

void inserir_livro(No **raiz, Livro *livro) {
    if (*raiz == NULL) {
        // Livro* livro = newlivro(livro_.codigo, livro_.titulo, livro_.autor, livro_.genero, livro_.ano, livro_.editora, livro_.numPag);
        // printf("\nInserindo livro de %s\n", livro->autor);
        *raiz = (No *)malloc(sizeof(No));
        (*raiz)->livro = livro;
        (*raiz)->key = livro->codigo;
        (*raiz)->left = NULL;
        (*raiz)->right = NULL;
    } else if (livro->codigo < (*raiz)->livro->codigo) {
        // printf("\nInserindo na esquerda");
        inserir_livro(&((*raiz)->left), livro);
    } else {
        // printf("\nInserindo na direita");
        inserir_livro(&((*raiz)->right), livro);
    }
}

// void inserir_livro(No **raiz, Livro livro_) {
//     if (*raiz == NULL) {
//         Livro* livro = newlivro(livro_.codigo, livro_.titulo, livro_.autor, livro_.genero, livro_.ano, livro_.editora, livro_.numPag);
//         // printf("\nInserindo livro de %s\n", livro->autor);
//         *raiz = (No *)malloc(sizeof(No));
//         (*raiz)->livro = livro;
//         (*raiz)->key = livro->codigo;
//         (*raiz)->left = NULL;
//         (*raiz)->right = NULL;
//     } else if (livro_.codigo < (*raiz)->livro->codigo) {
//         // printf("\nInserindo na esquerda");
//         inserir_livro(&((*raiz)->left), livro_);
//     } else {
//         // printf("\nInserindo na direita");
//         inserir_livro(&((*raiz)->right), livro_);
//     }
// }

/*
void buscar_por_genero(No *raiz, char genero[]) {
    if (raiz == NULL) {
        return;
    }

    if (strcmp(raiz->livro->genero, genero) == 0) {
        mostrarLivro((raiz->livro));
    }

    buscar_por_genero(raiz->left, genero);

    buscar_por_genero(raiz->right, genero);
}
*/

No *carregar_livros(char *nome_arquivo, No *raiz) {
    printf("Tentando carregar\n");

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    char linha[512];

    while(1) {
        Livro* livro = (Livro*)malloc(sizeof(Livro));


        if (fgets(linha, sizeof(linha), arquivo) == NULL) {
            break;
        }

        sscanf(linha, "%d;%99[^;];%49[^;];%29[^;];%d;%49[^;];%d",
               &(livro->codigo),
               livro->titulo,
               livro->autor,
               livro->genero,
               &(livro->ano),
               livro->editora,
               &(livro->numPag));

        // printf("Livro lido: %s\n", livro.titulo);
        inserir_livro(&raiz, livro);
    }

    fclose(arquivo);
    return raiz;
}

void exibir_arvore(No *raiz) {
    if (raiz != NULL) {
        printf("\n");
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
