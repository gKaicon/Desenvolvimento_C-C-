#ifndef GRAFO_MATRIZ_ADJACENCIA
#define GRAFO_MATRIZ_ADJACENCIA

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <cstring>
#include <fstream>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;
using namespace chrono;

string stipoGrafo;
boolean tipoGrafo;
int qtdVertice = 0;
int qtdAresta = 0;

struct vertice{
    string conteudo;
    int *ligacao;
    int ant;
    char situacaoCor;
    int tempoDescoberta;
    int tempoFinalizacao;
    unsigned long long distOrigem;
};

vertice *listaAdjVertice;
double **matrizCoordenadaVertice;

void exportarGrafo();
void importarGrafo();
void menu();
void menuCriaGrafo();
void criaGrafoMatrizCoord(int num);
void criarMatrizVerticeBuscas(int num);
void mostraGrafoVertice();
void mostraGrafoCoordenada();
bool consultarSeAdjacente(int verticeInicial, int verticeFinal);
void insereArestaGrafo();
void removeAresta(int verticeInicial, int verticeFinal);
void editarCoordenadasVertices(int vertice, int x, int y);
int consultarPrimeiroAdjacente(int vertice);
int proximoAdjacente(int vertice, int partida);
void listaCompletaDoVerticeAdjacentes(int vertice);
void reiniciaGrafo();
int retornaIndice(string nome);
string retornaNome(int vertice);
void editaConteudoVertice();
void mostraInformacaoVertice(int vertice);
void visitaParaBuscaProfundidade(int vertice, int *tempoDescoberta);
void visitaBuscaProfundidadeRemanescente(int *tempoDescoberta);
void buscalargura(int verticeOrigem, int *dist);
void visitaBuscaLarguraRemanescente();
vector<pair<int, vector<int>>> dijkstraMenorCaminho(int verticeOrigem, int verticeDestino);
void imprimirMenoresCaminhos(int verticeOrigem, const vector<pair<int, vector<int>>> &resultados);
void kruskal();

#endif