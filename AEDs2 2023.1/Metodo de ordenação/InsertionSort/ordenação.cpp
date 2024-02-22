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


void InsertionSortInt(unsigned long long *comparacao, unsigned long long *trocas){
    int aux;
    for (int i = 1; i < vI.size(); i++){
        aux = vI[i];
        for (int j = i; ((j > 0) && (aux < vI[j - 1])); j--){
            comparacao++; //Comparação feita no for
            vI[j] = vI[j - 1];
            vI[j - 1] = aux;
            trocas++;
        }
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
    InsertionSortInt(&comparacao, &trocas);
    imprimeVetor();

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl
         << endl
         << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}