# Nombre del ejecutable final
PROGRAMA := calc3

# Compilador
CC := gcc

# Regla principal
all: $(PROGRAMA)

# 1. Bison genera parser3.tab.c y parser3.tab.h a partir de parser3.y
parser3.tab.c parser3.tab.h: parser3.y
	bison -d parser3.y

# 2. Flex genera lex.yy.c (necesita parser3.tab.h)
lex.yy.c: scanner3.l parser3.tab.h
	flex scanner3.l

# 3. GCC compila ambos archivos .c para armar el ejecutable
$(PROGRAMA): lex.yy.c parser3.tab.c
	$(CC) lex.yy.c parser3.tab.c -o $(PROGRAMA)

# Regla para limpiar todos los archivos generados
clean:
	rm -f $(PROGRAMA) lex.yy.c parser3.tab.c parser3.tab.h

.PHONY: all clean