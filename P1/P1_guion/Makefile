############################
# Práctica 1 (guion)       #
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

CXX = g++
CXXFLAGS = -c -I$(INCLUDE)
LDFLAGS = -L$(LIB) #completar librerías 

.PHONY: all clean mrproper genera_dir

#Directivas de compilación #TO DO

all : 

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

mrproper: clean
	@echo [+] Eliminando directorios $(BIN)/, $(OBJ)/ y $(LIB)/
	@rm -rf $(BIN) $(OBJ) $(LIB)