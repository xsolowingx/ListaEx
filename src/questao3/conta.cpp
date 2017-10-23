/**
 *@since 15/10/2017
 *@file conta.cpp
 *@brief arquivo onde contém as implementações da classe Conta.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 23/10/2017
 */
#include "conta.h"
#include <iostream>

int Conta::totalContas= 0;

int Conta::getTotalContas()
{
	return totalContas;
}

/*=====Construtores e o Destrutor padrão=====*/

Conta::Conta() {}

Conta::Conta(std::string _agencia,std::string _numero_conta,std::string _senha,std::string _titular,TipoConta _tipo_da_conta):
	agencia(_agencia), numero_conta(_numero_conta), senha(_senha), titular(_titular),tipo_da_conta(_tipo_da_conta), saldo(0.00)
	{
		totalContas++;
	}

Conta::~Conta() {}

/*=====Membros que retornam o iterador para operações=====*/

std::vector<std::shared_ptr<Operacao>>::iterator Conta::operacoesBEGIN()
{
	return this->operacoes.begin();
}

std::vector<std::shared_ptr<Operacao>>::iterator Conta::operacoesEND()
{
	return this->operacoes.end();
}

/*=====Adiciona uma operação à conta=====*/

void Conta::addOperacao(std::shared_ptr<Operacao> _operacao)
{
	this->operacoes.push_back(_operacao);
}

/*=====Setters=====*/
void Conta::setSaldo(float _saldo_)
{
	this->saldo = _saldo_;
}

/*=====Getters=====*/

std::string Conta::getAgencia() const
{
	return this->agencia;
}

std::string Conta::getNumeroConta() const
{
	return this->numero_conta;
}

TipoConta Conta::getTipoConta() const
{
	return this->tipo_da_conta;
}

std::string Conta::getSenha() const
{
	return this->senha;
}

std::string Conta::getTitular() const
{
	return this->titular;
}

float Conta::getSaldo() const
{
	return this->saldo;
}

/*=====Sobrecarga de operadores=====*/

std::ostream& operator<< (std::ostream &o,Conta const &c)
{
	return c.print(o);
}
	
bool Conta::operator==(Conta &c) const
{
	if(this->numero_conta == c.getNumeroConta())
	{
		return true;
	}

	else
		return false;
}

void Conta::setTodosLimitesCP(int &LA)
{
	return setTodosLimitesCPD(LA);
}

void Conta::diminuiLimite(std::string &tipo)
{
	return diminuiLimiteD(tipo); 
}