#include <iostream>
#include "produto.h"

Produto::Produto() {}

Produto::~Produto() {}

Produto::Produto(std::string _codigo, std::string _descricao, double _preco):
	m_cod_barras(_codigo), m_descricao(_descricao), m_preco(_preco) {}

Produto::Produto(double _preco): m_preco(_preco) {}

std::string Produto::getCodBarras()
{
	return this->m_cod_barras;
}
	
std::string Produto::getDescricao()
{
	return this->m_descricao;
}

double Produto::getPreco() 
{
	return this->m_preco;
}
	
void Produto::setCodBarras(std::string _codigo) 
{
	this->m_cod_barras = _codigo;
}

void Produto::setDescricao(std::string _descricao)
{
	this->m_descricao = _descricao;
}

void Produto::setPreco(double _preco)
{
	this->m_preco = _preco;
}

std::ostream& operator<< (std::ostream &o, Produto &p) {
	return p.print(o);
}

Produto& Produto::operator+ (Produto &p)
{
	double preco = this->m_preco + p.getPreco();
	return Produto(preco);
}