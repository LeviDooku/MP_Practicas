############################
# Práctica 1 			   #
# file: Makefile		   #
# Pedro Velasco Santana    #
############################

#Variables (directorio y compilador)

HOME = .
BIN = $(HOME)/bin
INCLUDE = $(HOME)/include
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
SRC = $(HOME)/src

CXX = g++
CXXFLAGS = -c -I$(INCLUDE)
LDFLAGS = -L$(LIB) -loper2

.PHONY: all clean mrproper genera_dir

#Directivas de compilación

all : genera_dir $(BIN)/demo2 $(BIN)/demo
	@echo [+] FINALIZADO CON ÉXITO

$(BIN)/demo2 : $(OBJ)/demo2.o $(LIB)/liboper2.a
	@echo [+] Generando ejecutable $(BIN)/demo2
	@$(CXX) -o $(BIN)/demo2 $(OBJ)/demo2.o $(LDFLAGS)

$(BIN)/demo : $(OBJ)/demo2.o $(OBJ)/oper2.o
	@echo [+] Generando ejecutable $(BIN)/demo
	@$(CXX) -o $(BIN)/demo $(OBJ)/demo2.o $(OBJ)/oper2.o

$(OBJ)/demo2.o : $(SRC)/demo2.cpp $(INCLUDE)/oper2.h
	@echo [+] Generando objeto $(OBJ)/demo2.o
	@$(CXX) $(CXXFLAGS) -o $(OBJ)/demo2.o $(SRC)/demo2.cpp

$(OBJ)/oper2.o : $(SRC)/oper2.cpp $(INCLUDE)/oper2.h
	@echo [+] Generando objeto $(OBJ)/oper2.o
	@$(CXX) $(CXXFLAGS) -o $(OBJ)/oper2.o $(SRC)/oper2.cpp

$(LIB)/liboper2.a: $(OBJ)/oper2.o
	@echo [+] Generando librería $(LIB)/liboper2.a
	@ar rvs $(LIB)/liboper2.a $(OBJ)/oper2.o

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
	@rm -rf $(OBJ)/*.o $(BIN)/demo2 $(LIB)/liboper2.a

mrproper: clean
	@echo [+] Eliminando directorios $(BIN)/, $(OBJ)/ y $(LIB)/
	@rm -rf $(BIN) $(OBJ) $(LIB)