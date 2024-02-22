#include <iostream>
#include <windows.h>
#include <time.h> 

using namespace std;

int somaVet(int vet[], int tam){
    if(tam == 0) return 0;
    else{
        return vet[tam-1] + somaVet(vet, tam - 1);
    }
}

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    int n = 3, vet[n];

    for(int i = 0; i < n; i++){
        vet[i] = rand()%10;
    }
    
    cout << "Vetor: \n\n";
    for(int i = 0; i < n; i++){
        cout << vet[i] << "\t";
    }

    cout << somaVet(vet, n);
    return 0;
}