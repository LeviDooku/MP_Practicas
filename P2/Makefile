############################
# Práctica 2               #
# file: Makefile           #
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
LDFLAGS = -L$(LIB) -lproceso

.PHONY: all clean mrproper genera_dir doc clean-doc

#Directivas de compilación

all : genera_dir $(BIN)/main 

$(BIN)/main : $(OBJ)/main.o $(LIB)/libproceso.a
	@echo [+] Generando ejecutable $(BIN)/main
	@$(CXX) -o $(BIN)/main $(OBJ)/main.o $(LDFLAGS)

$(OBJ)/main.o : $(SRC)/main.cpp $(INCLUDE)/proceso.h 
	@echo [+] Generando objeto $(OBJ)/main.o
	@$(CXX) $(CXXFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/proceso.o : $(SRC)/proceso.cpp $(INCLUDE)/proceso.h
	@echo [+] Generando objeto $(OBJ)/proceso.o
	@$(CXX) $(CXXFLAGS) -o $(OBJ)/proceso.o $(SRC)/proceso.cpp

$(LIB)/libproceso.a: $(OBJ)/proceso.o
	@echo [+] Generando librería $(LIB)/libproceso.a
	@$(AR) $(LIB)/libproceso.a $(OBJ)/proceso.o

#Directivas para la generacion de directorios, clean  y mrproper

genera_dir: $(BIN)/ $(OBJ)/ $(LIB)/
	@echo [+] Directorios $(BIN)/, $(OBJ)/ y $(LIB)/ generados

$(BIN)/:
	@mkdir -p $(BIN)

$(OBJ)/:
	@mkdir -p $(OBJ)

$(LIB)/:
	@mkdir -p $(LIB)

clean:
	@echo [+] Eliminando ficheros objeto, ejecutable y librería
	@rm $(OBJ)/*.o 

mrproper: clean-doc
	@echo [+] Eliminando directorios $(BIN), $(OBJ) y $(LIB)
	@rm -rf $(BIN) $(OBJ) $(LIB) $(DOC)

doc:
	@echo [+] Generando documentación con Doxygen
	@doxygen $(DOC)/Doxyfile
	@echo [+] Documentación generada en ./doc/html/index.html

clean-doc:
	@rm -rf $(DOC)/html $(DOC)/latex
	@echo [+] Documentación eliminada.