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
AR = ar rvs
LDFLAGS = -L$(LIB) -lpaquete -lcontenedor

.PHONY: all clean mrproper genera_dir

#Directivas de compilación #TO DO

all : genera_dir $(BIN)/prueba
	@echo [+] FINALIZADO CON ÉXITO

$(BIN)/prueba : $(OBJ)/prueba.o $(LIB)/libpaquete.a $(LIB)/libcontenedor.a
	@echo [+] Generando ejecutable $(BIN)/prueba
	@$(CXX) -o $(BIN)/prueba $(OBJ)/prueba.o $(LDFLAGS)

$(OBJ)/paquete.o : $(SRC)/paquete.cpp $(INCLUDE)/paquete.h
	@echo [+] Generando objeto $(OBJ)/paquete.o
	@$(CXX) $(CXXFLAGS) -o $(OBJ)/paquete.o $(SRC)/paquete.cpp

$(OBJ)/contenedor.o : $(SRC)/contenedor.cpp $(INCLUDE)/contenedor.h $(INCLUDE)/paquete.h
	@echo [+] Generando objeto $(OBJ)/contenedor.o
	@$(CXX) $(CXXFLAGS) -o $(OBJ)/contenedor.o $(SRC)/contenedor.cpp

$(OBJ)/prueba.o : $(SRC)/prueba.cpp $(INCLUDE)/contenedor.h $(INCLUDE)/paquete.h
	@echo [+] Generando objeto $(OBJ)/prueba.o
	@$(CXX) $(CXXFLAGS) -o $(OBJ)/prueba.o $(SRC)/prueba.cpp

$(LIB)/libpaquete.a: $(OBJ)/paquete.o
	@echo [+] Generando librería $(LIB)/libpaquete.a
	@$(AR) $(LIB)/libpaquete.a $(OBJ)/paquete.o

$(LIB)/libcontenedor.a: $(OBJ)/contenedor.o
	@echo [+] Generando librería $(LIB)/libcontenedor.a
	@$(AR) $(LIB)/libcontenedor.a $(OBJ)/contenedor.o

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

mrproper: 
	@echo [+] Eliminando directorios $(BIN)/, $(OBJ)/ y $(LIB)/
	@rm -rf $(BIN) $(OBJ) $(LIB)