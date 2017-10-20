#include "contaPoupanca.h"

ContaPoupanca::ContaPoupanca() {}

ContaPoupanca::ContaPoupanca(std::string _agencia,std::string _numero_conta,std::string _senha,
	std::string _titular,TipoConta _tipo_da_conta):
	Conta(_agencia,_numero_conta,_senha,_titular,_tipo_da_conta),limiteSaque(3), limiteExtrato(3),
	limiteTransferenciaTitular(3), tipo_da_conta(_tipo_da_conta) {}	

ContaPoupanca::~ContaPoupanca() {}

/*=====Setters=====*/

void ContaPoupanca::setTodosLimitesCP(int LA)
{
	this->limiteSaque = LA;
	this->limiteExtrato = LA;
	this->limiteTransferenciaTitular = LA;
}

void ContaPoupanca::diminuiLimite(std::string tipo)
{
	if(tipo == "Saque" || tipo == "saque")
	{
		this->limiteSaque--;
	}

	if(tipo == "Extrato" || tipo == "extrato")
	{
		this->limiteExtrato--;
	}

	if(tipo == "Transferencia" || tipo == "transferencia")
	{
		this->limiteTransferenciaTitular--;
	}	
}

/*=====Getters=====*/

int ContaPoupanca::getLimiteSaque() const
{
	return this->limiteSaque;
}


TipoConta ContaPoupanca::getTipoConta() const
{
	return this->tipo_da_conta;
}

int ContaPoupanca::getLimiteExtrato() const
{
	return this->limiteExtrato;
}

int ContaPoupanca::getLimiteTransferenciaTitular() const
{
	return this->limiteTransferenciaTitular;
}

std::ostream& ContaPoupanca::print(std::ostream &o) const
{
	o << "Agencia: " << this->agencia << std::endl
	  << "Conta: " << this->numero_conta << std::endl
	  << "Titular: " << this->titular << std::endl
	  << "Tipo da conta: Poupanca" << std::endl;
	return o;
}