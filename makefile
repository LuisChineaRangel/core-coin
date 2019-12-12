# Luis Marcelo Chinea Rangel
# Computabilidad y Algoritmia
#---------------------------
# Makefile
#---------------------------

# Compilador
CXX=g++

# Flasgs del compilador
CXXFLAGS=-std=c++11

# Ficheros fuente
SRC=cambio.cpp greedy.cpp moneda.cpp

# Objetos
OBJS=$(SRC:.cpp=.o)

all: Cambio

# Compila el programa
Cambio: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o Cambio
	
cambio.o: cambio.cpp greedy.o
greedy.o: greedy.cpp moneda.o
moneda.o: moneda.cpp

# Tipos de archivos que NO borra el clean
MAKEFILE='makefile'
CPP="*.cpp"
HPP="*.hpp"

# Elimina los ejecutables y los objetos creados
clean:
	@echo "Limpiando todo..."
	@find . -maxdepth 1 -type f ! -name $(MAKEFILE) ! -name $(CPP) ! -name $(HPP) -delete