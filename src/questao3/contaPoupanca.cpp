/**
 *@since 15/10/2017
 *@file contaPoupanca.cpp
 *@brief arquivo onde contém as implementações da classe ContaPoupanca.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 23/10/2017
 */
#include "contaPoupanca.h"

ContaPoupanca::ContaPoupanca() {}

ContaPoupanca::ContaPoupanca(std::string _agencia,std::string _numero_conta,std::string _senha,
	std::string _titular,TipoConta _tipo_da_conta):
	Conta(_agencia,_numero_conta,_senha,_titular,_tipo_da_conta),limiteSaque(3), limiteExtrato(3),
	limiteTransferenciaTitular(3) {}	

ContaPoupanca::~ContaPoupanca() {}

/*=====Setter=====*/

void ContaPoupanca::setTodosLimitesCPD(int &LA)
{
	this->limiteSaque = LA;
	this->limiteExtrato = LA;
	this->limiteTransferenciaTitular = LA;
}

/*=====Método que diminui os limites...=====*/

void ContaPoupanca::diminuiLimiteD(std::string &tipo)
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

int ContaPoupanca::getLimiteExtrato() const
{
	return this->limiteExtrato;
}

int ContaPoupanca::getLimiteTransferenciaTitular() const
{
	return this->limiteTransferenciaTitular;
}

/*====="Implementação padrão...."=====*/

float ContaPoupanca::getLimite() const { return 2.0;}

/*=====Método que imprime os atributos da classe....=====*/

std::ostream& ContaPoupanca::print(std::ostream &o) const
{
	o << "Agencia: " << this->agencia << std::endl
	  << "Numero: " << this->numero_conta << std::endl
	  << "Titular: " << this->titular << std::endl
	  << "Tipo da conta: Poupanca" << std::endl << std::endl;
	return o;
}