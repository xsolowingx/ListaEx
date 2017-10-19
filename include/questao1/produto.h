/**
 *@since 10/10/2017
 *@file produto.h
 *@brief arquivo onde contém as definições da classe Produto.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 13/10/2017
 */
#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>
#include <string>
#include <ostream>

class Produto
{
public:
	/*=====Construtores=====*/
	Produto();
	Produto(std::string _codigo, std::string _descricao, double _preco);
	/*=====Destrutor=====*/
	virtual ~Produto();
protected:
	std::string m_cod_barras;
	std::string m_descricao;
	double m_preco;		
public:
	/*=====Getters=====*/
	std::string getCodBarras() const;
	std::string getDescricao() const;
	double getPreco() const;
	/*=====Setters=====*/
	void setCodBarras(std::string _codigo);
	void setDescricao(std::string _descricao);
	void setPreco(double _preco);
	/*=====Operators=====*/
	friend std::ostream& operator<< (std::ostream &o, Produto const &p);  
	operator double();
	bool operator==(Produto const &p);
	double operator+ (Produto const &p);
	double operator- (Produto const &p);
private:
	/*=====Membro que imprime as informações da classe,porém não é implementada nessa classe=====*/
	virtual std::ostream& print(std::ostream&) const = 0;
};
 
#endif
