#include "funcoes.hpp"

void menuStringInt(){
    system("cls");
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        **          Escolha o tipo de dados que será ordenado         **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 1 - STRING                                                 **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 2 - INT                                                    **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 0 - SAIR                                                   **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************";
    cout << "  \n        Opção: ";
}

int menuFuncoesOrdenacao(){
    int op;
    system("cls");
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        **                    Escolha uma ordenação                   **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                           OPÇÕES                           **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 1 - BUBBLESORT                                             **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 2 - QUICKSORT                                              **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 3 - SHELLSORT                                              **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 4 - SELECTIONSORT                                          **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 5 - INSERTIONSORT                                          **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 6 - MERGESORT                                              **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 0 - SAIR                                                   **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        Opção: ";
    cin >> op;
    return op;
}

int menuString()
{
    int op;
    system("cls");
    cout << "  \n        ******************************************************************";
    cout << "  \n        ******************************************************************";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        * *                    ORDENAÇÃO DE STRING                     * *";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        ******************************************************************";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        * *            ESCOLHA UMA LISTA PARA SER ORDENADA             * *";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        ******************************************************************";
    cout << "  \n        * *                           OPÇÕES                           * *";
    cout << "  \n        ******************************************************************";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        * * 1 - DicionarioAleatorio-29855                              * *";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        * * 2 - DicionarioAleatorio-261791                             * *";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        * * 3 - DicionarioInversamenteOrdenado-29855                   * *";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        * * 4 - DicionarioInversamenteOrdenado-261791                  * *";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        * * 5 - DicionarioOrdenado-29855                               * *";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        * * 6 - DicionarioOrdenado-261791                              * *";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        * * 0 - SAIR                                                   * *";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        ******************************************************************";
    cout << "  \n        * *                                                            * *";
    cout << "  \n        ******************************************************************";
    cout << "\n\nOpção: ";
    cin >> op;
    if (op == 0 || op > 6) return 0;
    else return op;
}

int menuInt()
{
    int op;
    system("cls");
    cout << "  \n        **********************************************************************************************";
    cout << "  \n        **********************************************************************************************";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        * *                                ORDENAÇÃO DE INTEIRO                                    * *";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        **********************************************************************************************";
    cout << "  \n        * *                         ESCOLHA UMA LISTA PARA SER ORDENADA                            * *";
    cout << "  \n        **********************************************************************************************";
    cout << "  \n        **********************************************************************************************";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        * *  1 - ListaAleatoria-1000                   2 - ListaAleatoria-10000                    * *";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        * *  3 - ListaAleatoria-100000                 4 - ListaAleatoria-1000000                  * *";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        * *  5 - ListaInversamenteOrdenada-1000        6 - ListaInversamenteOrdenada-10000         * *";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        * *  7 - ListaInversamenteOrdenada-100000      8 - ListaInversamenteOrdenada-1000000       * *";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        * *  9 - ListaOrdenada-1000                    10 - ListaOrdenada-10000                    * *";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        * *  11 - ListaOrdenada-100000                 12 - ListaOrdenada-1000000                  * *";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        * *  13 - ListaQuaseOrdenada-1000              14 - ListaQuaseOrdenada-10000               * *";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        * *  15 - ListaQuaseOrdenada-100000            16 - ListaQuaseOrdenada-1000000             * *";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        * *  0 - SAIR                                                                              * *";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        **********************************************************************************************";
    cout << "  \n        * *                                                                                        * *";
    cout << "  \n        **********************************************************************************************";
    cout << "  \n        Opção: ";
    cin >> op;
    if (op < 1 || op > 16) return 0;
    else return op;
}

bool lerArquivoS(int op){//leitura de arquivos com dados do tipo String
    if (op < 1 || op > 6){
        cout << "Você pressionou para sair. Ou digitou um valor acima de 6";
        nomeArquivo = "";
        arquivo.close();
        return false;
    }
    else{
        switch (op){
        case 1:
            nomeArquivo = "../arquivos/DicionarioAleatorio-29855.txt";
            break;
        case 2:
            nomeArquivo = "../arquivos/DicionarioAleatorio-261791.txt";
            break;
        case 3:
            nomeArquivo = "../arquivos/DicionarioInversamenteOrdenado-29855.txt";
            break;
        case 4:
            nomeArquivo = "../arquivos/DicionarioInversamenteOrdenado-261791.txt";
            break;
        case 5:
            nomeArquivo = "../arquivos/DicionarioOrdenado-29855.txt";
            break;
        case 6:
            nomeArquivo = "../arquivos/DicionarioOrdenado-261791.txt";
            break;
        }
        arquivo.open(nomeArquivo);
    }

    if (!arquivo.is_open()){
        cerr << "Arquivo inexistente." << endl;
        Sleep(2000);
        arquivo.clear();
        return false;
    }
    if (arquivo.is_open()){
        cout << "O arquivo " << nomeArquivo << " foi aberto";
        Sleep(1500);
        arquivo.clear();

        while (!arquivo.eof()){
            string conteudo;
            arquivo >> conteudo;
            vS.push_back(conteudo);
        }
        arquivo.close();
        nomeArquivo = "";
        return true;
    }
}

bool lerArquivoI(int opI){
    if (opI < 1 || opI > 16){
        cout << "Você pressionou para sair. Ou digitou um valor acima de 16";
        nomeArquivo = "";
        arquivo.close();
        return false;
    }
    else{
        switch (opI){
        case 1:
            nomeArquivo = "../arquivos/ListaAleatoria-1000.txt";
            break;
        case 2:
            nomeArquivo = "../arquivos/ListaAleatoria-10000.txt";
            break;
        case 3:
            nomeArquivo = "../arquivos/ListaAleatoria-100000.txt";
            break;
        case 4:
            nomeArquivo = "../arquivos/ListaAleatoria-1000000.txt";
            break;
        case 5:
            nomeArquivo = "../arquivos/ListaInversamenteOrdenada-1000.txt";
            break;
        case 6:
            nomeArquivo = "../arquivos/ListaInversamenteOrdenada-10000.txt";
            break;
        case 7:
            nomeArquivo = "../arquivos/ListaInversamenteOrdenada-100000.txt";
            break;
        case 8:
            nomeArquivo = "../arquivos/ListaInversamenteOrdenada-1000000.txt";
            break;
        case 9:
            nomeArquivo = "../arquivos/ListaOrdenada-1000.txt";
            break;
        case 10:
            nomeArquivo = "../arquivos/ListaOrdenada-10000.txt";
            break;
        case 11:
            nomeArquivo = "../arquivos/ListaOrdenada-100000.txt";
            break;
        case 12:
            nomeArquivo = "../arquivos/ListaOrdenada-1000000.txt";
            break;
        case 13:
            nomeArquivo = "../arquivos/ListaQuaseOrdenada-1000.txt";
            break;
        case 14:
            nomeArquivo = "../arquivos/ListaQuaseOrdenada-10000.txt";
            break;
        case 15:
            nomeArquivo = "../arquivos/ListaQuaseOrdenada-100000.txt";
            break;
        case 16:
            nomeArquivo = "../arquivos/ListaQuaseOrdenada-1000000.txt";
            break;
        }
        arquivo.open(nomeArquivo);
    }
    if (!arquivo.is_open()){
        cerr << "Arquivo inexistente, ou você pressionou para sair." << endl;
        Sleep(2000);
        arquivo.clear();
        return false;
    }

    if (arquivo.is_open()){
        cerr << "O arquivo " << nomeArquivo << " foi aberto";
        Sleep(2000);
        arquivo.clear();
        while (!arquivo.eof()){
            int conteudo;
            arquivo >> conteudo;
            vI.push_back(conteudo);
        }
        arquivo.close();
        nomeArquivo = "";
        return true;
    }
}

void imprimeVetS(){ //impressão de String
    for (int i = 0; i < vS.size(); i++) cout << vS[i] << "\n"; //impressão do vetor
    //depois da impressão, que é logo após a ordenação, limpa-se o vetor
    int j = vS.size() - 1;
    do{ //gambiarra, por que tava com problemas com o clear()
        vS.pop_back();
        j--;
    } while (j > 0);
}

void imprimeVetI(){ //Impressão de Inteiro
    for (int i = 0; i < vI.size(); i++)  cout << vI[i] << "\n"; //impressão do vetor
    //depois da impressão, que é logo após a ordenação, limpa-se o vetor
    int j = vI.size() - 1;
    do{ //gambiarra, por que tava com problemas com o clear()
        vI.pop_back();
        j--;
    } while (j > 0);
}

void BubbleSortInt(){
    cout << "Estamos ordenando seu array" << endl;
    steady_clock::time_point tempoinicio = steady_clock::now();
    int aux;
    bool troca;
    unsigned long long comparacao = 0, trocas = 0;

    for (int i = 0; i < vI.size() - 1; i++){
        troca = false;
        for (int j = 1; j < vI.size() - i; j++){
            comparacao++;
            if (vI[j] < vI[j - 1]){
                aux = vI[j];
                vI[j] = vI[j - 1];
                vI[j - 1] = aux;
                troca = true;
                trocas++;
            }
        }
        if (troca == false) break; // já está ordenado
    }
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado";
    imprimeVetI();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparação: " << comparacao << endl;
    system("PAUSE");
}

void QuickSortInt(int esquerda, int direita, unsigned long long *comparacao, unsigned long long *trocas){

    int aux, i = esquerda, j = direita;
    int pivo = vI[(esquerda + direita) / 2];

    while (i <= j){
        while (vI[i] < pivo) i++;
        while (vI[j] > pivo) j--;
        (*comparacao)++;
        if (i <= j){
            aux = vI[i];
            vI[i] = vI[j];
            vI[j] = aux;
            i++;
            j--;
            (*trocas)++;
        }
    }

    (*comparacao)++;
    if (esquerda < j) QuickSortInt(esquerda, j, comparacao, trocas);
    (*comparacao)++;
    if (i < direita)  QuickSortInt(i, direita, comparacao, trocas);
}

void usaQuickInt()
{
    cout << "Estamos ordenando seu array" << endl;
    steady_clock::time_point tempoinicio = steady_clock::now();

    unsigned long long trocas = 0, comparacao = 0;
    QuickSortInt(0, vI.size() - 1, &comparacao, &trocas);

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado." << endl;
    imprimeVetI();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparação: " << comparacao << endl;
    system("PAUSE");
}

void ShellSortInt(){
    cout << "Estamos ordenando seu array" << endl;
    steady_clock::time_point tempoinicio = steady_clock::now();
    unsigned long long comparacao = 0, trocas = 0;
    int i, j, value;

    int h = 1;
    while (h < vI.size()) h = 3 * h + 1;

    while (h > 0){
        comparacao++;
        for (i = h; i < vI.size(); i++){
            value = vI[i];
            j = i;
            while (j > h - 1 && value <= vI[j - h]){
                comparacao++; //foi feita dentro do while
                vI[j] = vI[j - h];
                j = j - h;
                trocas++;
            }
            vI[j] = value;
        }
        h = h / 3;
    }
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado." << endl;
    imprimeVetI();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparacao: " << comparacao << endl;
    system("PAUSE");
}

void SelectionSortInt(){
    cout << "Estamos ordenando seu array" << endl;
    steady_clock::time_point tempoinicio = steady_clock::now();
    unsigned long long comparacao = 0, trocas = 0;

    int min, aux;

    for (int i = 0; i < vI.size() - 1; i++){
        min = i;
        for (int j = i + 1; j < vI.size(); j++){
            comparacao++;
            if (vI[j] < vI[min]) min = j;
        }
        aux = vI[i];
        vI[i] = vI[min];
        vI[min] = aux;
        trocas++;
    }
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado." << endl;
    imprimeVetI();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparacao: " << comparacao << endl;
    system("PAUSE");
}

void InsertionSortInt(){
    cout << "Estamos ordenando seu array" << endl;
    steady_clock::time_point tempoinicio = steady_clock::now();
    unsigned long long comparacao = 0, trocas = 0;
    int aux;

    for (int i = 1; i < vI.size(); i++){
        aux = vI[i];
        for (int j = i; ((j > 0) && (aux < vI[j - 1])); j--){
            comparacao++; //Comparação feita no for
            vI[j] = vI[j - 1];
            vI[j - 1] = aux;
            trocas++;
        }
    }
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado." << endl;
    imprimeVetI();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparacao: " << comparacao << endl;
    system("PAUSE");
}

void IntercalaInt(int inicio, int meio, int fim, unsigned long long *comparacao, unsigned long long *trocas){
    int *ListaAux = (int *)malloc(sizeof(int) * (fim + 1));
    int i, j;

    for (i = inicio; i <= meio; i++) ListaAux[i] = vI[i];
    for (j = meio + 1; j <= fim; j++) ListaAux[fim + meio + 1 - j] = vI[j];

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++){
        (*comparacao)++;
        if (ListaAux[i] <= ListaAux[j]){
            vI[k] = ListaAux[i];
            i++;
            (*trocas)++;
        }
        else{
            vI[k] = ListaAux[j];
            j--;
            (*trocas)++;
        }
    }
    free(ListaAux);
}

void MergeSortInt(int inicio, int fim, unsigned long long *comparacao, unsigned long long *trocas){
    int meio;
    if (inicio < fim){ //recursividade
        meio = (inicio + fim) / 2;
        MergeSortInt(inicio, meio, comparacao, trocas);
        MergeSortInt(meio + 1, fim, comparacao, trocas);
        IntercalaInt(inicio, meio, fim, comparacao, trocas);
    }
}

void usaMergeInt(){
    cout << "Estamos ordenando seu array" << endl;
    steady_clock::time_point tempoinicio = steady_clock::now();

    unsigned long long comparacao = 0, trocas = 0;
    MergeSortInt(0, vI.size() - 1, &comparacao, &trocas);

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado." << endl;
    imprimeVetI();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparacao: " << comparacao << endl;
    system("PAUSE");
}

void BubbleSortString(){
    cout << "Estamos ordenando seu array" << endl;
    steady_clock::time_point tempoinicio = steady_clock::now();
    unsigned long long comparacao = 0, trocas = 0;
    bool troca;
    string aux;

    for (int i = 0; i < vS.size() - 1; i++){
        troca = false;
        for (int j = 1; j < vS.size() - i; j++){
            comparacao++;
            if (vS[j] < vS[j - 1]){
                aux = vS[j];
                vS[j] = vS[j - 1];
                vS[j - 1] = aux;
                troca = true;
                trocas++;
            }
        }
        if (troca == false) break;
    }
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado." << endl;
    imprimeVetS();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparacao: " << comparacao << endl;
    system("PAUSE");
}

void QuickSortString(int esquerda, int direita, unsigned long long *comparacao, unsigned long long *trocas){
    int i = esquerda, j = direita;
    string pivo = vS[(esquerda + direita) / 2], tmp;

    while (i <= j){
        while (vS[i] < pivo) i++;
        while (vS[j] > pivo) j--;
        if (i <= j){
            (*comparacao)++;
            tmp = vS[i];
            vS[i] = vS[j];
            vS[j] = tmp;
            i++;
            j--;
            (*trocas)++;
        }
    }
    (*comparacao)++;
    if (esquerda < j) QuickSortString(esquerda, j, comparacao, trocas);
    (*comparacao)++;
    if (i < direita) QuickSortString(i, direita, comparacao, trocas);
}

void usaQuickString(){
    cout << "Estamos ordenando seu array" << endl;
    steady_clock::time_point tempoinicio = steady_clock::now();
    unsigned long long comparacao = 0, trocas = 0;
    QuickSortString(0, vS.size() - 1, &comparacao, &trocas);
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado." << endl;
    imprimeVetS();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparacao: " << comparacao << endl;
    system("PAUSE");
}

void ShellSortString(){
    cout << "Estamos ordenando seu array" << endl;
    steady_clock::time_point tempoinicio = steady_clock::now();
    unsigned long long comparacao = 0, trocas = 0;
    int i, j;
    string value;

    int h = 1;
    while (h < vS.size()) h = 3 * h + 1;

    while (h > 0){
        comparacao++;
        for (i = h; i < vS.size(); i++){
            value = vS[i];
            j = i;
            while (j > h - 1 && value <= vS[j - h]) {
                comparacao++; //feita no while
                vS[j] = vS[j - h];
                j = j - h;
                trocas++;
            }
            vS[j] = value;
        }
        h = h / 3;
    }
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado." << endl;
    imprimeVetS();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparacao: " << comparacao << endl;
    system("PAUSE");
}

void SelectionSortString(){
    cout << "Estamos ordenando seu array" << endl;
    steady_clock::time_point tempoinicio = steady_clock::now();
    unsigned long long comparacao = 0, trocas = 0;
    int min;
    string aux;

    for (int i = 0; i < vS.size() - 1; i++){
        min = i;
        for (int j = i + 1; j < vS.size(); j++){
            comparacao++;
            if (vS[j] < vS[min]) min = j;
        }
        aux = vS[i];
        vS[i] = vS[min];
        vS[min] = aux;
        trocas++;
    }
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado." << endl;
    imprimeVetS();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparacao: " << comparacao << endl;
    system("PAUSE");
}

void InsertionSortString(){
    cout << "Estamos ordenando seu array" << endl;
    steady_clock::time_point tempoinicio = steady_clock::now();
    unsigned long long comparacao = 0, trocas = 0;
    string aux;

    for (int i = 1; i < vS.size(); i++){
        aux = vS[i];
        for (int j = i; ((j > 0) && (aux < vS[j - 1])); j--){
            comparacao++; //feita no for
            vS[j] = vS[j - 1];
            vS[j - 1] = aux;
            trocas++;
        }
    }
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado." << endl;
    imprimeVetS();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparacao: " << comparacao << endl;
    system("PAUSE");
}

void IntercalaString(int inicio, int meio, int fim, unsigned long long *comparacao, unsigned long long *trocas){
    string *ListaAux = (string *)calloc(fim + 1, sizeof(string));
    int i, j;

    for (i = inicio; i <= meio; i++) ListaAux[i] = vS[i];
    for (j = meio + 1; j <= fim; j++) ListaAux[fim + meio + 1 - j] = vS[j];

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++){
        (*comparacao)++;
        if (ListaAux[i] <= ListaAux[j]){
            vS[k] = ListaAux[i];
            i++;
            (*trocas)++;
        }
        else{
            vS[k] = ListaAux[j];
            j--;
            (*trocas)++;
        }
    }
    free(ListaAux);
}

void MergeSortString(int inicio, int fim, unsigned long long *comparacao, unsigned long long *trocas){
    int meio;
    if (inicio < fim){
        meio = (inicio + fim) / 2;
        MergeSortString(inicio, meio, comparacao, trocas);
        MergeSortString(meio + 1, fim, comparacao, trocas);
        IntercalaString(inicio, meio, fim, comparacao, trocas);
    }
}

void usaMergeString(){
    cout << "Estamos ordenando seu array" << endl;
    unsigned long long trocas = 0, comparacao = 0;
    steady_clock::time_point tempoinicio = steady_clock::now();

    MergeSortString(0, vS.size() - 1, &comparacao, &trocas);

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "Foi ordenado." << endl;
    imprimeVetS();
    cout << "\nTempo: " << tempo.count() << " segundos" << endl;
    cout << "\nTrocas: " << trocas << endl;
    cout << "Comparacao: " << comparacao << endl;
    system("PAUSE");
}