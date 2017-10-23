/**
 *@since 15/10/2017
 *@file conta.h
 *@brief esse arquivo contém as definições da classe Conta.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 23/10/2017
 */
#ifndef _CONTA_H
#define _CONTA_H

#include <string>
#include <vector>
#include <ostream>
#include <memory>
#include "operacao.h"

typedef enum str_especial
{
	Especial,
	Normal,
	Poupanca
}TipoConta;


class Conta
{
protected:
	std::string agencia;
	std::string numero_conta;
	std::string senha;
	std::string titular;
	std::vector<std::shared_ptr<Operacao>> operacoes;
	TipoConta tipo_da_conta;
	float saldo;
public:
	static int totalContas;
	static int getTotalContas();

	Conta(std::string _agencia,std::string _numero_conta,std::string _senha,std::string _titular,TipoConta _tipo_da_conta);
	Conta();
	virtual ~Conta();

	void addOperacao(std::shared_ptr<Operacao> _operacao);

	/*=====Membros que retornam o iterador para operações=====*/
	std::vector<std::shared_ptr<Operacao>>::iterator operacoesBEGIN();
	std::vector<std::shared_ptr<Operacao>>::iterator operacoesEND();

	/*=====Setters=====*/
	void setSaldo(float _saldo_);

	/*=====Getters=====*/
	std::string getAgencia() const;
	std::string getNumeroConta() const;
	std::string getSenha() const;
	std::string getTitular() const;
	std::string getTipoC() const;
	float getSaldo() const;
	TipoConta getTipoConta() const;
	void setTodosLimitesCP(int &LA);
	void diminuiLimite(std::string &tipo);
	virtual float getLimite() const = 0;
	
	virtual int getLimiteSaque() const = 0;
	virtual int getLimiteExtrato() const = 0;
	virtual int getLimiteTransferenciaTitular() const = 0;

	friend std::ostream& operator<< (std::ostream &o,Conta const &c);
	bool operator==(Conta &c) const;

private:
	virtual std::ostream& print(std::ostream& o) const = 0;
	virtual void setTodosLimitesCPD(int &LA) = 0;
	virtual void diminuiLimiteD(std::string &tipo) = 0;
};

#endif