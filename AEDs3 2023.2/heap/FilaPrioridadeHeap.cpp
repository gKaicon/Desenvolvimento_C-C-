#include "FilaPrioridadeHeap.hpp"

// Cria uma nova fila de prioridade, aloca memória para ela e inicializa o contador de elementos.
fila_prioridade* cria_FilaPrio() {
    fila_prioridade* fp = new fila_prioridade;
    fp->qtd = 0; // Inicializa a quantidade de elementos como zero.
    return fp;   // Retorna o ponteiro para a nova fila de prioridade.
}

// Libera a memória alocada para a fila de prioridade.
void libera_FilaPrio(fila_prioridade* fp) {
    delete fp; // Libera a memória alocada para a fila.
}

// Consulta o paciente de maior prioridade na fila.
int consulta_FilaPrio(fila_prioridade* fp, char* nome) {
    if (fp == nullptr || fp->qtd == 0)
        return 0; // Retorna 0 se a fila está vazia ou é nula.

    strcpy(nome, fp->dados[0].nome); // Copia o nome do paciente de maior prioridade.
    return 1; // Retorna 1 indicando que a consulta foi bem-sucedida.
}

// Promove um elemento recém-inserido para sua posição correta no heap.
void promoverElemento(fila_prioridade* fp, int filho) {
    int pai;
    struct paciente temp;
    pai = (filho - 1) / 2; // Calcula o índice do pai do elemento.
    while ((filho > 0) && (fp->dados[pai].prio <= fp->dados[filho].prio)) {
        temp = fp->dados[filho];
        fp->dados[filho] = fp->dados[pai]; // Troca o elemento com o pai.
        fp->dados[pai] = temp; //fim da troca
        filho = pai;
        pai = (pai - 1) / 2; // Move para o pai do pai.
    }
}

// Insere um novo paciente na fila de prioridade.
int insere_FilaPrio(fila_prioridade* fp, char* nome, int prioridade) {
    if (fp == nullptr)
        return 0; // Retorna 0 se a fila é nula.

    if (fp->qtd == MAX)
        return 0; // Retorna 0 se a fila está cheia.

    // Insere o novo elemento e sua prioridade.
    strcpy(fp->dados[fp->qtd].nome, nome);
    fp->dados[fp->qtd].prio = prioridade;

    // Reorganiza o heap para manter as propriedades da fila de prioridade.
    promoverElemento(fp, fp->qtd);

    fp->qtd++; // Incrementa o contador de elementos.
    return 1;   // Retorna 1 para indicar a inserção bem-sucedida.
}

// Rebaixa um elemento para sua posição correta após a remoção do elemento de maior prioridade.
void rebaixarElemento(fila_prioridade* fp, int pai) {
    struct paciente temp;
    int filho = 2 * pai + 1; // Calcula o índice do filho esquerdo.
    while (filho < fp->qtd) {

        // Verifica se o filho direito tem prioridade maior.
        if (filho < fp->qtd - 1 && fp->dados[filho].prio < fp->dados[filho + 1].prio)
            filho++; // Avança para o filho seguinte.

        // Compara a prioridade do pai com a do filho.
        if (fp->dados[pai].prio >= fp->dados[filho].prio)
            break; // Encontrou a posição correta.

        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho]; // Troca o elemento com o filho.
        fp->dados[filho] = temp;

        pai = filho;
        filho = 2 * pai + 1; // Move para o próximo nível.
    }
}

// Remove o paciente de maior prioridade da fila.
int remove_FilaPrio(fila_prioridade* fp) {
    if (fp == nullptr)
        return 0; // Retorna 0 se a fila é nula.

    if (fp->qtd == 0)
        return 0; // Retorna 0 se a fila está vazia.

    fp->qtd--; // Decrementa o contador de elementos.
    fp->dados[0] = fp->dados[fp->qtd]; // Move o último elemento para a raiz.

    // Reorganiza o heap após a remoção.
    rebaixarElemento(fp, 0);

    return 1; // Retorna 1 para indicar a remoção bem-sucedida.
}

// Retorna a quantidade de elementos na fila.
int tamanho_FilaPrio(fila_prioridade* fp) {
    if (fp == nullptr)
        return -1; // Retorna -1 se a fila é nula.
    else
        return fp->qtd; // Retorna a quantidade de elementos.
}

// Verifica se a fila de prioridade está cheia.
int estaCheia_FilaPrio(fila_prioridade* fp) {
    if (fp == nullptr)
        return -1; // Retorna -1 se a fila é nula.
    return (fp->qtd == MAX); // Retorna 1 se a fila está cheia, 0 caso contrário.
}

// Verifica se a fila de prioridade está vazia.
int estaVazia_FilaPrio(fila_prioridade* fp) {
    if (fp == nullptr)
        return -1; // Retorna -1 se a fila é nula.
    return (fp->qtd == 0); // Retorna 1 se a fila está vazia, 0 caso contrário.
}

// Imprime os elementos da fila de prioridade junto com suas prioridades e índices.
void imprime_FilaPrio(fila_prioridade* fp) {
    if (fp == nullptr)
        return; // Retorna sem fazer nada se a fila é nula.

    for (int i = 0; i < fp->qtd; i++) 
        cout << i << ") Prio: " << fp->dados[i].prio << "\tNome: " << fp->dados[i].nome << endl;
    // Imprime o índice, prioridade e nome de cada paciente na fila.
}