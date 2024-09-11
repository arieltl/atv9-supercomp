#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>  // Para medir o tempo de execução
#include <fstream> // Para manipulação de arquivos

using namespace std;
using namespace std::chrono;

// Estrutura para armazenar o valor e o peso
struct Item {
    int peso;
    int valor;
};

// Função para preencher a mochila pega os itens mais leves primeiro
pair<int, int> preencherMochilaAleatoria(int W, vector<Item>& itens) {
    
    sort(itens.begin(), itens.end(), [](const Item& a, const Item& b) {
        return a.peso < b.peso;
    });

    int pesoOcupado = 0;
    int valorTotal = 0;

    // Percorrer os itens e tentar colocar na mochila
    for (const auto& item : itens) {
        if (pesoOcupado + item.peso <= W) {
            pesoOcupado += item.peso;
            valorTotal += item.valor;
        }
    }

    // Retornar o peso ocupado e o valor alcançado
    return {pesoOcupado, valorTotal};
}



int main() {
    int N, W;
    cin >> N >> W;

    vector<Item> itens(N);

    for (int i = 0; i < N; i++) {
        cin >> itens[i].peso >> itens[i].valor;
    }

    // Capturar o tempo de início para o preenchimento aleatório
    auto inicioAleatorio = high_resolution_clock::now();

    // Executa a função de preenchimento aleatório
    auto resAleatorio = preencherMochilaAleatoria(W, itens);

    // Capturar o tempo de fim para o preenchimento aleatório
    auto fimAleatorio = high_resolution_clock::now();

    // Calcular o tempo de execução do preenchimento aleatório em milissegundos
    auto duracaoAleatorio = duration_cast<milliseconds>(fimAleatorio - inicioAleatorio).count();

    // Imprimir os resultados do preenchimento aleatório
    cout << "Preenchimento mais leve:\n";
    cout << "Peso ocupado: " << resAleatorio.first << " Kg, Valor alcançado: " << resAleatorio.second << " dinheiros\n";
    cout << "Tempo de execução: " << duracaoAleatorio << " ms\n";

    // Salvar o resultado no arquivo "resultados.txt"

    return 0;
}
