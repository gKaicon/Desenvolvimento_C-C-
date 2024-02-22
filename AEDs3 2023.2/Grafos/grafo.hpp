#ifndef GRAFO_MATRIZ_ADJACENCIA
#define GRAFO_MATRIZ_ADJACENCIA

#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;
using namespace chrono;

string stipoGrafo;
boolean tipoGrafo;
int **matrizCoordenadaVertice;
int **matrizArestasVertice;
int qtdVertice = 0;
int qtdAresta = 0;

void menu();
void criarMatrizVertice(int num);
void criaGrafoMatrizCoord(int num);
void mostraGrafoVertice();
void mostraGrafoCoordenada();
bool consultarSeAdjacente(int verticeInicial, int verticeFinal);
void insereAresta(int verticeInicial, int verticeFinal, int peso);
void removeAresta(int verticeInicial, int verticeFinal);
void editarCoordenadasVertices(int vertice, int x, int y);
void consultarPrimeiroAdjacente(int vertice);
void proximoAdjacente(int vertice, int partida);
void listaCompletaDoVerticeAdjacentes(int vertice);
void exportar();
void importarGrafo();

#endif