/**
 *@since 10/10/2017
 *@file bebida.cpp
 *@brief arquivo onde contém as implementações da classe Bebida.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 13/10/2017
 */
#include "bebida.h"
#include "produto.h"

/*=====Construtor=====*/

Bebida::Bebida(std::string _codigo, std::string _descricao,
 	double _preco, std::string _teor_alcoolico):
	Produto(_codigo, _descricao, _preco), teor_alcoolico(_teor_alcoolico) {}

/*=====Destrutor=====*/

Bebida::~Bebida() {}

/*=====Getter=====*/

std::string Bebida::getTeorAlcoolico() const
{
	return this->teor_alcoolico;
}

/*=====Setter=====*/

void Bebida::setTeorAlcoolico(std::string teor_alcoolico_da_bebida)
{
	this->teor_alcoolico = teor_alcoolico_da_bebida;
}

/*=====Membro que printa as informações da classe=====*/

std::ostream& Bebida::print(std::ostream &o) const
{
	o << "| " << this->m_cod_barras << " | " 
	  << this->m_descricao << " | "
	  << this->m_preco << " | "
	  << this->teor_alcoolico << "% |";
	return o; 
}