#include "grafo/grafo_lista.hpp"
#include "grafo/grafo_matriz.hpp"
#include "busca/bfs.hpp"
#include "busca/dfs_pilha.hpp"

#include <fstream>
#include <iostream>
#include <memory>

using namespace std;

unique_ptr<Grafo> carregarGrafo(const string& caminho, bool usarMatriz = false) {
    ifstream arquivo(caminho);
    int n, u, v;
    arquivo >> n;

    unique_ptr<Grafo> grafo = usarMatriz
        ? make_unique<GrafoMatriz>(n)
        : make_unique<GrafoLista>(n);

    while (arquivo >> u >> v)
        grafo->adicionarAresta(u, v);

    return grafo;
}

int main() {
    auto grafo = carregarGrafo("dados/grafo.txt", false);

    cout << "DFS (profundidade) a partir do vértice 0:\n";
    dfs_iterativo(*grafo, 0);

    cout << "\nBFS (largura) - caminho de 0 a 4:\n";
    bfs_caminho(*grafo, 0, 4);

    return 0;
}