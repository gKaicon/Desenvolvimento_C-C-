#include <iostream>
#include <windows.h>
#include <string>

using namespace std;
//Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo algoritmo
//Bubble Sort.

void BubbleSortCrescente(string &palavra){
    bool troca;
    char aux; //string é um vetor de caracteres
    int i, j;
    for (i = 0; i < palavra.length() - 1; i++){
        troca = false;
        for (j = 1; j < palavra.length() - i; j++){
            if (palavra[j] < palavra[j - 1]){
                aux = palavra[j];
                palavra[j] = palavra[j - 1];
                palavra[j - 1] = aux;
                troca = true;
            } 
        }
        if (troca == false) break;
    }
}

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    string p;

    cout << "Digite uma palavra: ";
    getline(cin, p);

    BubbleSortCrescente(p);

    cout << "Palavra ordenado: " << p << endl;

    return 0;
}

