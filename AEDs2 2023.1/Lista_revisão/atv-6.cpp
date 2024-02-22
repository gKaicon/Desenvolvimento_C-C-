#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;
// Faca um programa que leia n nomes inserindo-os em uma lista de forma ordenada utilizando a ideia
// do Insertion Sort. No final, o programa deve mostrar todos os nomes ordenados alfabeticamente.

vector<string> vS;

void InsertionSortString()
{ // mesmo insertion que usei no trabalho prático
    string aux;
    for (int i = 1; i < vS.size()-1; i++)
    {
        aux = vS[i];
        for (int j = i; (j > 0) && (aux < vS[j - 1]); j--)
        {
            vS[j] = vS[j - 1];
            vS[j - 1] = aux;
        }
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
        vS.push_back(nome);
        cout << endl << "Deseja inserir mais um nome?\n0 - não\n1 - sim\nOpção: ";
        cin >> op;
    }while(op != 0);

    InsertionSortString();

    cout << "\nNomes ordenados!" << endl;
    for (int i = 0; i < vS.size(); i++) cout << vS[i] << "\t\t";

    return 0;
}

/*
void InsertionSortString(vector<string> &vetPalavras)
{
    string chave;
    int j;

    for (int i = 1; i < vetPalavras.size(); i++)
    {
        chave = vetPalavras[i];
        j = i - 1;

        while (j >= 0 && vetPalavras[j] > chave)
        {
            vetPalavras[j + 1] = vetPalavras[j];
            j--;
        }
        vetPalavras[j + 1] = chave;
    }
}
*/