#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <windows.h>
#include <string.h>
#include <string>
#include <time.h> 
#include <chrono> 

using namespace std;
using namespace chrono;

typedef struct Data
{
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
};

typedef struct Endereco
{
    string logradouro;
    int numero;
    string bairro;
    string cidade;
    string estado;
    string cep;
};

typedef struct Pessoa
{
    int matricula;
    string cpf;
    string nome;
    string cargo;
    string telefone;
    Data data_nascimento;
    Endereco endereco;
};

struct No
{
    Pessoa pessoa;
    No *esquerda;
    No *direita;
};

No *criarNo(Pessoa pessoa);
No *inserirNo(No *raiz, Pessoa pessoa);
No *removerNo(No *raiz, int matricula);
Pessoa criarPessoa();
void imprimeItem(Pessoa pessoa);
No *buscarMatricula(No *raiz, int matricula);
No *buscarCPF(No *raiz, string cpf);
No *buscarNome(No *raiz, string nome);
No *removerPorMatricula(No *raiz, int matricula);
void removeMatricula(No *raiz);
void imprimeEmOrdem(No *raiz);
void imprimePreOrdem(No *raiz);
void imprimePosOrdem(No *raiz);
void Busca(No *raiz, int op);
void imprime(No *raiz, int op);
int menubusca();
void menu() ;
int menuimprimir();

#endif