/**
 *@since 10/10/2017
 *@file fruta.h
 *@brief arquivo onde contém as definições da classe Fruta.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 13/10/2017
 */
#ifndef _FRUTA_H_
#define _FRUTA_H_

#include "produto.h"

class Fruta : public Produto
{
public:
	/*=====Construtores=====*/
	Fruta();
	Fruta(std::string _codigo, std::string _descricao, double _preco, 
			std::string _data, double _validade);
	/*=====Destrutor=====*/
	~Fruta();
private:
	std::string m_data_lote;
	double m_validade;
public:
	/*=====Getters=====*/
	std::string getDataLote() const;
	double getValidade() const;
	/*=====Setters=====*/
	void setDataLote(std::string _data);
	void setValidade(double _validade);
private:
	/*=====Membro que imprime as informações da classe=====*/
	std::ostream& print(std::ostream &o) const;
};

#endif