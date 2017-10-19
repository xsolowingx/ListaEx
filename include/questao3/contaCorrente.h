#ifndef _CONTACORRENTE_H
#define _CONTACORRENTE_H

#include "conta.h"

typedef enum str_especial
{
	Especial,
	Normal
}TipoConta;

class ContaCorrente : public Conta
{
private:
	TipoConta tipo_da_conta;
	float limit;
public:
	ContaCorrente();
	ContaCorrente(std::string _agencia,std::string _numero_conta,std::string _senha,
		std::string _titular,TipoConta _tipo_da_conta);
	~ContaCorrente();
	
	/*=====Getters=====*/
	TipoConta getTipoConta() const;
	float getLimit() const;

private:
	std::ostream& print(std::ostream &o);
	
};






#endif