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

void IntercalaInt(int inicio, int meio, int fim, unsigned long long *comparacao, unsigned long long *trocas)
{
    int *ListaAux = (int *)malloc(sizeof(int) * (fim + 1));
    int i, j;

    for (i = inicio; i <= meio; i++)
        ListaAux[i] = vI[i];
    for (j = meio + 1; j <= fim; j++)
        ListaAux[fim + meio + 1 - j] = vI[j];

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++)
    {
        (*comparacao)++;
        if (ListaAux[i] <= ListaAux[j])
        {
            vI[k] = ListaAux[i];
            i++;
            (*trocas)++;
        }
        else
        {
            vI[k] = ListaAux[j];
            j--;
            (*trocas)++;
        }
    }
    free(ListaAux);
}

void MergeSortInt(int inicio, int fim, unsigned long long *comparacao, unsigned long long *trocas)
{
    int meio;
    if (inicio < fim)
    { // recursividade
        meio = (inicio + fim) / 2;
        MergeSortInt(inicio, meio, comparacao, trocas);
        MergeSortInt(meio + 1, fim, comparacao, trocas);
        IntercalaInt(inicio, meio, fim, comparacao, trocas);
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
    MergeSortInt(0, vI.size() - 1, &comparacao, &trocas);
    imprimeVetor();

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl
         << endl
         << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}