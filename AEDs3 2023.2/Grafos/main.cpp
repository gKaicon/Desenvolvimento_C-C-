#include "grafo.cpp"

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 5);
    srand(time(NULL));
    int opcao;
    do
    {
        menu();
        cin >> opcao;
        switch (opcao)
        {
            case 1:
            {
                importarGrafo();
                break;
            }
            case 2:
            {
                int qtdVerticeL, resp;
                cout << "Digite a quantidade de Vértices: ";
                cin >> qtdVerticeL;
                cout << "O grafo é direcionado ou não. Responda\n0 - Não\n1 - Sim\nOpção: ";
                cin >> resp;
                if (resp == 0)
                    stipoGrafo = "direcionado=nao";
                if (resp == 1)
                    stipoGrafo = "direcionado=sim";
                criarMatrizVertice(qtdVerticeL);
                criaGrafoMatrizCoord(qtdVerticeL);
                break;
            }
            case 3:
            {
                mostraGrafoVertice();
                mostraGrafoCoordenada();
                break;
            }
            case 4:
            {
                int vertice1, vertice2;
                cout << "Digite o primeiro vértice: ";
                cin >> vertice1;
                cout << "Digite o segundo vértice: ";
                cin >> vertice2;
                consultarSeAdjacente(vertice1, vertice2);
                break;
            }
            case 5:
            {
                int peso, inicio, fim;
                cout << "Digite a vertice inicial: ";
                cin >> inicio;
                cout << "Digite a vertice final: ";
                cin >> fim;
                cout << "Digite o peso da aresta: ";
                cin >> peso;
                insereAresta(inicio, fim, peso);
                break;
            }
            case 6:
            {
                int inicio, fim;
                cout << "Digite a aresta inicial: ";
                cin >> inicio;
                cout << "Digite a aresta final: ";
                cin >> fim;
                removeAresta(inicio, fim);
                break;
            }
            case 7:
            {
                int verticeL, valorX, valorY;
                cout << "Digite o vértice a ser editado: ";
                cin >> verticeL;
                cout << "Digite a coordenada x do vértice: ";
                cin >> valorX;
                while ((valorX > 100) || (valorX < 0))
                    cin >> valorX; // enquanto fora da escala 100, ele repete
                cout << "Digite a coordenada y do vértice: ";
                cin >> valorY;
                while ((valorY > 100) || (valorY < 0))
                    cin >> valorY; // enquanto fora da escala 100, ele repete
                editarCoordenadasVertices(verticeL, valorX, valorY);
                break;
            }
            case 8:
            {
                int verticeL;
                cout << "Digite o vértice: ";
                cin >> verticeL;
                consultarPrimeiroAdjacente(verticeL);
                break;
            }
            case 9:
            {
                int vertice1, verticeAdjao1;
                cout << "Digite o Vértice: ";
                cin >> vertice1;
                cout << "O adjacente do Vértice: ";
                cin >> verticeAdjao1;
                proximoAdjacente(vertice1, verticeAdjao1);
                break;
            }
            case 10:
            {
                int vertice;
                cout << "Digite o vértice: ";
                cin >> vertice;
                listaCompletaDoVerticeAdjacentes(vertice);
                break;
            }
            case 11:
            {
                exportar();
                break;
            }
            case 12:
            {
                exit(0);
                break;
            }
            default:
            {
                cout << "O número de entrada não corresponde a nenhuma opção do menu." << endl;
            }
        }
        system("PAUSE");
    } while (opcao != 12);

    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << "\nTempo de Execução:" << tempo.count() << " segundos\n";
    return 0;
}