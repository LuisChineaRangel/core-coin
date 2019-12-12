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
SRC=cambio.cpp greedy.cpp solucion.cpp moneda.cpp

# Objetos
OBJS=$(SRC:.cpp=.o)

all: Cambio

# Compila el programa
Cambio: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o Cambio
	
cambio.o: cambio.cpp greedy.o
greedy.o: greedy.cpp solucion.o
solucion.o: solucion.cpp moneda.o
moneda.o: moneda.cpp

# Elimina los ejecutables y los objetos creados
clean:
	@echo "Limpiando todo..."
	@rm -r *.o *.exe Cambio