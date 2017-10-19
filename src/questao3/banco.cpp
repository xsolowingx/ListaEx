#include "banco.h"
#include <iostream>
#include <sstream>
#include <iomanip>

void criaContaCorrente(std::vector<std::shared_ptr<Conta>> &contas)
{
	std::cout << "Por favor, digite a agencia da sua conta: " << std::endl;

	std::string _agencia_;

	inputNumberI(_agencia_);

	std::cout << "Por favor, digite o numero da sua conta: " << std::endl;

	std::string _numero_conta_;

	inputNumberI(_numero_conta_);

	std::cout << "Por favor digite o nome do titular: " << std::endl;
	
	std::string _titular_;
	inputName(_titular_);

	std::cout << "Por favor, digite o tipo da conta: " << std::endl;

	std::string _Tipo_Conta;
	TipoConta Tipo_Conta;
	
	while(std::getline(std::cin , _Tipo_Conta))
	{
		if(_Tipo_Conta == "Especial")
		{
			Tipo_Conta = Especial;
			break;
		}

		if(_Tipo_Conta == "Normal")
		{
			Tipo_Conta = Normal;
			break;
		}

		std::cout << "Error! invalid input. " << std::endl;
	}

	std::cout << "Por favor digite sua senha: " << std::endl;

	std::string _SENHA_;

	std::getline(std::cin,_SENHA_);

	contas.push_back(std::make_shared<ContaCorrente>(_agencia_,_numero_conta_,_SENHA_,_titular_,Tipo_Conta) );
}

void criarContaPoupanca(std::vector<std::shared_ptr<Conta>>& contas)
{
	std::cout << "Por favor, digite a agencia da sua conta: " << std::endl;

	std::string _agencia_;

	inputNumberI(_agencia_);

	std::cout << "Por favor, digite o numero da sua conta: " << std::endl;

	std::string _numero_conta_;

	inputNumberI(_numero_conta_);

	std::cout << "Por favor digite o nome do titular: " << std::endl;
	
	std::string _titular_;
	inputName(_titular_);

	std::cout << "Por favor digite sua senha: " << std::endl;

	std::string _SENHA_;

	std::getline(std::cin,_SENHA_);

	//contas.push_back(std::make_shared<ContaPoupanca>(_agencia_,_numero_conta_,_SENHA_,_titular_) );
}

/*=====F=====*/
/*=====Funções que fazem verificações=====*/

bool verificaConta(std::string &_agencia_,std::string &_numero_conta_,std::vector<std::shared_ptr<Conta>> &contas)
{
	for(auto it = contas.begin(); it != contas.end() ; it++)
	{
		if( _agencia_ == (*it)->getAgencia())
		{
			if(_numero_conta_ == (*it)->getNumeroConta())
			{
				std::cout << "This account already exist!" << std::endl;
				std::cout << "Type a diferent number" << std::endl;
				return true;
			}
		}
	}
	return false;
}

bool verificaSim_Nao()
{
	std::string opcao;

	while(std::getline(std::cin , opcao))
	{
		if((opcao == "S") || (opcao == "s"))
		{
			return true;
		}

		if((opcao == "N") || (opcao == "n"))
		{
			return false;
		}
	}
	return false;
}

void verificaSenha(Conta &contaP)
{
	std::cout << "Por favor digite sua senha: " << std::endl;
	std::string _SENHA_;
	while(std::getline(std::cin , _SENHA_))
	{
		if(_SENHA_ == contaP.getSenha())
		{
			std::cout << "Senha Correta! " << std::endl << std::endl;
			return ;
		}

		else
		{	
			std::cout << "Senha Incorreta! " << std::endl << std::endl;
			std::cout << "Por favor digite sua senha: " << std::endl;
		}
	}
}



/*=====Funções "input"=====*/

void inputNumberI(std::string &numero)
{
	int _int_aux;

	while(std::getline(std::cin , numero) )
	{
		std::stringstream ss(numero);

		if(ss >> _int_aux && ss.eof())
		{
			std::cout << "Entrada valida: " << numero << std::endl;
			return ;
		}

		std::cout << "Erro! entrada invalida. " << std::endl;

	}
}

void inputNumberF(std::string &numero)
{
	float _float_aux;

	while(std::getline(std::cin , numero) )
	{
		std::stringstream ss(numero);

		if(ss >> _float_aux && ss.eof())
		{
			std::cout << "Entrada valida: " << numero << std::endl;
			return ;
		}

		std::cout << "Erro! entrada invalida. " << std::endl;

	}
}

void inputName(std::string &name)
{
	int _int_aux;
	float _float_aux;

	while(std::getline(std::cin , name) )
	{
		std::stringstream ssi(name);
		std::stringstream ssf(name);

		if( ((ssi >> _int_aux) || (ssf >> _float_aux) ) && ssi.eof() )
		{
			std::cout << "Erro! entrada invalida. " << std::endl;
		}

		else
			std::cout << "Entrada valida: " << name << std::endl;
	}
}