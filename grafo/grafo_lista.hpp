#pragma once
#include "grafo_interface.hpp"
#include <vector>
#include <list>

using namespace std;

class GrafoLista : public Grafo {
private:
    vector<list<int>> lista;

public:
    explicit GrafoLista(int n) : lista(n) {}

    void adicionarAresta(int u, int v) override {
        lista[u].push_back(v);
        lista[v].push_back(u); // grafo não direcionado
    }

    vector<int> vizinhos(int v) const override {
        return vector<int>(lista[v].begin(), lista[v].end());
    }

    int tamanho() const override {
        return static_cast<int>(lista.size());
    }
};