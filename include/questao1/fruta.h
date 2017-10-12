#ifndef _FRUTA_H_
#define _FRUTA_H_

#include "produto.h"

class Fruta : public Produto
{
public:
	Fruta();
	Fruta(std::string _codigo, std::string _descricao, double _preco, 
			std::string _data, double _validade);
	~Fruta();
private:
	std::string m_data_lote;
	double m_validade;
public:
	// getters
	std::string getDataLote();
	double getValidade();
	// setters
	void setDataLote(std::string _data);
	void setValidade(double _validade);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif