#include <stdio.h>


#ifndef LIVRO_H
#define LIVRO_H

typedef struct livro
{
    int codigo;
    char titulo[100];
    char autor[100];
    char genero[100];
    int ano;
    char editora[100];
    int numPag;

} Livro;

Livro* newlivro(int codigo, char titulo[], char autor[], char genero[], int ano, char editora[], int numPag);
void mostrarLivro(Livro* livro);

#endif