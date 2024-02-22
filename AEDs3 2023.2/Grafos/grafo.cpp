#include "grafo.hpp"

void menu()
{
    system("cls");
    cout << "********************************************************************************************" << endl;
    cout << "*********************************          MENU          ***********************************" << endl;
    cout << "********************************************************************************************" << endl;
    cout << "**                                                                                        **" << endl;
    cout << "**  Informe a opção desejada                                                              **" << endl;
    cout << "**  1 - Importar um Grafo de um arquivo de texto                                          **" << endl;
    cout << "**  2 - Criar grafo vazio                                                                 **" << endl;
    cout << "**  3 - Exibir a matriz                                                                   **" << endl;
    cout << "**  4 - Consultar a adjacência entre 2 vértices                                           **" << endl;
    cout << "**  5 - Inserir novas arestas                                                             **" << endl;
    cout << "**  6 - Remover arestas                                                                   **" << endl;
    cout << "**  7 - Editar as coordenadas                                                             **" << endl;
    cout << "**  8 - Consultar o 1° adjacente de um vértice                                            **" << endl;
    cout << "**  9 - Consultar o próximo adjacente de um vértice a partir de um adjacente informado    **" << endl;
    cout << "**  10 - Consultar a lista completa de adjacentes                                         **" << endl;
    cout << "**  11 - Exportar o grafo para um arquivo de texto                                        **" << endl;
    cout << "**  12 - Sair                                                                             **" << endl;
    cout << "**                                                                                        **" << endl;
    cout << "********************************************************************************************" << endl;
    cout << "********************************************************************************************" << endl;
    cout << "Opção: ";
}

void criarMatrizVertice(int num)
{
    qtdVertice = num;
    matrizArestasVertice = new int *[qtdVertice];
    for (int i = 0; i < qtdVertice; i++)
    {
        matrizArestasVertice[i] = new int[qtdVertice];
        for (int j = 0; j < qtdVertice; j++)
            matrizArestasVertice[i][j] = 0;
    }
}

void criaGrafoMatrizCoord(int num)
{
    qtdVertice = num;
    matrizCoordenadaVertice = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        matrizCoordenadaVertice[i] = new int[num];
        for (int j = 0; j < qtdVertice; j++)
            matrizCoordenadaVertice[i][j] = 0;
    }
}

void mostraGrafoVertice()
{
    cout << "\nMostrar Matriz Vertice: " << endl;
    for (int i = 0; i < qtdVertice; i++)
    {
        for (int j = 0; j < qtdVertice; j++)
        {
            if (matrizArestasVertice[i][j] > 9) // espaçamento para números com 1 digito
                cout << matrizArestasVertice[i][j] << " ";
            else // espaçamento para números com 2 digitos
                cout << matrizArestasVertice[i][j] << "  ";
        }
        cout << endl;
    }
}
void mostraGrafoCoordenada()
{
    cout << "\nMatriz Coordenadas dos vértices:\n\nX Y\n\n";
    for (int i = 0; i < qtdVertice; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << matrizCoordenadaVertice[j][i] << " ";
        cout << "\n";
    }
}

bool consultarSeAdjacente(int verticeInicial, int verticeFinal)
{
    if ((matrizArestasVertice[verticeInicial][verticeFinal] != 0))
    {
        cout << "As vértices são adjacentes" << endl;
        return true;
    }
    else
    {
        cout << "As vértices não são adjacentes" << endl;
        return false;
    }
}

void insereAresta(int verticeInicial, int verticeFinal, int peso)
{
    if (verticeInicial >= 0 && verticeFinal <= qtdVertice)
    {
        if (tipoGrafo == true)
            matrizArestasVertice[verticeInicial][verticeFinal] = peso;
        else
        {
            matrizArestasVertice[verticeInicial][verticeFinal] = peso;
            matrizArestasVertice[verticeFinal][verticeInicial] = peso;
        }
        qtdAresta++;
    }
    else
        cout << "Os vértices aos quais deseja inserir não existem no grafo" << endl;
}

void removeAresta(int verticeInicial, int verticeFinal)
{
    if (verticeInicial >= 0 || verticeFinal <= qtdVertice)
    {
        cout << "Você removeu a aresta que liga o vértice " << verticeInicial << " ao vértice " << verticeFinal << endl;
        if (tipoGrafo == true)
            matrizArestasVertice[verticeInicial][verticeFinal] = 0;
        else
        {
            matrizArestasVertice[verticeInicial][verticeFinal] = 0;
            matrizArestasVertice[verticeFinal][verticeInicial] = 0;
        }
        qtdAresta--;
    }
    else
        cout << "Os valores de Vértice Inicial e Vértice Final não foram encontrados." << endl;
}

void editarCoordenadasVertices(int vertice, int x, int y)
{
    if (vertice >= 0 || vertice < qtdVertice)
    {
        matrizCoordenadaVertice[0][vertice] = x;
        matrizCoordenadaVertice[1][vertice] = y;
    }
    else
        cout << "O vértice não pertence ao grafo." << endl;
}

void consultarPrimeiroAdjacente(int vertice)
{
    int i;
    for (i = 0; i <= vertice; i++)
    {
        if (matrizArestasVertice[i][vertice] != 0) // percorre até o primeiro adjacente e para
            break;
    }
    cout << "O primeiro Adjacente é " << i << endl;
}

void proximoAdjacente(int vertice, int partida)
{
    int result = -1;
    if (consultarSeAdjacente(vertice, partida) == true)
    {
        for (int i = partida + 1; i <= qtdVertice; i++) // começa a busca a partir do vértice que já é adjacente
        {
            if (matrizArestasVertice[vertice][i] != 0)
            {
                result = i;
                cout << "O próximo adjacente do Vértice " << vertice << " após o vértice " << partida << " é o " << result;
                break;
            }
            if (result != -1)
            {
                cout << "O vértice " << vertice << " não possui adjacentes posteriores ao " << partida << ".\n";
                break;
            }
        }
    }
    if (consultarSeAdjacente(vertice, partida) == false)
        cout << "Os vértices informados não são adjacentes." << endl << endl;
}

void listaCompletaDoVerticeAdjacentes(int vertice)
{
    cout << "Lista de Adjacentes: " << endl;
    for (int j = 0; j < qtdVertice; j++)
    {
        if (matrizArestasVertice[j][vertice] != 0)
            cout << j << endl;
    }
}

void exportar()
{
    cout << "Exportando Arquivo, espere alguns segundos." << endl;
    ofstream arqMatrix;
    arqMatrix.open("grafoFeitoViaCod.txt");
    arqMatrix << stipoGrafo << endl;
    arqMatrix << qtdVertice << endl;
    for (int i = 0; i < qtdVertice; i++)
    {
        arqMatrix << i << " ";
        arqMatrix << matrizCoordenadaVertice[0][i] << " ";
        arqMatrix << matrizCoordenadaVertice[1][i] << endl;
    }
    arqMatrix << qtdAresta << endl;
    for (int i = 0; i < qtdAresta; i++)
    {
        for (int j = 0; j < qtdAresta; j++)
        {
            if (matrizArestasVertice[i][j] != 0 && i < j)
            {
                arqMatrix << i << " ";
                arqMatrix << j << " ";
                arqMatrix << matrizArestasVertice[i][j] << endl;
            }
        }
    }
    arqMatrix.close();
    cout << "Arquivo Exportado, seu nome é 'grafoFeitoViaCod.txt'." << endl;
}

void importarGrafo()
{
    ifstream leitura("grafoProntoTeste.txt");
    leitura >> stipoGrafo;
    if (stipoGrafo == "direcionado=nao" || stipoGrafo == "nao")
        tipoGrafo = false;
    else
        tipoGrafo = true;
    leitura >> qtdVertice;
    criaGrafoMatrizCoord(qtdVertice);
    for (int i = 0; i < qtdVertice; i++)
    {
        int a = 0, b = 0, c = 0;
        leitura >> a >> b >> c;
        matrizCoordenadaVertice[0][i] = b;
        matrizCoordenadaVertice[1][i] = c;
    }

    leitura >> qtdAresta;
    criarMatrizVertice(qtdVertice);
    for (int i = 0; i < qtdAresta; i++)
    {
        int a = 0, b = 0, c = 0;
        leitura >> a >> b >> c;
        if (tipoGrafo == true) // direcionado
            matrizArestasVertice[a][b] = c;
        else // não direcionado
            matrizArestasVertice[a][b] = c;
        matrizArestasVertice[b][a] = c;
    }
    cout << "Arquivo importado com sucesso!" << endl;
}