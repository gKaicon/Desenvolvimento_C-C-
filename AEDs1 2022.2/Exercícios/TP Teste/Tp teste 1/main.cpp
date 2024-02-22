#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include "funcoes.cpp"

#define Max_Tam 5
#define Inicio 0

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    system("cls");

    TListaEncadeada listaE;
    TListaSequencial listaS;
    CriaListaVaziaEncadeada(&listaE);

    // Manipulação do arquivo funcionarios.bin
    FILE *arquivo;
    TFuncionario fun;
    TApontador y = listaE.Primeiro;
    arquivo = fopen("funcionarios.bin", "rb");
    if (arquivo != NULL)
    {
        while (fread(&fun, sizeof(TFuncionario), 1, arquivo))
        {
            InserirEncadeada(fun, &listaE);
        }
        fclose(arquivo);
    }
    else
    {
        cout << "Arquivo vazio!!";
    }

    int opcao;

    do
    {
        menu();
        cout << "Escolha uma opção: ";
        cin >> opcao;
        system("cls");
        switch (opcao)
        {
        case 1:
            CadastraFuncionario(&listaE);
            break;
        case 2:
            CadastraProjetos(&listaE);
            break;
        case 3:
            ExcluiProjetos(&listaE);
            break;
        case 4:
            ExcluiFuncionario(&listaE);
            break;
        case 5:
            ConsultaFuncionario(&listaE);
            break;
        case 6:
            ImprimeContraCheque(&listaE);
            break;
        }
    } while (opcao != 7);

    //Gravando no arquivo
    arquivo = fopen("funcionarios.bin", "wb");

    while (y->prox != NULL)
    {
        fun = y->prox->item;
        fwrite(&fun, sizeof(TFuncionario), 1, arquivo);
        y = y->prox;
    }

    fclose(arquivo);

    return 0;
}