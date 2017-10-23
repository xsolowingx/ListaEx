/**
 *@since 15/10/2017
 *@file contaCorrente.h
 *@brief arquivo onde contém as definições da classe ContaCorrente.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 23/10/2017
 */
#ifndef _CONTACORRENTE_H
#define _CONTACORRENTE_H

#include "conta.h"

class ContaCorrente : public Conta
{
private:
	float limite;
public:
	ContaCorrente();
	ContaCorrente(std::string _agencia,std::string _numero_conta,std::string _senha,
		std::string _titular,TipoConta _tipo_da_conta);
	~ContaCorrente();
	
	/*=====Getters=====*/
	float getLimite() const ;

	int getLimiteSaque() const;//
	int getLimiteExtrato() const;//
	int getLimiteTransferenciaTitular() const;//
	
private:
	std::ostream& print(std::ostream &o) const;
	void setTodosLimitesCPD(int &LA);//
	void diminuiLimiteD(std::string &tipo);//
	
};


#endif