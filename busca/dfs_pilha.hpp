#pragma once
#include "grafo/grafo_interface.hpp"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void dfs_iterativo(const Grafo& g, int inicio) {
    vector<bool> visitado(g.tamanho(), false);
    stack<int> pilha;

    pilha.push(inicio);

    while (!pilha.empty()) {
        int atual = pilha.top();
        pilha.pop();

        if (!visitado[atual]) {
            visitado[atual] = true;
            cout << atual << " ";

            for (int viz : g.vizinhos(atual)) {
                if (!visitado[viz])
                    pilha.push(viz);
            }
        }
    }
    cout << "\n";
}