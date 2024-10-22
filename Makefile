# Makefile actualizado para incluir todos los subdirectorios de 'include/'

# Directorios de origen y de objetos
SRC=src
OBJ=obj

# Bandera del compilador y las librerías
CC=g++
LDFLAGS= -lbcm2835 -lrt -lSSD1306_OLED_RPI -lmpg123 -lao -pthread
STD=-std=c++17

# Buscar todos los directorios en 'include' y agregarles '-I'
INCLUDES = $(shell find include -type d -exec echo -I{} \;)

# Flags del compilador, incluyendo los directorios encontrados y el estándar de C++
CFLAGS = $(STD) $(INCLUDES) -c -Wall -Wextra 

# Comando para crear directorios
MD=mkdir

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC)/*.cpp $(SRC)/*/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

# Directorio de binarios
BIN=./bin
TARGET=$(BIN)/bt_oled_mp3_app

# Opción por defecto
all: clean pre-build $(TARGET) 

# Opción para ejecutar la aplicación
run:
	sudo $(TARGET)

# Crear directorios si no existen
pre-build:
	@echo '*******'
	@echo '[START!]'
	@echo 'Building: ' $(SRC)
	$(MD) -vp $(BIN)
	$(MD) -vp $(OBJ)
	$(foreach dir,$(sort $(dir $(OBJS))), $(MD) -vp $(dir);)

# Compilar el ejecutable
$(TARGET): $(OBJS) $(OBJ)
	@echo '[MAKE EXE FILE!]'
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo '[DONE!]'

# Compilar los archivos .cpp en objetos .o y crear directorios si no existen
$(OBJ)/%.o : $(SRC)/%.cpp
	@echo '[MAKE OBJECT FILE!]'
	$(MD) -vp $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

# Limpiar objetos y binarios
clean:
	@echo '*******'
	@echo '[CLEANUP!]'
	rm -vf $(OBJS) $(TARGET)
	@echo '[DONE!]'
