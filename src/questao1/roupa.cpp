#include "roupa.h"
#include "produto.h"

Roupa::Roupa(std::string _codigo, std::string _descricao,
 	double _preco,std::string _marca,char _sexo,std::string _tamanho):
 	Produto(_codigo, _descricao, _preco), marca(_marca) , sexo(_sexo) , tamanho(_tamanho) {}

 Roupa::~Roupa() {}

 std::string Roupa::getMarca()
 {
 	return this->marca;
 }

char Roupa::getSexo()
 {
 	return this->sexo;
 }

 std::string Roupa::getTamanho()
 {
 	return this->tamanho;
 }

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

 std::ostream& Roupa::print(std::ostream &o) const
 {
 	o << std::setfill (' ') << std::setw (10) << this->m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << this->m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << this->m_preco << " | "
		<< std::setfill (' ') << std::setw (15) << this->marca << " | "
		<< std::setfill (' ') << std::setw (2) << this->sexo << " | "
		<< std::setfill (' ') << std::setw (5) << this->tamanho;
		return o;
 }