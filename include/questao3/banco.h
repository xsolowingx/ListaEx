#ifndef _BANCO_H
#define _BANCO_H

#include "conta.h"
#include "contaCorrente.h"
#include "contaPoupanca.h"

void criarConta(std::vector<std::shared_ptr<Conta>> &contas);

void deposito(std::vector<std::shared_ptr<Conta>> &contas);
void saque(std::vector<std::shared_ptr<Conta>> &contas);
void deletarConta(std::vector<std::shared_ptr<Conta>> &contas);
void listarContas(std::vector<std::shared_ptr<Conta>> &contas);
void transferencia(std::vector<std::shared_ptr<Conta>> &contas);
void veSaldo(std::vector<std::shared_ptr<Conta>> &contas);
void extratoBancario(std::vector<std::shared_ptr<Conta>> &contas);

bool verificaConta(std::string &_agencia_,std::string &_numero_conta_,std::vector<std::shared_ptr<Conta>> &contas);
bool verificaSim_Nao();
void verificaSenha(Conta &contaP);

void mensagemInicio();
void menu();

void inputNumberI(std::string &number);
void inputNumberF(std::string &number);
void inputName(std::string &name);



#endif