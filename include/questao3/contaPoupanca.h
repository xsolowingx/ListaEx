#ifndef _CONTAPOUPANCA_H
#define _CONTAPOUPANCA_H

#include "conta.h"

class ContaPoupanca :public Conta
{
private:
	int limiteSaque;
	int limiteExtrato;
	int limiteTransferenciaTitular;
	TipoConta tipo_da_conta;
public:
	ContaPoupanca();
	ContaPoupanca(std::string _agencia,std::string _numero_conta,std::string _senha,std::string _titular,TipoConta _tipo_da_conta);
		
	~ContaPoupanca();
	
	/*=====Setters=====*/
	void setTodosLimitesCP(int LA);
	void diminuiLimite(std::string tipo);

	/*=====Getters=====*/
	int getLimiteSaque() const;
	int getLimiteExtrato() const;
	int getLimiteTransferenciaTitular() const;
	TipoConta getTipoConta() const;
	float getLimite() const = 0;
private:
	std::ostream& print(std::ostream &o) const;
};



#endif