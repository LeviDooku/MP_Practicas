############################
# Práctica 3               #
# file: makefile           #
# Pedro Velasco Santana    #
############################

#Variables (directorio y compilador)

HOME = .
BIN = $(HOME)/bin
INCLUDE = $(HOME)/include
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
SRC = $(HOME)/src
DOC = $(HOME)/doc

CXX = g++
CXXFLAGS = -c -I$(INCLUDE)
AR = ar rvs
LDFLAGS = -L$(LIB) -lfunc

#Detectar Binarios

CPP_SOURCE      = $(filter-out $(SRC)/funcArrays.cpp, $(wildcard $(SRC)/*.cpp))
BINARIES        = $(patsubst $(SRC)/%.cpp, $(BIN)/%, $(CPP_SOURCE))

.PHONY: all clean mrproper genera_dir doc clean-doc

#Directivas de compilación

all: genera_dir $(LIB)/libfunc.a $(BINARIES)
	@echo "[+] Todo está compilado correctamente"

$(OBJ)/funcArrays.o: $(SRC)/funcArrays.cpp $(INCLUDE)/funcArrays.h
	@echo "[+] Generando objeto funcArrays.o"
	@$(CXX) $(CXXFLAGS) -o $@ $<

$(LIB)/libfunc.a: $(OBJ)/funcArrays.o
	@echo "[+] Generando librería libfunc.a"
	@$(AR) $@ $<

$(BIN)/%: $(SRC)/%.cpp $(LIB)/libfunc.a
	@echo "[+] Compilando $@..., primer requisito $<"
	@$(CXX) -o $@ $< $(LDFLAGS)

#Directiva genera_dir

genera_dir: $(BIN)/ $(OBJ)/ $(LIB)/
	@echo [+] Directorios $(BIN)/, $(OBJ)/ y $(LIB)/ generados

$(BIN)/:
	@mkdir -p $(BIN)

$(OBJ)/:
	@mkdir -p $(OBJ)

$(LIB)/:
	@mkdir -p $(LIB)

#Directivas clean y mrproper

clean:
	@echo [+] Eliminando ficheros objeto, ejecutable y librería
	@rm $(OBJ)/*.o

mrproper: clean-doc
	@echo [+] Eliminando directorios $(BIN), $(OBJ) y $(LIB)
	@rm -rf $(BIN) $(OBJ) $(LIB) $(DOC)

#Directivas para generación de documentación 

doc:
	@echo [+] Generando documentación con Doxygen
	@doxygen $(DOC)/Doxyfile
	@echo [+] Documentación generada en ./doc/html/index.html

clean-doc:
	@rm -rf $(DOC)/html $(DOC)/latex
	@echo [+] Documentación eliminada.