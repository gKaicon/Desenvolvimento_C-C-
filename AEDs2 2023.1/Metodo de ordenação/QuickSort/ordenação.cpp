#include <iostream>
#include <windows.h>
#include <time.h>
#include <vector>
#include <chrono>


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

void QuickSortInt(int esquerda, int direita, unsigned long long *comparacao, unsigned long long *trocas)
{

    int aux, i = esquerda, j = direita;
    int pivo = vI[(esquerda + direita) / 2];

    while (i <= j)
    {
        while (vI[i] < pivo)
            i++;
        while (vI[j] > pivo)
            j--;
        (*comparacao)++;
        if (i <= j)
        {
            aux = vI[i];
            vI[i] = vI[j];
            vI[j] = aux;
            i++;
            j--;
            (*trocas)++;
        }
    }

    (*comparacao)++;
    if (esquerda < j)
        QuickSortInt(esquerda, j, comparacao, trocas);
    (*comparacao)++;
    if (i < direita)
        QuickSortInt(i, direita, comparacao, trocas);
}

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    unsigned long long comp = 0, troca = 0;
    preencheVetor(10);
    imprimeVetor();
    QuickSortInt(0, vI.size() - 1, &comp, &troca);
    imprimeVetor();

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl << endl << "Tempo de Execução: " << tempo.count() << " segundos" << endl;
    return 0;
}