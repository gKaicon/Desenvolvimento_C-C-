#include <iostream>
#include <windows.h>
#include <fstream>

// ifstream - leitura
// ofstream - escrita
// cerr - cout só que de console

using namespace std;

struct Habitante{
    double salario;
    int idade;
    int numFilho;
    char sexo;
};

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    ofstream escreve;
    escreve.open("cadastrocarregado.txt");
    if(!escreve.is_open()){
        cerr << "Erro ao abrir o arquivo";
        return -1;
    }

    double somaSa, somaFi, mediaSa, mediaFi, maiorSa, percMulher, qtdMulher = 0, qtdH;
    struct Habitante h[2];
    qtdH = 2;

    for(int i = 0; i < qtdH; i++){
         cout << "Informe o salário: R$ ";
         cin >> h[i].salario;
         escreve << h[i].salario << "\n";

         cout << "Informe a idade: ";
         cin >> h[i].idade;
         escreve << h[i].idade << "\n";

         cout << "Informe a quantidade de filhos: ";
         cin >> h[i].numFilho;
         escreve << h[i].numFilho << "\n";

         cout << "Informe o sexo: ";
         cin >> h[i].sexo;
         escreve << h[i].sexo << "\n";
    }
    escreve.close();
    /*
    h[1].salario = 990.0;
    h[1].idade = 19;
    h[1].numFilho = 2;
    h[1].sexo = 'F';

    h[2].salario = 2000.0;
    h[2].idade = 46;
    h[2].numFilho = 2;
    h[2].sexo = 'F';

    h[3].salario = 200.0;
    h[3].idade = 18;
    h[3].numFilho = 1;
    h[3].sexo = 'F';

    h[4].salario = 990.0;
    h[4].idade = 19;
    h[4].numFilho = 4;
    h[4].sexo = 'M';

    h[5].salario = 1990.0;
    h[5].idade = 24;
    h[5].numFilho = 2;
    h[5].sexo = 'M';
*/
    //média de salário da população
    for(int i = 0; i < qtdH; i++){
        somaSa += h[i].salario;
    }
    mediaSa = somaSa/qtdH;

    //média de número de filhos da população
    for(int i = 0; i < qtdH; i++){
        somaFi += h[i].numFilho;
    }
    mediaFi = somaFi/qtdH;
    
    //percentual de mulheres com salário abaixo de 1000
    for(int i = 0; i < qtdH; i++){
        if(((h[i].sexo == 'F') || (h[i].sexo == 'f')) && (h[i].salario <= 1000)){
            qtdMulher++;
        }
    }
    percMulher = qtdMulher * 100/qtdH;

    //maior salário
    for(int i = 0; i < qtdH; i++){
        if(h[i].salario > maiorSa){
            maiorSa = h[i].salario;
        }
    }
    cout << "Média de Salário da população: R$ " << mediaSa << "\n";
    cout << "Média de números de filhos da população: " << mediaFi << "\n";
    cout << "Percentual de mulheres com salário abaixo de R$ 1000.00:  " << percMulher << "% \n";
    cout << "Maior Salário: R$ " << maiorSa << endl;
    return 0;
}