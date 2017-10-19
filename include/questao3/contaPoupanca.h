#ifndef _CONTAPOUPANCA_H
#define _CONTAPOUPANCA_H

#include "conta.h"

class ContaPoupanca :public Conta
{
private:
	int limiteSaldo;
	int limiteExtrato;
	int limiteTransferenciaTitular;
public:
	ContaPoupanca();
	ContaPoupanca(std::string _agencia,std::string _numero_conta,std::string _senha,std::string _titular);
		
	~ContaPoupanca();
	
	/*=====Setters=====*/
	void setLimiteSaldo(int LS);
	void setLimiteExtrato(int LE);
	void setLimiteTransferenciaTitular(int LTT);

	/*=====Getters=====*/
	int getLimiteSaldo() const;
	int getLimiteExtrato() const;
	int getLimiteTransferenciaTitular() const;

private:
	std::ostream& print(std::ostream &o);
};



#endif