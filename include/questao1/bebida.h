#ifndef _BEBIDA_H
#define _BEBIDA_H

#include "produto.h"

class Bebida : public Produto
{
public:
	Bebida();
	Bebida(std::string _codigo, std::string _descricao, double _preco, std::string _teor_alcoolico);
	~Bebida();
private:
	std::string teor_alcoolico;
public:
	//getter
	std::string getTeorAlcoolico();
	//setter
	void setTeorAlcoolico(std::string teor_alcoolico_da_bebida);
private:
	std::ostream& print(std::ostream &o) const;
};


#endif