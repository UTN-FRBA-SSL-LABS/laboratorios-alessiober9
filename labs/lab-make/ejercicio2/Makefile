# Nombre del ejecutable final
PROGRAMA := scanner2

# Compilador
CC := gcc

# Regla principal
all: $(PROGRAMA)

# 1. Flex genera lex.yy.c a partir de scanner2.l
lex.yy.c: scanner2.l
	flex scanner2.l

# 2. GCC compila lex.yy.c para generar el ejecutable
$(PROGRAMA): lex.yy.c
	$(CC) lex.yy.c -o $(PROGRAMA)

# Regla para limpiar archivos generados
clean:
	rm -f $(PROGRAMA) lex.yy.c

.PHONY: all clean