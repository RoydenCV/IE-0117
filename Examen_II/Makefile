# Royden Contreras Vallejos
# C12260
# Esto es el segundo examen parcial de Porgramacion Bajo Plataformas Abiertas el
# cual consiste en definir una serie de variables para que el programa funcione 
# correctamente como nos indican en las intrucciones. 


# Definicion de variables
CC = gcc   # Definir el compilador
CFLAGS = -Wall   # Definir las banderas de compilación
SRC = main.c inventario.c   # Definir los archivos fuente
EXEC = programa.exe   # Definir el nombre del ejecutable
LIB = libinventario.a   # Definir el nombre de la biblioteca estática

# El target por defecto 'all'
all: $(EXEC)

# Target para generar el ejecutable principal
$(EXEC):
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

# Target para limpiar archivos temporales y ejecutables generados
clean:
	rm -f *.o $(EXEC) $(LIB)

# Target para ejecutar el programa compilado
run: $(EXEC)
	./$(EXEC)