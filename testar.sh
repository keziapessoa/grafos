#!/bin/bash

echo "Compilando o projeto..."
make

echo ""
echo "Executando o programa com grafo de exemplo:"
./grafo

echo ""
echo "Limpando arquivos temporários..."
make limpar