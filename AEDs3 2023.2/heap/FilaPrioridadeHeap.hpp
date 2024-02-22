#ifndef FILAPRIORIDADEHEAP_H
#define FILAPRIORIDADEHEAP_H

#include <iostream>
#include <cstring>
#include <windows.h>

const int MAX = 100;

using namespace std;
typedef struct paciente {
    char nome[30];
    int prio;
};
typedef struct fila_prioridade {
    int qtd;
    struct paciente dados[MAX];
};

typedef fila_prioridade FilaPrio;

FilaPrio* cria_FilaPrio();
void libera_FilaPrio(FilaPrio* fp);
int consulta_FilaPrio(FilaPrio* fp, char* nome);
int insere_FilaPrio(FilaPrio* fp, char* nome, int prioridade);
int remove_FilaPrio(FilaPrio* fp);
int tamanho_FilaPrio(FilaPrio* fp);
int estaCheia_FilaPrio(FilaPrio* fp);
int estaVazia_FilaPrio(FilaPrio* fp);
void imprime_FilaPrio(FilaPrio* fp);

#endif