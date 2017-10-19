/**
 *@since 10/10/2017
 *@file bebida.h
 *@brief arquivo onde contém as definições da classe Bebida.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 13/10/2017
 */
#ifndef _BEBIDA_H
#define _BEBIDA_H

#include "produto.h"

class Bebida : public Produto
{
public:
	/*=====Construtores=====*/
	Bebida();
	Bebida(std::string _codigo, std::string _descricao, double _preco, std::string _teor_alcoolico);
	/*=====Destrutor=====*/
	~Bebida();
private:
	std::string teor_alcoolico;
public:
	/*=====Getter=====*/
	std::string getTeorAlcoolico() const;
	/*=====Setter=====*/
	void setTeorAlcoolico(std::string teor_alcoolico_da_bebida);
private:
	/*=====Membro que printa na tela as informações da classe=====*/
	std::ostream& print(std::ostream &o) const;
};


#endif