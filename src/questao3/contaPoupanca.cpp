#include "contaPoupanca.h"

ContaPoupanca::ContaPoupanca() {}

ContaPoupanca::ContaPoupanca(std::string _agencia,std::string _numero_conta,std::string _senha,std::string _titular):
	Conta(_agencia,_numero_conta,_senha,_titular), limiteSaldo(3), limiteExtrato(3),
	limiteTransferenciaTitular(3) {}	

ContaPoupanca::~ContaPoupanca() {}

/*=====Setters=====*/

void ContaPoupanca::setLimiteSaldo(int LS)
{
	this->limiteSaldo = LS;
}

void ContaPoupanca::setLimiteExtrato(int LE)
{
	this->limiteExtrato = LE;
}	

void ContaPoupanca::setLimiteTransferenciaTitular(int LTT)
{
	this->limiteTransferenciaTitular = LTT;
}

/*=====Getters=====*/

int ContaPoupanca::getLimiteSaldo() const
{
	return this->limiteSaldo;
}

int ContaPoupanca::getLimiteExtrato() const
{
	return this->limiteExtrato;
}

int ContaPoupanca::getLimiteTransferenciaTitular() const
{
	return this->limiteTransferenciaTitular;
}

std::ostream& ContaPoupanca::print(std::ostream &o)
{
	o << "Agencia: " << this->agencia << std::endl
	  << "Conta: " << this->numero_conta << std::endl
	  << "Titular: " << this->titular << std::endl;
	return o;
}