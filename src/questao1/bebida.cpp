#include "bebida.h"
#include "produto.h"

Bebida::Bebida(std::string _codigo, std::string _descricao,
 	double _preco, std::string _teor_alcoolico):
	Produto(_codigo, _descricao, _preco), teor_alcoolico(_teor_alcoolico) {}

Bebida::~Bebida() {}

std::string Bebida::getTeorAlcoolico()
{
	return this->teor_alcoolico;
}

void Bebida::setTeorAlcoolico(std::string teor_alcoolico_da_bebida)
{
	this->teor_alcoolico = teor_alcoolico_da_bebida;
}

std::ostream& Bebida::print(std::ostream &o) const
{
	o << std::setfill (' ') << std::setw (10) << this->m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << this->m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << this->m_preco << " | "
		<< std::setfill (' ') << std::setw (3) << this->teor_alcoolico;
		return o; 
}