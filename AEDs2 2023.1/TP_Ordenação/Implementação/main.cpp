#include "funcoes.cpp"

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2);

    int op;
    do{
        menuStringInt();
        cin >> op;
        if (op == 1){ // string
            if(lerArquivoS(menuString()) == false) break;
            else{
                switch (menuFuncoesOrdenacao()){
                case 1:
                    BubbleSortString();
                    break;
                case 2:
                    usaQuickString();
                    break;
                case 3:
                    ShellSortString();
                    break;
                case 4:
                    SelectionSortString();
                    break;
                case 5:
                    InsertionSortString();
                    break;
                case 6:
                    usaMergeString();
                    break;
                case 0:
                    cout << "Saindo...";
                    Sleep(2000);
                    break;    
                }
            }    
        }
        if (op == 2){ // int
            if (lerArquivoI(menuInt()) == false) break;
            else{
                switch (menuFuncoesOrdenacao()){
                case 1:
                    BubbleSortInt();
                    break;
                case 2:
                    usaQuickInt();
                    break;
                case 3:
                    ShellSortInt();
                    break;
                case 4:
                    SelectionSortInt();
                    break;
                case 5:
                    InsertionSortInt();
                    break;
                case 6:
                    usaMergeInt();
                    break;
                case 0:
                    cout << "Saindo...";
                    Sleep(2000);
                    break;
                }
            }
        }
        if (op == 0){
            cout << "Saindo...";
            Sleep(2000);
            break;
        }
    } while (op != 0);
    return 0;
}