#include "BST.hpp"

No *criarNo(Pessoa pessoa)
{
    No *novoNo = new No();
    novoNo->pessoa = pessoa;
    novoNo->esquerda = nullptr;
    novoNo->direita = nullptr;
    return novoNo;
}

No *inserirNo(No *raiz, Pessoa pessoa)
{
    if (raiz == nullptr)
    {
        raiz = criarNo(pessoa);
    }
    else if (pessoa.matricula < raiz->pessoa.matricula)
    {
        raiz->esquerda = inserirNo(raiz->esquerda, pessoa);
    }
    else
    {
        raiz->direita = inserirNo(raiz->direita, pessoa);
    }
    return raiz;
}

No *removerNo(No *raiz, int matricula)
{
    if (raiz == nullptr)
    {
        return raiz;
    }
    else if (matricula < raiz->pessoa.matricula)
    {
        raiz->esquerda = removerNo(raiz->esquerda, matricula);
    }
    else if (matricula > raiz->pessoa.matricula)
    {
        raiz->direita = removerNo(raiz->direita, matricula);
    }
    else
    {
        // Caso 1: Nó não possui filhos
        if (raiz->esquerda == nullptr && raiz->direita == nullptr)
        {
            delete raiz;
            cout << "Matricula removida.";
            raiz = nullptr;
        }
        // Caso 2: Nó possui apenas um filho
        else if (raiz->esquerda == nullptr)
        {
            No *temp = raiz;
            raiz = raiz->direita;
            delete temp;
            cout << "Matricula removida.";
        }
        else if (raiz->direita == nullptr)
        {
            No *temp = raiz;
            raiz = raiz->esquerda;
            delete temp;
            cout << "Matricula removida.";
        }
        // Caso 3: Nó possui dois filhos
        else
        {
            No *temp = raiz->direita;
            while (temp->esquerda != nullptr)
            {
                temp = temp->esquerda;
            }
            raiz->pessoa = temp->pessoa;
            raiz->direita = removerNo(raiz->direita, temp->pessoa.matricula);
            cout << "Matricula removida.";
        }
    }
    return raiz;
}

Pessoa criarPessoa()
{
    Pessoa pessoa;
    cout << "Matricula: ";
    cin >> pessoa.matricula;
    cin.ignore();
    cout << "CPF: ";
    getline(cin, pessoa.cpf);
    cout << "Nome: ";
    getline(cin, pessoa.nome);
    cout << "Data de nascimento - Dia: ";
    cin >> pessoa.data_nascimento.dia;
    cout << "Data de nascimento - Mês: ";
    cin >> pessoa.data_nascimento.mes;
    cout << "Data de nascimento - Ano: ";
    cin >> pessoa.data_nascimento.ano;
    cin.ignore();
    cout << "Endereço - Rua: ";
    getline(cin, pessoa.endereco.logradouro);
    cout << "Endereço - Numero: ";
    cin >> pessoa.endereco.numero;
    cin.ignore();
    cout << "Endereço - Bairro: ";
    getline(cin, pessoa.endereco.bairro);
    cout << "Endereço - CEP: ";
    getline(cin, pessoa.endereco.cep);
    cout << "Endereço - Cidade: ";
    getline(cin, pessoa.endereco.cidade);
    cout << "Endereço - Estado: ";
    getline(cin, pessoa.endereco.estado);
    cout << "Telefone: ";
    getline(cin, pessoa.telefone);
    cout << "Cargo: ";
    getline(cin, pessoa.cargo);
    return pessoa;
}

void imprimeItem(Pessoa pessoa)
{
    cout << "\nMatricula: " << pessoa.matricula
         << "\nCPF: " << pessoa.cpf
         << "\nNome: " << pessoa.nome
         << "\nData de nascimento - Dia: " << pessoa.data_nascimento.dia
         << "\nData de nascimento - Mês: " << pessoa.data_nascimento.mes
         << "\nData de nascimento - Ano: " << pessoa.data_nascimento.ano
         << "\nEndereço - Rua: " << pessoa.endereco.logradouro
         << "\nEndereço - Numero: " << pessoa.endereco.numero
         << "\nEndereço - Bairro: " << pessoa.endereco.bairro
         << "\nEndereço - CEP: " << pessoa.endereco.cep
         << "\nEndereço - Cidade: " << pessoa.endereco.cidade
         << "\nEndereço - Estado: " << pessoa.endereco.estado
         << "\nTelefone: " << pessoa.telefone
         << "\nCargo: " << pessoa.cargo << endl << endl;
}

No *buscarMatricula(No *raiz, int matricula)
{
    if (raiz == nullptr || raiz->pessoa.matricula == matricula)
    {
        imprimeItem(raiz->pessoa);
        return raiz;
    }
    if (raiz->pessoa.matricula < matricula)
        return buscarMatricula(raiz->direita, matricula);
    return buscarMatricula(raiz->esquerda, matricula);
}

No *buscarCPF(No *raiz, string cpf)
{
    if (raiz == nullptr || raiz->pessoa.cpf == cpf)
    {
        imprimeItem(raiz->pessoa);
        return raiz;
    }

    if (raiz->pessoa.cpf != cpf)
        return buscarCPF(raiz->direita, cpf);
    return buscarCPF(raiz->esquerda, cpf);
}

No *buscarNome(No *raiz, string nome)
{
    if (raiz == nullptr || (raiz->pessoa.nome == nome))
    {
        imprimeItem(raiz->pessoa);
        return raiz;
    }
    if (nome != raiz->pessoa.nome)
        return buscarNome(raiz->direita, nome);
    return buscarNome(raiz->esquerda, nome);
}


void removeMatricula(No *raiz){
    int matricula;
    cout << "Digite a matricula a ser Excluída(caso não se lembre, digite qualquer valor negativo e confira): ";
    cin >> matricula;
    removerNo(raiz, matricula);
    cout << endl;
    system("PAUSE");
}

void imprimeEmOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        imprimeEmOrdem(raiz->esquerda);
        imprimeItem(raiz->pessoa);
        imprimeEmOrdem(raiz->direita);
    }
}

void imprimePreOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        imprimeItem(raiz->pessoa);
        imprimePreOrdem(raiz->esquerda);
        imprimePreOrdem(raiz->direita);
    }
}

void imprimePosOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        imprimePosOrdem(raiz->esquerda);
        imprimePosOrdem(raiz->direita);
        imprimeItem(raiz->pessoa);
    }
}

void Busca(No *raiz, int op){
    int matricula;
    string nome, cpf;

    if(op == 1){
        cout << "CPF: ";
        getline(cin, cpf);
        buscarCPF(raiz, cpf);
    }
    if (op == 2)
    {
        cout << "Nome: ";
        getline(cin, nome);
        buscarNome(raiz, nome);
    }
    if (op == 3)
    {
        cout << "Matricula: ";
        cin >> matricula;
        cin.ignore();
        buscarMatricula(raiz, matricula);
    }
    system("PAUSE");
}

void imprime(No *raiz, int op){
    if(op == 1){
        imprimeEmOrdem(raiz);
    }
    if (op == 2){
        imprimePreOrdem(raiz);
    }
    if (op == 3){
        imprimePosOrdem(raiz);
    }
}

int menubusca(){
    int opB;
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        **                   ESCOLHA O MODO DE BUSCA                  **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 1 - BUSCA POR CPF                                          **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 2 - BUSCA POR NOME                                         **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 3 - BUSCA POR MATRICULA                                    **";
    cout << "  \n        **                                                            **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************\n\n";
    cout << "Opção: ";
    cin >> opB;
    cin.ignore();
    return opB;
}

void menu(){
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        **                      MENU-PRINCIPAL                        **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 1 - CADASTRAR FUNCIONÁRIO                                  **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 2 - BUSCAR FUNCIONÁRIO                                     **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 3 - REMOVER FUNCIONÁRIO                                    **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 4 - IMPRIMIR                                               **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 5 - SAIR                                                   **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************\n\n";
    cout << "Opção: ";
}

int menuimprimir(){
    int opI;
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        **                ESCOLHA O MODO DE IMPRESSÃO                 **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 1 - IMPRESSÃO EM ORDEM                                     **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 2 - IMPRESSÃO PRÉ-ORDEM                                    **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ** 3 - IMPRESSÃO PÓS-ORDEM                                    **";
    cout << "  \n        **                                                            **";
    cout << "  \n        ****************************************************************";
    cout << "  \n        ****************************************************************\n\n";
    cout << "Opção: ";
    cin >> opI;
    if (opI == 1) cout << "\nImpressão em ordem.\n\n";
    if (opI == 2) cout << "\nImpressão pré-ordem.\n\n";
    if (opI == 3) cout << "\nImpressão pós-ordem.\n\n";
        
    return opI;
}