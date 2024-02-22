#include "grafo.hpp"

void exportarGrafo()
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
        arqMatrix << matrizCoordenadaVertice[1][i] << " ";
        arqMatrix << listaAdjVertice[i].conteudo << endl;
    }
    arqMatrix << qtdAresta << endl;
    for (int i = 0; i < qtdVertice; i++)
    {
        for (int j = 0; j < qtdVertice; j++)
        {
            if (tipoGrafo == false)
            { // se não direcionado
                if (listaAdjVertice[i].ligacao[j] != 0 && i <= j)
                {
                    arqMatrix << i << " ";
                    arqMatrix << j << " ";
                    arqMatrix << listaAdjVertice[i].ligacao[j] << endl;
                }
            }
            if (tipoGrafo == true)
            { // se direcionado
                if (listaAdjVertice[i].ligacao[j] != 0)
                {
                    arqMatrix << i << " ";
                    arqMatrix << j << " ";
                    arqMatrix << listaAdjVertice[i].ligacao[j] << endl;
                }
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
    if (stipoGrafo.compare("direcionado=nao") == 0) // se 0, significa que são iguais
        tipoGrafo = false;
    if (stipoGrafo.compare("direcionado=sim") == 0) // se 0, significa que são iguais
        tipoGrafo = true;
    leitura >> qtdVertice;
    criaGrafoMatrizCoord(qtdVertice);
    criarMatrizVerticeBuscas(qtdVertice);
    for (int i = 0; i < qtdVertice; i++)
    {
        int a = 0;
        leitura >> a >> matrizCoordenadaVertice[0][i] >> matrizCoordenadaVertice[1][i];
        getline(leitura >> ::ws, listaAdjVertice[a].conteudo);
    }
    leitura >> qtdAresta;
    for (int i = 0; i < qtdAresta; i++)
    {
        int a = 0, b = 0, c = 0;
        leitura >> a >> b >> c;
        if (tipoGrafo == true) // direcionado
            listaAdjVertice[a].ligacao[b] = c;
        else
        { // não direcionado
            listaAdjVertice[a].ligacao[b] = c;
            listaAdjVertice[b].ligacao[a] = c;
        }
    }
    cout << "Arquivo importado com sucesso!" << endl;
}

void menu()
{
    system("cls");
    cout << "    ********************************************************************************************" << endl;
    cout << "    *********************************          MENU          ***********************************" << endl;
    cout << "    ********************************************************************************************" << endl;
    cout << "    **                                                                                        **" << endl;
    cout << "    **                               INFORME A OPÇÃO DESEJADA                                 **" << endl;
    cout << "    **                                                                                        **" << endl;
    cout << "    ********************************************************************************************" << endl;
    cout << "    **                                                                                        **" << endl;
    cout << "    **   1 - Criar grafo vazio                                                                **" << endl;
    cout << "    **   2 - Inserir novas arestas                                                            **" << endl;
    cout << "    **   3 - Exibir a matriz                                                                  **" << endl;
    cout << "    **   4 - Consultar a adjacência entre 2 vértices                                          **" << endl;
    cout << "    **   5 - Consultar o 1° adjacente de um vértice                                           **" << endl;
    cout << "    **   6 - Consultar o próximo adjacente de um vértice a partir de um adjacente informado   **" << endl;
    cout << "    **   7 - Consultar a lista completa de adjacentes                                         **" << endl;
    cout << "    **   8 - Ver conteúdo do vértice                                                          **" << endl;
    cout << "    **   9 - Editar conteúdo do vértice                                                       **" << endl;
    cout << "    **  10 - Editar as coordenadas do vértice                                                 **" << endl;
    cout << "    **  11 - Remover aresta                                                                   **" << endl;
    cout << "    **  12 - Importar                                                                         **" << endl;
    cout << "    **  13 - Exportar                                                                         **" << endl;
    cout << "    **  14 - Busca em profundidade                                                            **" << endl;
    cout << "    **  15 - Busca em largura                                                                 **" << endl;
    cout << "    **  16 - Algoritmo menor caminho - Dijkstra                                               **" << endl;
    cout << "    **  17 - Algoritmo Árvore geradora mínima - Kruskal                                       **" << endl;
    cout << "    **   0 - Sair                                                                             **" << endl;
    cout << "    **                                                                                        **" << endl;
    cout << "    ********************************************************************************************" << endl;
    cout << "    ********************************************************************************************" << endl;
    cout << "\nOpção: ";
}

void menuCriaGrafo()
{
    int qtdVerticeL = -1, resp;
    while (qtdVerticeL < 0)
    {
        cout << "Digite a quantidade de Vértices: ";
        cin >> qtdVerticeL;
    }
    cout << "O grafo é direcionado ou não. Responda\n0 - Não\n1 - Sim\nOpção: ";
    cin >> resp;
    if (resp == 0)
    {
        stipoGrafo = "direcionado=nao";
        tipoGrafo = false;
    }
    else if (resp == 1)
    {
        stipoGrafo = "direcionado=sim";
        tipoGrafo = true;
    }
    criarMatrizVerticeBuscas(qtdVerticeL);
    criaGrafoMatrizCoord(qtdVerticeL);
}

void criaGrafoMatrizCoord(int num)
{
    qtdVertice = num;
    matrizCoordenadaVertice = new double *[2];
    for (int i = 0; i < 2; i++)
    {
        matrizCoordenadaVertice[i] = new double[num];
        for (int j = 0; j < qtdVertice; j++)
            matrizCoordenadaVertice[i][j] = 0.00;
    }
}

void criarMatrizVerticeBuscas(int num)
{
    qtdVertice = num;
    listaAdjVertice = new vertice[qtdVertice];
    for (int i = 0; i < qtdVertice; i++)
    {
        listaAdjVertice[i].ligacao = new int[qtdVertice];
        for (int j = 0; j < qtdVertice; j++)
        {
            listaAdjVertice[i].ligacao[j] = 0;
        }
        listaAdjVertice[i].conteudo = "";
        listaAdjVertice[i].ant = (-1);
        listaAdjVertice[i].situacaoCor = 'b';
        listaAdjVertice[i].tempoDescoberta = NULL;
        listaAdjVertice[i].tempoFinalizacao = NULL;
        listaAdjVertice[i].distOrigem = __LONG_LONG_MAX__;
    }
}

void mostraGrafoVertice()
{
    cout << "\nMostrar Matriz Vertice: " << endl;
    cout << "Lista de adjacências\t\t\t | Conteúdo " << endl;
    for (int i = 0; i < qtdVertice; i++)
    {
        for (int j = 0; j < qtdVertice; j++)
        {
            if (listaAdjVertice[i].ligacao[j] < 9) // espaçamento para números com 1 digito
                cout << listaAdjVertice[i].ligacao[j] << "   ";
            else if (listaAdjVertice[i].ligacao[j] > 9 && listaAdjVertice[i].ligacao[j] <= 99) // espaçamento para números com 2 digito
                cout << listaAdjVertice[i].ligacao[j] << "  ";
            else // espaçamento para números com 3 digitos
                cout << listaAdjVertice[i].ligacao[j] << " ";
        }
        cout << " | " << listaAdjVertice[i].conteudo << endl;
    }
}

void mostraGrafoCoordenada()
{
    cout << "\nMatriz Coordenadas dos vértices:\n\nI   X      Y\t\tConteúdo\n\n";
    for (int i = 0; i < qtdVertice; i++)
    {
        cout << i << "   ";
        for (int j = 0; j < 2; j++)
        {
            if (matrizCoordenadaVertice[j][i] <= 9) // espaçamento para números com 1 digito
                cout << matrizCoordenadaVertice[j][i] << "   ";
            else if (matrizCoordenadaVertice[j][i] > 9 && matrizCoordenadaVertice[j][i] <= 99) // espaçamento para números com 2 digito
                cout << matrizCoordenadaVertice[j][i] << "  ";
            else // espaçamento para números com 3 digitos
                cout << matrizCoordenadaVertice[j][i] << " ";
        }
        cout << "\t" << listaAdjVertice[i].conteudo << "\n";
    }
}

bool consultarSeAdjacente(int verticeInicial, int verticeFinal)
{
    if ((listaAdjVertice[verticeInicial].ligacao[verticeFinal] != 0))
        return true;
    else
        return false;
}

void insereArestaGrafo()
{
    int peso = -1, verticeInicial, verticeFinal;
    do
    {
        cout << "Digite a vertice inicial: ";
        cin >> verticeInicial;
    } while (verticeInicial >= qtdVertice || verticeInicial < -1);
    do
    {
        cout << "Digite a vertice final: ";
        cin >> verticeFinal;
    } while (verticeFinal >= qtdVertice || verticeFinal < -1);

    if (verticeInicial == verticeFinal)
        peso = 1;
    else
    {
        while (peso < 0)
        {
            cout << "Digite o peso da aresta: ";
            cin >> peso;
        }
    }
    if (tipoGrafo == true)
        listaAdjVertice[verticeInicial].ligacao[verticeFinal] = peso;
    else if (tipoGrafo == false)
    {
        listaAdjVertice[verticeInicial].ligacao[verticeFinal] = peso;
        listaAdjVertice[verticeFinal].ligacao[verticeInicial] = peso;
    }
    qtdAresta++;
}

void removeAresta(int verticeInicial, int verticeFinal)
{
    if (verticeInicial >= 0 && verticeFinal <= qtdVertice)
    {
        if (tipoGrafo == true)
        {
            listaAdjVertice[verticeInicial].ligacao[verticeFinal] = 0;
        }

        else if (tipoGrafo == false)
        {
            listaAdjVertice[verticeInicial].ligacao[verticeFinal] = 0;
            listaAdjVertice[verticeFinal].ligacao[verticeInicial] = 0;
        }
        if (listaAdjVertice[verticeInicial].ligacao[verticeFinal] == 0 || listaAdjVertice[verticeFinal].ligacao[verticeInicial] == 0)
            cout << "Você removeu a aresta que liga o vértice " << verticeInicial << " ao vértice " << verticeFinal << endl;
        qtdAresta--;
    }
    else
        cout << "Os valores de vértice Inicial e/ou vértice Final não foram encontrados." << endl;
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

int consultarPrimeiroAdjacente(int vertice)
{
    int i;
    for (i = 0; i <= qtdVertice; i++)
    {
        if (listaAdjVertice[vertice].ligacao[i] > 0)
        { // percorre até o primeiro adjacente e para
            cout << "O primeiro Adjacente é " << i << endl;
            return i;
        }
    }
    cout << "O vértice " << vertice << " não possui adjacências.";
    return -1;
}

int proximoAdjacente(int vertice, int partida)
{
    int result = -1;
    if (consultarSeAdjacente(vertice, partida) == true)
    {
        for (int i = partida + 1; i <= qtdVertice; i++) // começa a busca a partir do vértice que já é adjacente
        {
            if (listaAdjVertice[vertice].ligacao[i] != 0)
            {
                result = i;
                cout << "O próximo adjacente do Vértice " << vertice << " após o vértice " << partida << " é o " << result;
                return result;
                break;
            }
            if (result != -1)
            {
                cout << "O vértice " << vertice << " não possui adjacentes posteriores ao " << partida << ".\n";
                return 0;
                break;
            }
        }
    }
    if (consultarSeAdjacente(vertice, partida) == false)
    {
        cout << "Os vértices informados não são adjacentes.\n\n";
        return 0;
    }
}

void listaCompletaDoVerticeAdjacentes(int vertice)
{
    cout << "Lista de Adjacentes: " << endl;
    for (int j = 0; j < qtdVertice; j++)
        if (listaAdjVertice[vertice].ligacao[j] != 0)
            cout << j << endl;
}

///////////////////////////////////////// TRABALHO 2 /////////////////////////////////////////

void reiniciaGrafo()
{
    for (int i = 0; i < qtdVertice; i++)
    {
        listaAdjVertice[i].ant = (-1);
        listaAdjVertice[i].situacaoCor = 'b';
        listaAdjVertice[i].tempoDescoberta = 0;
        listaAdjVertice[i].tempoFinalizacao = 0;
        listaAdjVertice[i].distOrigem = __LONG_LONG_MAX__;
    }
}

int retornaIndice(string nome)
{
    for (int i = 0; i < qtdVertice; i++)
    {
        if (listaAdjVertice[i].conteudo.compare(nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

string retornaNome(int vertice)
{
    for (int i = 0; i < qtdVertice; i++)
    {
        if (vertice == i)
        {
            return listaAdjVertice[i].conteudo;
        }
    }
    return "";
}

void editaConteudoVertice()
{
    int indiceVertice;
    cout << "Indice\tConteúdo" << endl;
    for (int i = 0; i < qtdVertice; i++)
        cout << i << "\t" << listaAdjVertice[i].conteudo << endl;
    cout << "Digite o indice do vértice que terá o conteúdo alterado: ";
    cin >> indiceVertice;
    cin.ignore();
    if (indiceVertice < qtdVertice)
    {
        for (int i = 0; i < qtdVertice; i++)
        {
            if (i == indiceVertice)
            { // procura do vértice, para substituição do conteúdo
                cout << "Digite o novo conteudo do vértice: ";
                getline(cin, listaAdjVertice[i].conteudo);
                break;
            }
        }
    }
    else
    {
        cout << "O vértice digitado não pertence ao grafo.";
    }
}

void mostraInformacaoVertice(int vertice)
{
    cout << "\n\tIndice do vértice: " << vertice;
    cout << "\n\tLista de ligações: \n\t";
    for (int j = 0; j < qtdVertice; j++)
        cout << "\t\t" << listaAdjVertice[vertice].ligacao[j];
    cout << "\n\tConteúdo: " << listaAdjVertice[vertice].conteudo;
    cout << "\n\tAntecessor: " << listaAdjVertice[vertice].ant;
    cout << "\n\tSituação: " << listaAdjVertice[vertice].situacaoCor;
    cout << "\n\tTempo de Descoberta: " << listaAdjVertice[vertice].tempoDescoberta;
    cout << "\n\tTempo de finalização de processamento: " << listaAdjVertice[vertice].tempoFinalizacao;
    cout << "\n\tDistância em relação à origem: " << listaAdjVertice[vertice].distOrigem << endl;
}

// busca em profundidade
void visitaParaBuscaProfundidade(int vertice, int *tempoDescoberta)
{
    *tempoDescoberta = *tempoDescoberta + 1;
    if (listaAdjVertice[vertice].situacaoCor == 'b')
    {
        // Marcar o vértice como visitado
        listaAdjVertice[vertice].situacaoCor = 'c';
        listaAdjVertice[vertice].tempoDescoberta = *tempoDescoberta;
        cout << "\nInicio do processamento do vertice: " << vertice << endl;
        mostraInformacaoVertice(vertice);
        // Realizar repetição para os vizinhos do vértice
        for (int i = 0; i < qtdVertice; i++)
        {
            if (listaAdjVertice[vertice].ligacao[i] > 0)
            {
                listaAdjVertice[i].ant = vertice;
                // Verificar se o vizinho não foi visitado
                if (listaAdjVertice[i].situacaoCor == 'b')
                {
                    visitaParaBuscaProfundidade(i, tempoDescoberta);
                }
            }
        }
        // Marcar o vértice como visitado (preto) após visitar todos os vizinhos
        listaAdjVertice[vertice].situacaoCor = 'p';
        *tempoDescoberta = *tempoDescoberta + 1;
        listaAdjVertice[vertice].tempoFinalizacao = *tempoDescoberta;
        cout << "\nFim do processamento do vertice: " << vertice << endl;
        mostraInformacaoVertice(vertice);
    }
}

void visitaBuscaProfundidadeRemanescente(int *tempoDescoberta)
{ // garantir que todos sejam visitados
    int i;
    for (i = 0; i < qtdVertice; i++)
        if (listaAdjVertice[i].situacaoCor == 'b')
            visitaParaBuscaProfundidade(i, tempoDescoberta);
}

// busca em Largura
void buscalargura(int verticeOrigem, int *dist)
{
    queue<int> fila;
    // Marcar o vértice de origem como visitado e adicioná-lo à fila
    listaAdjVertice[verticeOrigem].situacaoCor = 'c';
    listaAdjVertice[verticeOrigem].distOrigem = *dist;
    cout << "\nInicio do processamento vértice " << verticeOrigem << endl;
    mostraInformacaoVertice(verticeOrigem);
    fila.push(verticeOrigem);

    // Loop principal
    while (!fila.empty())
    {
        int u = fila.front();
        *dist = *dist + 1;
        // Realizar a repetição sobre os vizinhos
        for (int i = 0; i < qtdVertice; i++)
        {
            if (listaAdjVertice[u].ligacao[i] > 0)
            {
                // Verificar se o vizinho não foi visitado
                if (listaAdjVertice[i].situacaoCor == 'b')
                {
                    listaAdjVertice[i].situacaoCor = 'c';
                    listaAdjVertice[i].ant = u;
                    listaAdjVertice[i].distOrigem = *dist;
                    fila.push(i);
                    cout << "\nInicio do processamento vértice " << i << endl;
                    mostraInformacaoVertice(i);
                }
            }
        }
        listaAdjVertice[u].situacaoCor = 'p';
        cout << "Fim do processamento vértice " << u << endl;
        mostraInformacaoVertice(u);
        fila.pop();
    }
}

void visitaBuscaLarguraRemanescente()
{
    int i, dist = 0;
    for (i = 0; i < qtdVertice; i++)
        if (listaAdjVertice[i].situacaoCor == 'b')
            buscalargura(i, &dist);
}

//  dijkstra
vector<pair<int, vector<int>>> dijkstraMenorCaminho(int verticeOrigem, int verticeDestino)
{

    set<pair<int, int>> pq;                     // Conjunto para armazenar pares (distância, vértice) ordenados pela distância, que iremos usar como priority queue
    vector<int> distancia(qtdVertice, INT_MAX); // Vetor para armazenar as distâncias mínimas de verticeOrigem para cada vértice
    vector<int> anterior(qtdVertice, -1);       // Vetor para armazenar o vértice anterior no caminho mínimo para cada vértice

    distancia[verticeOrigem] = 0;  // Inicializa a distância do vértice de origem como 0
    pq.insert({0, verticeOrigem}); // Insere o vértice de origem na fila de prioridade com distância 0

    while (!pq.empty())
    {
        int u = pq.begin()->second; // Extrai o vértice com a menor distância da fila de prioridade
        pq.erase(pq.begin());

        for (int v = 0; v < qtdVertice; ++v)
        {
            if (listaAdjVertice[u].ligacao[v] != 0) // vamos para os vertices vizinhos
            {
                if (distancia[u] != INT_MAX && distancia[u] + listaAdjVertice[u].ligacao[v] < distancia[v]) // Verifica se há uma aresta entre u e v e se há uma melhoria na distância
                {
                    pq.erase({distancia[v], v}); // vou apagar a distância para aquele vértice
                    distancia[v] = distancia[u] + listaAdjVertice[u].ligacao[v];
                    pq.insert({distancia[v], v}); // vou colocar a nova melhor distância lá
                    anterior[v] = u;              // vou falar quem é o anterior
                }
            }
        }
    }

    // vou guardar todo o caminho percorrido, para imprimi-lo depois, em outra função
    vector<int> caminho;
    int destino = verticeDestino;
    while (destino != -1)
    {
        caminho.insert(caminho.begin(), destino);
        destino = anterior[destino];
    }

    // Retorno duplo o resultado como um vetor contendo a distância e o caminho
    return {{distancia[verticeDestino], caminho}};
}

// Função para imprimir os menores caminhos encontrados
void imprimirMenoresCaminhos(int verticeOrigem, const vector<pair<int, vector<int>>> &resultados)
{
    cout << "Vértice Origem : " << verticeOrigem;
    for (const auto &resultado : resultados)
    {
        int destino = resultado.second.back(); // Obtém o vértice de destino a partir do caminho
        cout << "\nVértice Destino: " << destino;
        if (resultado.first == INT_MAX) // Verifica se o vértice é inalcançável
            cout << "Não alcançável";
        else
        {
            // Imprime o caminho percorrido, porém com os conteúdos dos vértices
            cout << "\nDistância: " << resultado.first << "\n\tCaminho: ";
            for (int j = 0; j < resultado.second.size(); j++)
            {
                cout << retornaNome(resultado.second[j]);
                if (j < resultado.second.size() - 1) // Adiciona setas entre os vértices
                    cout << " -> ";
            }
            cout << "\n";
            // Imprime novamente, desta vez, apenas os índices dos vértices
            cout << "\nDistância: " << resultado.first << "\n\tCaminho: ";
            for (int j = 0; j < resultado.second.size(); j++)
            {
                cout << resultado.second[j];
                if (j < resultado.second.size() - 1) // Adiciona setas entre os vértices
                    cout << " -> ";
            }
        }
    }
}

// arvore geradora Mínima
void kruskal()
{
    int pesoTotal = 0;
    vector<pair<int, pair<int, int>>> arestas; // Criar uma lista para armazenar todas as arestas, sem precisar do uso de struct
    for (int i = 0; i < qtdVertice; ++i)
        for (int j = 0; j < qtdVertice; ++j)
            if (listaAdjVertice[i].ligacao[j] != 0)
                arestas.push_back({listaAdjVertice[i].ligacao[j], {i, j}}); // Adicionar as arestas à lista
    sort(arestas.begin(), arestas.end());                                   // Ordenar as arestas por peso
    int pais[qtdVertice];                                                   // Criar um array para armazenar os pais de cada vértice
    for (int i = 0; i < qtdVertice; ++i)                                    // Inicializar os pais de cada vértice
        pais[i] = i;
    // Contador para contar o número de arestas adicionadas à árvore
    int contador = 0;
    for (const auto &aresta : arestas) // Percorrer as arestas ordenadas
    {
        int peso = aresta.first;
        int u = aresta.second.first;
        int v = aresta.second.second;
        int pai_u = u;
        int pai_v = v;
        // Verificar se adicionar a aresta forma um ciclo
        while (pais[pai_u] != pai_u)
            pai_u = pais[pai_u];
        while (pais[pai_v] != pai_v)
            pai_v = pais[pai_v];
        if (pai_u != pai_v)
        {
            cout << "Aresta " << u << " - " << v << "  = " << peso << endl;
            pesoTotal = peso + pesoTotal;
            contador++;
            // Unir os conjuntos dos vértices u e v
            pais[pai_u] = pai_v;
        }
        // Se todas as arestas necessárias foram adicionadas, sair do loop
        if (contador == qtdVertice - 1)
            break;
    }
    cout << "Peso total da arvore geradora mínima: " << pesoTotal;
}