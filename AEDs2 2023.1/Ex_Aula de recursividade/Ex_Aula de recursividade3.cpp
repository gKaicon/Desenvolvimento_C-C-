#include <iostream>
#include <windows.h>
#include <time.h> 

using namespace std;

void inverteVet(int vet[], int inicio, int tam){
    if(inicio >= tam){
        return;
    }
    else{
        int aux;
        aux = vet[inicio];
        vet[inicio] = vet[tam];
        vet[tam] = aux;
        inverteVet(vet, inicio + 1, tam -1);
    }
}

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    int n = 5, vet[n];

    for(int i = 0; i < n; i++){
        vet[i] = rand()%10;
    }
    
    cout << "Vetor: \n\n";
    for(int i = 0; i < n; i++){
        cout << vet[i] << "\t";
    }
    cout << "\n";

    inverteVet(vet, 0, n-1);

    cout << "\nVetor Invertido: \n\n";
    for(int i = 0; i < n; i++){
        cout << vet[i] << "\t";
    }
    cout << endl;
    return 0;
}