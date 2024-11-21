#include "livro.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Livro* newlivro(int codigo, char titulo[], char autor[], char genero[], int ano, char editora[], int numPag) {
    Livro* book = (Livro*)malloc(sizeof(Livro));

    book->codigo = codigo;
    strcpy(book->titulo, titulo);
    strcpy(book->autor, autor);
    strcpy(book->genero, genero);
    book->ano = ano;
    strcpy(book->editora, editora);
    book->numPag = numPag;

    return book;
}

void mostrarLivro(Livro* livro) {
    if (livro == NULL)
        printf("Dados vazios...");
    else {
        printf("\nDados:\n");
        printf("Nome: %s\nCodigo: %d\nAutor: %s\nGenero: %s\nAno: %d\nEditora: %s\nN. Pag: %d\n", livro->titulo, livro->codigo, livro->autor, livro->genero, livro->ano, livro->editora, livro->numPag);
    }
}
