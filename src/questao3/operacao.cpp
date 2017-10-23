/**
 *@since 15/10/2017
 *@file operacao.cpp
 *@brief arquivo onde contém as implementações da classe Operacao.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 23/10/2017
 */
#include "operacao.h"

/*=====Construtores e Destrutor=====*/

Operacao::Operacao() {}

Operacao::Operacao(std::string _descricao,TipoOperacao _tipo_operacao,float _valor):
	descricao(_descricao), tipo_operacao(_tipo_operacao), valor(_valor) {}

Operacao::~Operacao() {}

/*=====Getters=====*/

std::string Operacao::getDescricao() const
{
	return this->descricao;
}

TipoOperacao Operacao::getTipo_operacao() const
{
	return this->tipo_operacao;
}

float Operacao::getValor() const
{
	return this->valor;
}

/*=====Sobrecarga de Operador=====*/

std::ostream& operator<< (std::ostream &o,Operacao const &op)
{
	o << "Descricao: " << op.getDescricao() << std::endl;
	
	if(op.getTipo_operacao() == Debito)
	{
		o << "Tipo da operacao: Debito" << std::endl;
	}

	else if(op.getTipo_operacao() == Credito)
	{
		o << "Tipo da operacao: Credito" << std::endl;
	}

	o << "Valor: " << op.getValor() << std::endl << std::endl;
	
	return o;
}
