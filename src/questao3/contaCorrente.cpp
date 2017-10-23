#include "contaCorrente.h"
#include "conta.h"

ContaCorrente::ContaCorrente() {}

ContaCorrente::ContaCorrente(std::string _agencia,std::string _numero_conta,std::string _senha,
	std::string _titular,TipoConta _tipo_da_conta):
	Conta(_agencia,_numero_conta,_senha,_titular,_tipo_da_conta), limite(500.00) {}

ContaCorrente::~ContaCorrente() {}

float ContaCorrente::getLimite() const
{
	return this->limite;
}

std::ostream& ContaCorrente::print(std::ostream &o) const
{
	o << "Agencia: " << this->agencia << std::endl
	  << "Numero: " << this->numero_conta << std::endl
	  << "Titular: " << this->titular << std::endl
	  << "Tipo da conta: Corrente" << std::endl << std::endl;
	return o;
}

int ContaCorrente::getLimiteSaque() const {}
	
int ContaCorrente::getLimiteExtrato() const {}
	
int ContaCorrente::getLimiteTransferenciaTitular() const {}

void ContaCorrente::setTodosLimitesCPD(int &LA)
{
	LA += 5;
}

void ContaCorrente::diminuiLimiteD(std::string &tipo) 
{
	tipo += "!!!";
}
