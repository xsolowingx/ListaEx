/**
 *@since 10/10/2017
 *@file produto.cpp
 *@brief arquivo onde contém as implementações da classe Produto.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 13/10/2017
 */
#include <iostream>
#include "produto.h"

/*=====Construtores=====*/

Produto::Produto() {}

Produto::Produto(std::string _codigo, std::string _descricao, double _preco):
	m_cod_barras(_codigo), m_descricao(_descricao), m_preco(_preco) {}

/*=====Destrutor=====*/

Produto::~Produto() {}

/*=====Getters=====*/

std::string Produto::getCodBarras() const
{
	return this->m_cod_barras;
}
	
std::string Produto::getDescricao() const
{
	return this->m_descricao;
}

double Produto::getPreco() const
{
	return this->m_preco;
}

/*=====Setters=====*/

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

/*=====Operators=====*/

std::ostream& operator<< (std::ostream &o, Produto const &p) {
	return p.print(o);
}

bool Produto::operator==(Produto const &p)
{
	if(this->m_preco == p.m_preco) return true;
	else
		return false;
}

double Produto::operator+(Produto const &p)
{
	return this->m_preco + p.m_preco;

}

double Produto::operator-(Produto const &p)
{
	return this->m_preco - p.m_preco;

}

Produto::operator double()
{
	return this->m_preco;
}