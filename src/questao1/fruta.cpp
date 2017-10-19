/**
 *@since 10/10/2017
 *@file fruta.cpp
 *@brief arquivo onde contém as implementações da classe Fruta.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 13/10/2017
 */
#include <iomanip>
#include "fruta.h"
#include "produto.h"

/*=====Construtores=====*/

Fruta::Fruta() {}

Fruta::Fruta(std::string _codigo, std::string _descricao, double _preco, 
	std::string _data, double _validade):
	Produto(_codigo, _descricao, _preco), m_data_lote(_data), m_validade(_validade) {}

/*=====Destrutor=====*/

Fruta::~Fruta() {}

/*=====Getters=====*/

std::string Fruta::getDataLote() const
{
	return this->m_data_lote;
}

double Fruta::getValidade() const
{
	return this->m_validade;
}

/*=====Setters=====*/

void Fruta::setDataLote(std::string _data)
{
	this->m_data_lote = _data;
}

void Fruta::setValidade(double _validade)
{
	this->m_validade = _validade;
}

/*=====Membro que imprime as informações da classe=====*/

std::ostream& Fruta::print(std::ostream &o) const
{
	o << "| " << this->m_cod_barras << " | " 
	  << this->m_descricao << " | "
	  << this->m_preco << " | "
	  << this->m_data_lote << " | " 
	  << this->m_validade << " Dias |";
	return o;
}
