#pragma once
#include <vector>

using namespace std;

class Grafo {
public:
    virtual void adicionarAresta(int u, int v) = 0;
    virtual vector<int> vizinhos(int v) const = 0;
    virtual int tamanho() const = 0;
    virtual ~Grafo() = default;
};