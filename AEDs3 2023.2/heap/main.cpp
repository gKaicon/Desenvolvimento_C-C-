#include "FilaPrioridadeHeap.cpp"

int main() {

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    FilaPrio* fp = cria_FilaPrio();
    paciente itens[6] = {{"Andre", 1}, {"Bianca", 2},{"Carlos", 5}, {"Nilza", 8}, {"João Vitor", 6}, {"Kaicon", 4} };
    
    cout << "\n\nHeap como foi inserido" <<  endl;
    for (int i = 0; i < 6; i++) {
        cout << i << ") Prio: " << itens[i].prio << " nome: " << itens[i].nome << endl;
        insere_FilaPrio(fp, itens[i].nome, itens[i].prio);
    }
    cout << "\nHeap após o primeiro rearranjo" << endl;
    cout << "=================================" << endl;
    imprime_FilaPrio(fp);

    // teste
    cout << "Heap com a inserção do Teste, e obviamente executando o rearranjo" << endl;
    cout << "=================================" << endl;
    insere_FilaPrio(fp, "Teste", 9);
    imprime_FilaPrio(fp);

    cout << "Heap 'jogando' o maior para o final, e desconsiderando ele como informação, e imprimindo o restante" << endl;
    cout << "=================================" << endl;
    remove_FilaPrio(fp);
    imprime_FilaPrio(fp);

    cout << "Impressão final de como a fila está, após o rearranjo" << endl;
    cout << "=================================" << endl;
    for (int i = 0; i < 6; i++) {
        char nome[30];
        consulta_FilaPrio(fp, nome);
        cout << i << ") " << nome << endl;
        remove_FilaPrio(fp);
    }

    libera_FilaPrio(fp);
    return 0;
}