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
DOC = $(HOME)/doc

CXX = g++
CXXFLAGS = -c -I$(INCLUDE)
AR = ar rvs
LDFLAGS = -L$(LIB) -lpaquete -lcontenedor

.PHONY: all clean mrproper genera_dir doc clean-doc

#Directivas de compilación

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

genera_dir: $(BIN)/ $(OBJ)/ $(LIB)/ $(DOC)/
	@echo [+] Directorios $(BIN)/, $(OBJ)/, $(LIB)/ y $(DOC) generados

$(BIN)/:
	@mkdir -p $(BIN)

$(OBJ)/:
	@mkdir -p $(OBJ)

$(LIB)/:
	@mkdir -p $(LIB)

$(DOC)/:
	@mkdir -p $()

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