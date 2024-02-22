#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

vector<int> vI;

void preencheVetor(int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vI.push_back(rand() % 99);
    }
}

void imprimeVetor()
{
    for (int i = 0; i < vI.size() - 1; i++)
    {
        cout << vI[i] << "\t";
    }
    cout << endl
         << endl;
}


void SelectionSortInt(unsigned long long *comparacao,unsigned long long *trocas){
    int min, aux;

    for (int i = 0; i < vI.size() - 1; i++){
        min = i;
        for (int j = i + 1; j < vI.size(); j++){
            comparacao++;
            if (vI[j] < vI[min]) min = j;
        }
        aux = vI[i];
        vI[i] = vI[min];
        vI[min] = aux;
        trocas++;
    }
}

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    unsigned long long comparacao = 0, trocas = 0;
    preencheVetor(10);
    imprimeVetor();
    SelectionSortInt(&comparacao, &trocas);
    imprimeVetor();

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl
         << endl
         << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}