# Compilador y flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Iinclude

# Directorios
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Archivos fuente y objetos
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLE := $(BIN_DIR)/clasifica

# Regla principal
all: $(EXECUTABLE)

# Regla para el ejecutable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regla para los objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Ejecución con datos de prueba
run: $(EXECUTABLE)
	./$(EXECUTABLE) < datosGrupos.txt

.PHONY: all clean run