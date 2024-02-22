#include <iostream>
#include <windows.h>
#include <time.h> 
#include <chrono> 

using namespace std;
using namespace chrono;

int main() {
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    string produtoPreco[4][3];
    string nome;
    double preco;

    produtoPreco[0][0] = "\n\nProduto \t|\t Preço";

    for (int i = 1; i < 3; i++) {
        for (int j = 1; j < 2; j++) {
            cout << "Escreva o nome do Produto: ";
            cin >> nome;
            cout << "Preço do produto: ";
            cin >> preco;

            produtoPreco[i][j] = "\n" + nome + " \t\t|\t R$ " + to_string(preco);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << produtoPreco[i][j];
        }
    }

    cout << "\n" << produtoPreco[0][0] << produtoPreco[0][1] << produtoPreco[1][0] << produtoPreco[1][1] << produtoPreco[2][1] << endl;

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl << endl << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}