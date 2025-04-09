#pragma once
#include "grafo_interface.hpp"
#include <vector>

using namespace std;

class GrafoMatriz : public Grafo {
private:
    vector<vector<bool>> matriz;

public:
    explicit GrafoMatriz(int n) : matriz(n, vector<bool>(n, false)) {}

    void adicionarAresta(int u, int v) override {
        matriz[u][v] = true;
        matriz[v][u] = true; // grafo não direcionado
    }

    vector<int> vizinhos(int v) const override {
        vector<int> viz;
        for (size_t i = 0; i < matriz[v].size(); ++i)
            if (matriz[v][i]) viz.push_back(i);
        return viz;
    }

    int tamanho() const override {
        return static_cast<int>(matriz.size());
    }
};