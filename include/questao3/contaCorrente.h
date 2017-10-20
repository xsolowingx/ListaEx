#ifndef _CONTACORRENTE_H
#define _CONTACORRENTE_H

#include "conta.h"

class ContaCorrente : public Conta
{
private:
	TipoConta tipo_da_conta;
	float limite;
public:
	ContaCorrente();
	ContaCorrente(std::string _agencia,std::string _numero_conta,std::string _senha,
		std::string _titular,TipoConta _tipo_da_conta);
	~ContaCorrente();
	
	/*=====Getters=====*/
	TipoConta getTipoConta() const;
	float getLimite() const ;

	int getLimiteSaque() const = 0;
	int getLimiteExtrato() const = 0;
	int getLimiteTransferenciaTitular() const = 0;
	void setTodosLimitesCP(int LA) const = 0;
	void diminuiLimite(std::string tipo) const = 0;
	
private:
	std::ostream& print(std::ostream &o) const;
	
};






#endif