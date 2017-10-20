#include "contaCorrente.h"
#include "conta.h"

ContaCorrente::ContaCorrente() {}

ContaCorrente::ContaCorrente(std::string _agencia,std::string _numero_conta,std::string _senha,
	std::string _titular,TipoConta _tipo_da_conta):
	Conta(_agencia,_numero_conta,_senha,_titular,_tipo_da_conta), tipo_da_conta(_tipo_da_conta), limite(500.00) {}

ContaCorrente::~ContaCorrente() {}

TipoConta ContaCorrente::getTipoConta() const
{
	return this->tipo_da_conta;
}

float ContaCorrente::getLimite() const
{
	return this->limite;
}

std::ostream& ContaCorrente::print(std::ostream &o) const
{
	o << "Agencia: " << this->agencia << std::endl
	  << "Conta: " << this->numero_conta << std::endl
	  << "Titular: " << this->titular << std::endl
	  << "Tipo da conta: Corrente" << std::endl;
	return o;
}

