/**
 *@since 10/10/2017
 *@file roupa.h
 *@brief arquivo onde contém as definições da classe Roupa.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 13/10/2017
 */
#ifndef _ROUPA_H
#define _ROUPA_H

#include "produto.h"

class Roupa : public Produto
{
public:
	/*=====Construtores=====*/
	Roupa();
	Roupa(std::string _codigo, std::string _descricao, double _preco,std::string _marca,char _sexo,std::string _tamanho);
	/*=====Destrutores=====*/
	~Roupa();
private:
	std::string marca;
	char sexo;
	std::string tamanho;
public:
	/*=====Getters=====*/
	std::string getMarca() const;
	char getSexo() const;
	std::string getTamanho() const;
	/*=====Setters=====*/
	void setMarca(std::string _marca);
	void setSexo(char _sexo);
	void setTamanho(std::string _tamanho);
private:
	/*=====Membro que imprime as informações da classe=====*/
	std::ostream& print(std::ostream &o) const;
};



#endif