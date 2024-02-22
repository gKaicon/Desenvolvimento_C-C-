#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;
//Implemente um programa que leia n nomes e ordene-os pelo tamanho utilizando o Selection Sort.
//No final, o algoritmo deve mostrar todos os nomes ordenados.

vector<string>vetNomes;

void SelectionSortString()
{
    int min, i, j;
    string aux;
    for (i = 0; i < vetNomes.size(); i++)
    {
        min = i;

        for (j = i + 1; j < vetNomes.size(); j++)
        {
            if (vetNomes[j].size() < vetNomes[min].size())//pega uma palavra(que é um vetor) dentro do vetor, e compara os tamanho
            {
                min = j;
            }
        }
        aux = vetNomes[i];
        vetNomes[i] = vetNomes[min];
        vetNomes[min] = aux;
    }
}

int main()
{

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    string nome;
    int op;
    do{
        cout << "Digite um nome: ";
        cin >> nome;
        vetNomes.push_back(nome);
        cout << endl << "Deseja inserir mais um nome?\n0 - não\n1 - sim\nOpção: ";
        cin >> op;
    }while(op != 0);

    SelectionSortString();

    cout << "\nNomes ordenados!" << endl;
    for (int i = 0; i < vetNomes.size(); i++) cout << vetNomes[i] << "\t\t";
        
    return 0;
}
