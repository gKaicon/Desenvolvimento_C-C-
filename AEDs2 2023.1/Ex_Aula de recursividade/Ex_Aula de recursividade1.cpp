#include <iostream>
#include <windows.h>
#include <time.h> 

using namespace std;

double potencia(double base, int expoente){
    if(expoente == 0) return 1;
    else{
        return base * potencia(base, expoente - 1);
    }
}

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    cout << potencia(2,3);
    cout << endl;
    return 0;
}