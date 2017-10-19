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
CFLAGS = -W -Wall -pedantic -ansi -O0 -g -std=c++11 -I. -I$(INC_DIR)/questao1 -I$(INC_DIR)/questao2 -I$(INC_DIR)/questao3
#variáveis de diretórios.
INC_DIR = ./include
BIN_DIR = ./bin
SRC_DIR = ./src
OBJ_DIR = ./build
DOC_DIR = ./doc
#variáveis objetos.
OBJETO1 = $(OBJ_DIR)/questao1/bebida.o $(OBJ_DIR)/questao1/fruta.o $(OBJ_DIR)/questao1/produto.o\
$(OBJ_DIR)/questao1/roupa.o $(OBJ_DIR)/questao1/main1.o

OBJETO2 = $(OBJ_DIR)/questao2/operation.o $(OBJ_DIR)/questao2/account.o\
$(OBJ_DIR)/questao2/main2.o $(OBJ_DIR)/questao2/bank.o

OBJETO3 = $(OBJ_DIR)/questao3/banco.o $(OBJ_DIR)/questao3/conta.o\
$(OBJ_DIR)/questao3/contaCorrente.o $(OBJ_DIR)/questao3/operacao.o\
$(OBJ_DIR)/questao3/contaPoupanca.o $(OBJ_DIR)/questao3/main3.o


#Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy


all:	questao1 questao2 questao3

questao1:	$(OBJETO1)
	@echo "====================="
	@echo "Ligando o alvo $@"
	@echo "=========*-*========="
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@ 
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "=========*-*========="

$(OBJ_DIR)/questao1/main1.o:	$(SRC_DIR)/questao1/main1.cpp
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/produto.o:	$(SRC_DIR)/questao1/produto.cpp
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/fruta.o:	$(SRC_DIR)/questao1/fruta.cpp
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/bebida.o:	$(SRC_DIR)/questao1/bebida.cpp
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/roupa.o:	$(SRC_DIR)/questao1/roupa.cpp
	$(CC) -c $(CFLAGS) $< -o $@

questao2:	$(OBJETO2)
	@echo "====================="
	@echo "Ligando o alvo $@"
	@echo "=========*-*========="
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@ 
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "=========*-*========="

$(OBJ_DIR)/questao2/operation.o:	$(SRC_DIR)/questao2/operation.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/questao2/account.o:	$(SRC_DIR)/questao2/account.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/questao2/main2.o:	$(SRC_DIR)/questao2/main2.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/questao2/bank.o:	$(SRC_DIR)/questao2/bank.cpp
	$(CC) $(CFLAGS) -c $< -o $@

questao3:	$(OBJETO3)
	@echo "====================="
	@echo "Ligando o alvo $@"
	@echo "=========*-*========="
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@ 
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "=========*-*========="

$(OBJ_DIR)/questao3/teste.o:	$(SRC_DIR)/questao3/teste.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/questao3/conta.o:	$(SRC_DIR)/questao3/conta.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/questao3/contaPoupanca.o:	$(SRC_DIR)/questao3/contaPoupanca.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/questao3/contaCorrente.o:	$(SRC_DIR)/questao3/contaCorrente.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/questao3/operacao.o:	$(SRC_DIR)/questao3/operacao.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/questao3/main3.o:	$(SRC_DIR)/questao3/main3.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/questao3/banco.o:	$(SRC_DIR)/questao3/banco.cpp
	$(CC) $(CFLAGS) -c $< -o $@