#include <iostream>
#include <windows.h>
#include <time.h> 

using namespace std;

//as comparações, quer dizer se elas foram pro if, pouco importa se eles foram verdadeiros ou não, apenas se foram testados

void MaxMin1(int vet[], int n, int &max, int &min, int &comp){
    max = vet[0];
    min = vet[0];
    for (int i = 1; i < n; i++){
        comp++;
        if(vet[i] > max) max = vet[i];
        comp++;
        if(vet[i] < min) min = vet[i];
    }
}

void MaxMin2(int vet[], int n, int &max, int &min, int &comp){
    max = vet[0];
    min = vet[0];
    for (int i = 1; i < n; i++){
        comp++;
        if(vet[i] > max) max = vet[i];

        else if(vet[i] < min){
            comp++;
            min = vet[i];
        }
    }
}

void MaxMin3(int vet[], int n, int max, int &min, int &comp){
    int i, FimDoAnel;
    if ((n % 2) > 0){
        vet[n] = vet[n - 1];
        FimDoAnel = n;
    }
    else FimDoAnel = n - 1;
    
    comp++;
    if (vet[0] > vet[1]){
        max = vet[0];
        min = vet[1];
    }
    else{
        max = vet[1];
        min = vet[0];
    }
    for (i = 2; i < FimDoAnel; i += 2){
        comp++;
        if (vet[i] > vet[i + 1]){
            comp++;
            if (vet[i] > max) max = vet[i];
            
            comp++;
            if (vet[i + 1] < min) min = vet[i + 1];
        }
        else{
            comp++;
            if (vet[i] < min) min = vet[i];

            comp++;
            if (vet[i + 1] > max) max = vet[i + 1];
        }
    }
}

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int n = 10, v[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, max, min, comp = 0;

    MaxMin1(v, n, max, min, comp);
    cout << "1 - Max: " << max << endl;
    cout << "1 - Min: " << min << endl;
    cout << "1 - Comparações: " << comp << endl << endl;

    comp = 0;
    MaxMin2(v, n, max, min, comp);
    cout << "2 - Max: " << max << endl;
    cout << "2 - Min: " << min << endl;
    cout << "2 - Comparações: " << comp << endl << endl;

    comp = 0;
    MaxMin3(v, n, max, min, comp);
    cout << "3 - Max: " << max << endl;
    cout << "3 - Min: " << min << endl;
    cout << "3 - Comparações: " << comp << endl << endl;

    cout << endl;
    return 0;
}