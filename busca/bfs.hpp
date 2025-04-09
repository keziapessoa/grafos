#pragma once
#include "grafo/grafo_interface.hpp"
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <iostream>

using namespace std;

void bfs_caminho(const Grafo& g, int origem, int destino) {
    vector<bool> visitado(g.tamanho(), false);
    unordered_map<int, int> pai;

    queue<int> fila;
    fila.push(origem);
    visitado[origem] = true;

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();

        for (int viz : g.vizinhos(atual)) {
            if (!visitado[viz]) {
                visitado[viz] = true;
                pai[viz] = atual;
                fila.push(viz);
            }
        }
    }

    if (!visitado[destino]) {
        cout << "Não há caminho entre os vértices " << origem << " e " << destino << ".\n";
        return;
    }

    stack<int> caminho;
    for (int v = destino; v != origem; v = pai[v])
        caminho.push(v);
    caminho.push(origem);

    cout << "Caminho de " << origem << " a " << destino << ": ";
    while (!caminho.empty()) {
        cout << caminho.top() << " ";
        caminho.pop();
    }
    cout << "\n";
}