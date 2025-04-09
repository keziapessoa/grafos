# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -I./

# Arquivos fonte e executável
FONTE = main.cpp
EXECUTAVEL = grafo

# Regra principal
tudo: $(EXECUTAVEL)

$(EXECUTAVEL): $(FONTE)
	$(CXX) $(CXXFLAGS) $(FONTE) -o $(EXECUTAVEL)

# Limpeza dos arquivos gerados
limpar:
	rm -f $(EXECUTAVEL)