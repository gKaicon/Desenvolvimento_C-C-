#include "BST.cpp"

int main() {
    steady_clock::time_point tempoinicio = steady_clock::now();
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    int op;
    No *raiz = nullptr;    // Criando a raiz da árvore

    //inserção de pessoas para teste
    Pessoa pessoa0;
    pessoa0.matricula = 4;
    pessoa0.cpf = "987.456.321-34";
    pessoa0.nome = "Joao Vitor Mendes";
    pessoa0.data_nascimento.dia = 8;
    pessoa0.data_nascimento.mes = 12;
    pessoa0.data_nascimento.ano = 2003;
    pessoa0.endereco.logradouro = "Rua X";
    pessoa0.endereco.numero = 101;
    pessoa0.endereco.bairro = "Pito";
    pessoa0.endereco.cep = "3570500";
    pessoa0.endereco.cidade = "GHS";
    pessoa0.endereco.estado = "MG";
    pessoa0.telefone = "(33) 9 8876-5432";
    pessoa0.cargo = "Monitor FSI";
    raiz = inserirNo(raiz, pessoa0);

    Pessoa pessoa1;
    pessoa1.matricula = 8;
    pessoa1.cpf = "912.654.372-09";
    pessoa1.nome = "Manda";
    pessoa1.data_nascimento.dia = 1;
    pessoa1.data_nascimento.mes = 11;
    pessoa1.data_nascimento.ano = 2004;
    pessoa1.endereco.logradouro, "Rua Y";
    pessoa1.endereco.numero = 121;
    pessoa1.endereco.bairro = "Centro";
    pessoa1.endereco.cep = "39705000";
    pessoa1.endereco.cidade = "SJE";
    pessoa1.endereco.estado = "MG";
    pessoa1.telefone = " (33) 9 8876-5432";
    pessoa1.cargo = "Monitora de Inglês";
    raiz = inserirNo(raiz, pessoa1);

    Pessoa pessoa2;
    pessoa2.matricula = 2;
    pessoa2.cpf = "916.984.372-00";
    pessoa2.nome = "Eduardo Trindade";
    pessoa2.data_nascimento.dia = 15;
    pessoa2.data_nascimento.mes = 02;
    pessoa2.data_nascimento.ano = 1992;
    pessoa2.endereco.logradouro = "Rua Z";
    pessoa2.endereco.numero = 101;
    pessoa2.endereco.bairro = "Conjunto Habitacional Vale das teclas";
    pessoa2.endereco.cep = "3765000";
    pessoa2.endereco.cidade = "Diamantina";
    pessoa2.endereco.estado = "MG";
    pessoa2.telefone = "33988765432";
    pessoa2.cargo = "Professor AEDs";
    raiz = inserirNo(raiz, pessoa2);
    
    Pessoa pessoa3;
    pessoa3.matricula = 12;
    pessoa3.cpf = "093.325.856-95";
    pessoa3.nome = "Gabriel Kaicon";
    pessoa3.data_nascimento.dia = 21;
    pessoa3.data_nascimento.mes = 01;
    pessoa3.data_nascimento.ano = 2004;
    pessoa3.endereco.logradouro = "Rua X";
    pessoa3.endereco.numero = 101;
    pessoa3.endereco.bairro = "Pombal";
    pessoa3.endereco.cep = "3970500";
    pessoa3.endereco.cidade = "SJE";
    pessoa3.endereco.estado = "MG";
    pessoa3.telefone = "33988765432";
    pessoa3.cargo = "Monitor de Banco de Dados";
    raiz = inserirNo(raiz, pessoa3);

    do{
        system("cls");
        menu();
        cin >> op;
        switch (op){
            case 1:
                system("cls");
                int opC;
                opC = 1;
                while(opC != 0){
                    Pessoa pessoa = criarPessoa();
                    raiz = inserirNo(raiz, pessoa);
                    cout << "Deseja inserir um novo funcionário? \n1 - Sim \n0 - Não\nOpção: ";
                    cin >> opC;
                    if(opC == 0)break;
                }
                break;
            case 2:
                system("cls");
                Busca(raiz, menubusca());
                break;
            case 3:
                system("cls");
                removeMatricula(raiz);
                break;
            case 4:
                system("cls");
                imprime(raiz, menuimprimir());
                system("PAUSE");
                break;
        }
    }while(op != 5);

    cout << "\n\n";
    
    steady_clock::time_point tempofim = steady_clock::now();
    duration<double> tempo = duration_cast<duration<double>>(tempofim - tempoinicio);
    cout << endl << "Tempo de Execução:" << tempo.count() << " segundos" << endl;
    return 0;
}