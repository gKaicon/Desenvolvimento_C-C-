#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void imprimeVetor(int v[], int tam){
    for(int i = 0; i < tam; i++){
        cout << v[i] << "\t";
    }
    cout << endl << endl;
}

void BubbleSortCrescente(int Lista[], int tamanho){
    int aux, contTrocas = 0, comparacao = 0;
    bool troca;

    for (int i = 0; i < tamanho - 1; i++){
        troca = false;
        for (int j = 1; j < tamanho - i; j++){
            comparacao++;
            if (Lista[j] < Lista[j - 1]){
                aux = Lista[j];
                Lista[j] = Lista[j - 1];
                Lista[j - 1] = aux;
                troca = true;
                contTrocas++;
            }
        }
        if(troca == false){
            break;
        }
    }
    imprimeVetor(Lista, tamanho);
    cout << "Trocas:" << contTrocas << endl;
    cout << "Comparacoes:" << comparacao << endl;
}

void BubbleSortDecrescente(int Lista[], int tamanho){

    int aux, contTrocas = 0;
    bool troca;

    for (int i = 0; i < tamanho - 1; i++){
        troca = false;
        for (int j = 1; j < tamanho - i; j++){
            if (Lista[j] > Lista[j - 1]){
                aux = Lista[j];
                Lista[j] = Lista[j - 1];
                Lista[j - 1] = aux;
                troca = true;
                contTrocas++;
            }
        }
        if(troca == false){
            break;
        }
    }
    imprimeVetor(Lista, tamanho);
    cout << "Trocas:" << contTrocas << endl;
}

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    int idades[4] = {20, 14, 5, 2};
    cout << "Vetor Normal" << endl;
    imprimeVetor(idades, 4);
    cout << endl << "Vetor Ordenado Crescente" << endl;
    BubbleSortCrescente(idades, 4);
    cout << endl << "Vetor Ordenado Decrescente" << endl;
    BubbleSortDecrescente(idades, 4);
    cout << endl;
    return 0;
}