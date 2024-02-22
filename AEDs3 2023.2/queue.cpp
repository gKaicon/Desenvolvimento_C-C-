#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <stack>

using namespace std;
using namespace chrono;

struct carta{
    int carta;
};


int somaPilha(stack<carta> mao){
    int somaTotal;
    while (!mao.empty())
    {
        somaTotal = mao.top().carta + somaTotal;
        mao.pop();
    }
    return somaTotal;
}
void imprimeMao(stack<carta> mao){
    cout << "Mão: ";
    while (!mao.empty())
    {
        cout << mao.top().carta << ", ";
        mao.pop();
    }
}

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2);
    srand(time(NULL));
    stack<carta> mao;

    int entrada = 3, sort;
    int somaPilhaI = 0;
    string valorSort;
    while(entrada != -1){
        carta c;
        c.carta = sort = rand()%10;
        mao.push(c);
        imprimeMao(mao);
        somaPilhaI = somaPilha(mao);
        entrada --;
    }
    system("PAUSE");
    system("cls");
    imprimeMao(mao);
    cout << somaPilhaI;
    

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "\n\nTempo de Execução:" << setprecision(2) << tempo.count() << " segundos" << endl;
    // system("taskkill /f /im cmd.exe");
    return 0;
}
