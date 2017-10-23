/**
 *@since 15/10/2017
 *@file contaCorrente.cpp
 *@brief arquivo onde contém as implementações da classe ContaCorrente.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 23/10/2017
 */
#include "contaCorrente.h"
#include "conta.h"

/*=====Construtores e destrutor=====*/

ContaCorrente::ContaCorrente() {}

ContaCorrente::ContaCorrente(std::string _agencia,std::string _numero_conta,std::string _senha,
	std::string _titular,TipoConta _tipo_da_conta):
	Conta(_agencia,_numero_conta,_senha,_titular,_tipo_da_conta), limite(500.00) {}

ContaCorrente::~ContaCorrente() {}

/*=====Método que imprime os atributos da classe=====*/

std::ostream& ContaCorrente::print(std::ostream &o) const
{
	o << "Agencia: " << this->agencia << std::endl
	  << "Numero: " << this->numero_conta << std::endl
	  << "Titular: " << this->titular << std::endl
	  << "Tipo da conta: Corrente" << std::endl << std::endl;
	return o;
}

/*=====Getter=====*/

float ContaCorrente::getLimite() const
{
	return this->limite;
}

/*====="Implementação padrão dos métodos...."=====*/

int ContaCorrente::getLimiteSaque() const 
{
	return 1;
}
	
int ContaCorrente::getLimiteExtrato() const
{
	return 1;
}
	
int ContaCorrente::getLimiteTransferenciaTitular() const 
{
	return 1;
}

void ContaCorrente::setTodosLimitesCPD(int &LA)
{
	LA += 5;
}

void ContaCorrente::diminuiLimiteD(std::string &tipo) 
{
	tipo += "!!!";
}
