#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <windows.h>
#include <chrono>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;
using namespace chrono;

vector<int> vI;
vector<string> vS;
ifstream arquivo;
string nomeArquivo;

int menuFuncoesOrdenacao();
void menuStringInt();
int menuString();
int menuInt();
bool lerArquivoS(int op);
bool lerArquivoI(int op);
void imprimeVetS();
void imprimeVetI();
void BubbleSortInt();
void QuickSortInt(int esquerda, int direita, unsigned long long *comparacao, unsigned long long *trocas);
void usaQuickInt();
void ShellSortInt();
void SelectionSortInt();
void InsertionSortInt();
void IntercalaInt(int inicio, int meio, int fim, unsigned long long *comparacao, unsigned long long *trocas);
void MergeSortInt(int inicio, int fim, unsigned long long *comparacao, unsigned long long *trocas);
void usaMergeInt();
void BubbleSortString();
void QuickSortString(int esquerda, int direita, unsigned long long *comparacao, unsigned long long *trocas);
void usaQuickString();
void ShellSortString();
void SelectionSortString();
void InsertionSortString();
void IntercalaString(int inicio, int meio, int fim, unsigned long long *comparacao, unsigned long long *trocas);
void MergeSortString(int inicio, int fim, unsigned long long *comparacao, unsigned long long *trocas);
void usaMergeString();

#endif