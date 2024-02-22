#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void funcao_a(int v[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++) // começa da segunda posição
    {
        x = v[i];                  // guarda o valor da segunda posição
        j = i - 1;                 // na primeira execução, o j é a primeira posição
        while (j >= 0 && v[j] > x) // enquanto j for maior que a posoção anterior
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }

    cout << endl << "Vetor da função A, ordenado: \n" << endl;
    for (i = 0; i < n; i++)
        cout << v[i] << "\t";
    cout << endl;
    
}

void funcao_b(int v[], int n)
{ // não tem min no insertion aqui, logo selection
    int i, j, aux, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
        cout << endl;
        for (i = 0; i < n; i++)
            cout << v[i] << "\t";
        cout << endl;
    }
    cout << "Vetor da função B, ordenado: \n" << endl;
    for (i = 0; i < n; i++)
        cout << v[i] << "\t";
    cout << endl;
}

void funcao_c(int v[], int n)
{ // insertion
    int i, j, aux;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cout << endl;
                for (i = 0; i < n; i++)
                    cout << v[i] << "\t";
                cout << endl;
            }
        }
    }
    cout << "Vetor da função C, ordenado: \n" << endl;
    for (i = 0; i < n; i++)
        cout << v[i] << "\t";
    cout << endl;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    int vb[10] = {7, 8, 1, 5, 2, 3, 9, 10, 4, 0};
    int vS[10] = {7, 8, 1, 5, 2, 3, 9, 10, 4, 0};
    int vI[10] = {7, 8, 1, 5, 2, 3, 9, 10, 4, 0};

    cout << endl;
    funcao_a(vb, 10); //bubble
    funcao_b(vS, 10); //selection
    funcao_c(vI, 10); //insertion
    cout << endl;
    return 0;
}
