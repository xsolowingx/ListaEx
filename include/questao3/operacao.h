#ifndef _OPERACAO_H
#define _OPERACAO_H

#include <ostream>
#include <string>

typedef enum strType
{
	Debito,
	Credito
}TipoOperacao;

class Operacao
{
private:
	std::string descricao;
	TipoOperacao tipo_operacao;
	float valor;	
public:
	Operacao();
	Operacao(std::string _descricao,TipoOperacao _tipo_operacao,float _valor);
	~Operacao();

	/*=====Getters=====*/
	std::string getDescricao() const;
	TipoOperacao getTipo_operacao() const;
	float getValor() const;

	friend std::ostream& operator<< (std::ostream &o,Operacao const &op);
	
};

#endif