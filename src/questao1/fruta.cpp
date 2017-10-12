#include <iomanip>
#include "fruta.h"
#include "produto.h"

Fruta::Fruta() {}

Fruta::Fruta(std::string _codigo, std::string _descricao, double _preco, 
	std::string _data, double _validade):
	Produto(_codigo, _descricao, _preco), m_data_lote(_data), m_validade(_validade) {}

Fruta::~Fruta() {}

std::string Fruta::getDataLote()
{
	return this->m_data_lote;
}

double Fruta::getValidade()
{
	return this->m_validade;
}

void Fruta::setDataLote(std::string _data)
{
	this->m_data_lote = _data;
}

void Fruta::setValidade(double _validade)
{
	this->m_validade = _validade;
}

std::ostream& Fruta::print(std::ostream &o)
{
	o << std::setfill (' ') << std::setw (10) << this->m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << this->m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << this->m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << this->m_data_lote << " | " 
		<< std::setfill (' ') << std::setw (3) << this->m_validade;
		return o;
}