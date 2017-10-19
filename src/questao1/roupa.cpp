/**
 *@since 10/10/2017
 *@file roupa.cpp
 *@brief arquivo onde contém as implementações da classe Roupa.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 13/10/2017
 */
#include "roupa.h"
#include "produto.h"

/*=====Construtores=====*/

Roupa::Roupa() {}

Roupa::Roupa(std::string _codigo, std::string _descricao,
 	double _preco,std::string _marca,char _sexo,std::string _tamanho):
 	Produto(_codigo, _descricao, _preco), marca(_marca) , sexo(_sexo) , tamanho(_tamanho) {}

/*=====Destrutor=====*/

 Roupa::~Roupa() {}

 /*=====Getters=====*/

 std::string Roupa::getMarca() const
 {
 	return this->marca;
 }

char Roupa::getSexo() const
 {
 	return this->sexo;
 }

 std::string Roupa::getTamanho() const
 {
 	return this->tamanho;
 }

 /*=====Setters=====*/

 void Roupa::setMarca(std::string _marca)
 {
 	this->marca = _marca;
 }

 void Roupa::setSexo(char _sexo)
 {
 	this->sexo = _sexo;
 }

 void Roupa::setTamanho(std::string _tamanho)
 {
 	this->tamanho = _tamanho;
 }

/*=====Membro que imprime as informações da classe=====*/

 std::ostream& Roupa::print(std::ostream &o) const
 {
 	o << "| " << this->m_cod_barras << " | " 
	  << this->m_descricao << " | "
	  << this->m_preco << " | "
	  << this->marca << " | "
	  << this->sexo << " | "
	  << this->tamanho << " |";
	return o;
 }
