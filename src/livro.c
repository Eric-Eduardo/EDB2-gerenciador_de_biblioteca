#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

Livro* newbook(int codigo, char titulo[], char autor[], char genero[], int ano, char editora[], int numPag) {
    Livro* book = (Livro*) malloc(sizeof(Livro));

    book->codigo = codigo;
    strcpy(book->titulo, titulo);
    strcpy(book->autor, autor);
    strcpy(book->genero, genero);
    book->ano = ano;
    strcpy(book->editora, editora);
    book->numPag = numPag;

    return book;
}