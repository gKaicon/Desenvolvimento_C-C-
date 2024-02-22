#include "grafo.cpp"

int main()
{
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 6);
    srand(time(NULL));
    
    int opcao = -1;
    //importarGrafo(); // apagar para apresentar
    do
    {
        menu();
        cin >> opcao;
        switch (opcao)
        {
        case 1:
        {
            menuCriaGrafo();
            break;
        }
        case 2:
        {
            insereArestaGrafo();
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
            if (consultarSeAdjacente(vertice1, vertice2) == true)
                cout << "As vértices são adjacentes" << endl;
            else
                cout << "As vértices não são adjacentes" << endl;
            break;
        }
        case 5:
        {
            int verticeL;
            cout << "Digite o vértice: ";
            cin >> verticeL;
            consultarPrimeiroAdjacente(verticeL);
            break;
        }
        case 6:
        {
            int vertice1, verticeAdjao1;
            cout << "Digite o Vértice: ";
            cin >> vertice1;
            cout << "O adjacente do Vértice: ";
            cin >> verticeAdjao1;
            proximoAdjacente(vertice1, verticeAdjao1);
            break;
        }
        case 7:
        {
            int vertice;
            cout << "Digite o vértice: ";
            cin >> vertice;
            listaCompletaDoVerticeAdjacentes(vertice);
            break;
        }
        case 8:
        {
            int verticeV;
            cout << "Digite o indice do vértice que você quer ver as informações: ";
            cin >> verticeV;
            mostraInformacaoVertice(verticeV);
            break;
        }
        case 9:
        {
            editaConteudoVertice();
            break;
        }
        case 10:
        {
            mostraGrafoCoordenada();
            int verticeL, valorX = -1, valorY = -1;
            cout << "Digite o vértice a ser editado: ";
            cin >> verticeL;
            cout << "Digite a coordenada x do vértice: ";
            while ((valorX > 100) || (valorX < 0))
                cin >> valorX; // enquanto fora da escala 100, ele repete
            cout << "Digite a coordenada y do vértice: ";
            while ((valorY > 100) || (valorY < 0))
                cin >> valorY; // enquanto fora da escala 100, ele repete
            editarCoordenadasVertices(verticeL, valorX, valorY);
            break;
        }
        case 11:
        {
            int inicio, fim;
            cout << "Digite a aresta inicial: ";
            cin >> inicio;
            cout << "Digite a aresta final: ";
            cin >> fim;
            removeAresta(inicio, fim);
            break;
        }
        case 12:
        {
            importarGrafo();
            break;
        }
        case 13:
        {
            exportarGrafo();
            break;
        }
        case 14:
        {
            int verticeOrigem, t = 0;
            cout << "Digite o vértice de partida para realização da busca em profundidade: ";
            cin >> verticeOrigem;
            system("cls");
            visitaParaBuscaProfundidade(verticeOrigem, &t);
            visitaBuscaProfundidadeRemanescente(&t);
            reiniciaGrafo();
            break;
        }
        case 15:
        {
            int verticeOrigem, d = 0;
            cout << "Digite o vértice de partida para realização da busca em largura: ";
            cin >> verticeOrigem;
            buscalargura(verticeOrigem, &d);
            visitaBuscaLarguraRemanescente();
            reiniciaGrafo();
            break;
        }
        case 16:
        {
            cin.ignore();
            cout << "Indice\tConteúdo" << endl;
            for (int i = 0; i < qtdVertice; i++)
                cout << "  " << i << "\t" << listaAdjVertice[i].conteudo << endl;
            string nomeOrigem, nomeDestino;
            cout << "Digite o nome do vértice de partida para realização do algoritmo de menor caminho: ";
            getline(cin, nomeOrigem);
            cout << "Digite o nome do vértice de destino para realização do algoritmo de menor caminho: ";
            getline(cin, nomeDestino);
            int verticeOrigem = retornaIndice(nomeOrigem), verticeDestino = retornaIndice(nomeDestino);
            auto resultados = dijkstraMenorCaminho(verticeOrigem, verticeDestino);
            imprimirMenoresCaminhos(verticeOrigem, resultados);
            break;
        }
        case 17:
        {
            cout << "Árvore Geradora mínima" << endl;
            kruskal();
            break;
        }
        case 0:
        {
            cout << "Saindo...";
            steady_clock::time_point tempofim = steady_clock::now();
            duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
            cout << "\n\nTempo de Execução: " << setprecision(2) << tempo.count() << " segundos\n";
            Sleep(200);
            system("taskkill /f /im cmd.exe");
            exit(0);
            break;
        }
        default:
        {
            cout << "O número de entrada não corresponde a nenhuma opção do menu." << endl;
            break;
        }
        }
        opcao = -1;
        cout << endl;
        system("PAUSE");
    } while (opcao != 0);
    return 0;
}