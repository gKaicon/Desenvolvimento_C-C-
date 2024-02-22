#include "funcoes.cpp"

int main(){

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    
    ifstream inputFile("input.txt"); // Substitua 'input.txt' pelo caminho para o arquivo de entrada
    ofstream outputFile("output.txt"); // Substitua 'output.txt' pelo arquivo de saída desejado

    if (!inputFile) {
        cerr << "Erro: não foi possível abrir o arquivo de entrada." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Erro: não foi possível criar o arquivo de saída." << endl;
        return 1;
    }

    createtapes(inputFile);

    inputFile.close();

    // Abra todos os arquivos de fita para mesclagem
    vector<ifstream> tapeFiles;

    for (int tapeNum = 0; ; ++tapeNum) {
        ifstream tapeFile("tape_" + to_string(tapeNum) + ".txt");
        if (!tapeFile)
            break;
        tapeFiles.push_back(move(tapeFile));
    }

    mergetapes(outputFile, tapeFiles);

    for (auto& file : tapeFiles) {
        if (file.is_open())
            file.close();
    }

    outputFile.close();

    cout << "Ordenação externa concluída. Os dados classificados são salvos em 'output.txt'." << endl;

    return 0;
}
