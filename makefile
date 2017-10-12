#Algumas variaveis sao usadas com significado especial:
#$@ nome do alvo (target)
#$^ lista com os nomes de todos os pre-requisitos sem duplicatas
#$< nome do primeiro pre-requisito
# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM = rm -rf
#variáveis de compilação.
CC = g++
CFLAGS = -W -Wall -pedantic -ansi -O0 -g -std=c++11 -I. -I$(INC_DIR)/questao1 
#variáveis de diretórios.
INC_DIR = ./include
BIN_DIR = ./bin
SRC_DIR = ./src
OBJ_DIR = ./build
DOC_DIR = ./doc
#variáveis objetos.
OBJETO1 = $(OBJ_DIR)/questao1/main1.o $(OBJ_DIR)/questao1/fruta.o $(OBJ_DIR)/questao1/bebida.o \
$(OBJ_DIR)/questao1/produto.o $(OBJ_DIR)/questao1/roupa.o
#variáveis arquivos .h
ARQ_H1 = $(INC_DIR)/questao1/fruta.h $(INC_DIR)/questao1/roupa.h $(INC_DIR)/questao1/produto.h \
$(INC_DIR)/questao1/bebida.h
#Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

questao1:	$(OBJETO1)
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "========s====="
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/questao1 
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/questao1/main1.o:	$(SRC_DIR)/questao1/main1.cpp $(ARQ_H1)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/produto.o:	$(SRC_DIR)/questao1/produto.cpp $(ARQ_H1)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/fruta.o:	$(SRC_DIR)/questao1/fruta.cpp $(ARQ_H1)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/bebida.o:	$(SRC_DIR)/questao1/bebida.cpp $(ARQ_H1)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/roupa.o:	$(SRC_DIR)/questao1/roupa.cpp $(ARQ_H1)
	$(CC) $(CFLAGS) $< -o $@
