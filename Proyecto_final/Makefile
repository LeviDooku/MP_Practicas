############################
# Proyecto final           #
# file: Makefile           #
# Pedro Velasco Santana    #
############################

# Variables (directorios y compilador)

HOME = .
BIN = $(HOME)/bin
INCLUDE = $(HOME)/include
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
SRC = $(HOME)/src
DOC = $(HOME)/doc

CXX = g++
CXXFLAGS = -c -I$(INCLUDE) -Wall -Wextra -std=c++11

# Detectar archivos fuente y generar binarios

CPP_SOURCE = $(wildcard $(SRC)/*.cpp)
OBJ_FILES = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(CPP_SOURCE))
TARGET = $(BIN)/main

.PHONY: all clean mrproper genera_dir doc clean-doc

#Directivas de compilación

all: genera_dir $(TARGET)
	@echo "[+] Compilación finalizada correctamente"

$(TARGET): $(OBJ_FILES) $(OBJ)/main.o
	@echo "[+] Generando ejecutable $(TARGET)"
	@$(CXX) -o $@ $(OBJ)/main.o $(OBJ_FILES)

$(OBJ)/main.o: main.cpp
	@echo "[+] Compilando main.cpp"
	@$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	@echo "[+] Compilando $<"
	@$(CXX) $(CXXFLAGS) -o $@ $<

#Crear directorios si no existen

genera_dir: $(BIN)/ $(OBJ)/ $(LIB)/ 
	@echo "[+] Directorios creados: $(BIN), $(OBJ), $(LIB)"

$(BIN)/:
	@mkdir -p $(BIN)

$(OBJ)/:
	@mkdir -p $(OBJ)

$(LIB)/:
	@mkdir -p $(LIB)

#Limpiar ficheros objeto y ejecutables

clean:
	@echo "[+] Limpiando ficheros objeto y ejecutables"
	@rm -rf $(OBJ) $(BIN) $(LIB)

#Eliminar todo

mrproper: clean clean-doc
	@echo "[+] Limpiando ficheros objeto, ejecutables y documentación"

#Generar documentación (opcional)

doc:
	@echo "[+] Generando documentación con Doxygen"
	@doxygen $(DOC)/Doxyfile
	@echo "[+] Documentación generada en ./doc/html/index.html"

clean-doc:
	@echo "[+] Limpiando documentación"
	@rm -rf $(DOC)/html $(DOC)/latex
