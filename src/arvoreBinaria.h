#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "livro.h"

typedef struct No {
  int key;
  Livro* livro;
  struct arv* left;
  struct arv* right;
} No;

No* inicializar_arvore();
void inserir_livro(No** raiz, Livro livro);
void buscar_por_genero(No* raiz, char genero[]);
No* carregar_livros(char* nome_arquivo, No* raiz);
void exibir_arvore(No* raiz);
void liberar_arvore(No* raiz);

#endif