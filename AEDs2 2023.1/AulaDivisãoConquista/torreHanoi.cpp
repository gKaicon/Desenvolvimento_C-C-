#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

void torre_hanoi(int n, char origem, char destino, char auxiliar) {
    if (n==1) {
        cout<<"Mover disco "<<n<<" de "<<origem<<" para "<<destino<< endl;
    }
    else{
        torre_hanoi(n-1, origem, auxiliar, destino);
        cout<<"Mover disco "<<n<<" de "<<origem<<" para "<<destino<< endl;
        torre_hanoi(n-1, auxiliar, destino, origem);
    }
}

int main() {
    int discos = 3;
    torre_hanoi(discos, 'A', 'C', 'B');
    //A é a origem (Torre 1)
    //B é a torre auxiliar (Torre 2)
    //C é o destino (Torre 3)
    cout << "Movimentações: " << pow(2, discos)-1;
 return 0;
}