#include "contaCorrente.h"
#include "conta.h"

ContaCorrente::ContaCorrente() {}

ContaCorrente::ContaCorrente(std::string _agencia,std::string _numero_conta,std::string _senha,
	std::string _titular,TipoConta _tipo_da_conta):
	Conta(_agencia,_numero_conta,_senha,_titular), tipo_da_conta(_tipo_da_conta), limit(500.00) {}

ContaCorrente::~ContaCorrente() {}

TipoConta ContaCorrente::getTipoConta() const
{
	return this->tipo_da_conta;
}

float ContaCorrente::getLimit() const
{
	return this->limit;
}

std::ostream& ContaCorrente::print(std::ostream &o)
{
	o << "Agencia: " << this->agencia << std::endl
	  << "Conta: " << this->numero_conta << std::endl
	  << "Titular: " << this->titular << std::endl;
	return o;
}