#include "banco.h"
#include "contaCorrente.h"
#include "contaPoupanca.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory>

/*=====Cria uma conta=====*/

void criarConta(std::vector<std::shared_ptr<Conta>> &contas)
{
	std::cout << "Por favor, digite a agencia da sua conta: " << std::endl;

	std::string _agencia_;

	inputNumberI(_agencia_);

	std::cout << "Por favor, digite o numero da sua conta: " << std::endl;

	std::string _numero_conta_;

	int _int_helper;

	while(std::getline(std::cin , _numero_conta_) )
	{
		std::stringstream ss(_numero_conta_);

		if(ss >> _int_helper && ss.eof())
		{
			if(verificaConta(_agencia_,_numero_conta_,contas) )
			{
				continue;
			}

			else
			{
				std::cout << "Entrada valida: " << _numero_conta_ << std::endl;
				break;
			}
		}

		std::cout << "Erro! entrada invalida. " << std::endl;
	}

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

		if(_Tipo_Conta == "Poupanca")
		{
			Tipo_Conta = Poupanca;
			break;
		}

		std::cout << "Error! invalid input. " << std::endl;
	}

	std::cout << "Por favor digite sua senha: " << std::endl;

	std::string _SENHA_;

	std::getline(std::cin,_SENHA_);

	if(Tipo_Conta == Poupanca)
	{
		contas.push_back(std::make_shared<ContaPoupanca>(_agencia_,_numero_conta_,_SENHA_,_titular_,Tipo_Conta) );
		std::cout << "Conta Criada com Sucesso!" << std::endl;
	}

	if(Tipo_Conta != Poupanca)
	{
		contas.push_back(std::make_shared<ContaCorrente>(_agencia_,_numero_conta_,_SENHA_,_titular_,Tipo_Conta) );
		std::cout << "Conta Criada com Sucesso!" << std::endl;
	}
}

/*=====Faz um depósito e adiciona uma operação de "Credito" para a conta=====*/

void deposito(std::vector<std::shared_ptr<Conta>> &contas)
{
	std::cout << "Por favor digite a agencia da conta que voce deseja fazer o deposito " << std::endl;
	std::string _agencia_;
	inputNumberI(_agencia_);
			
	std::cout << "Por favor digite o numero da conta que voce deseja fazer o deposito " << std::endl;
	std::string _numero_conta_;
	inputNumberI(_numero_conta_);

	for(auto it = contas.begin(); it != contas.end() ; it++)
	{
		if( ((**it).getAgencia() == _agencia_) && ( (**it).getNumeroConta() == _numero_conta_) )
		{
			std::cout << "Conta Encontrada!" << std::endl;
			std::cout << (**it);

			if( (**it).getTipoConta() == Poupanca )
			{
				std::cout << "A cada R$100,00 depositados em contas poupancas, aumenta em 1 o limite para saque,transferencia e extrato " << std::endl;
			}

			std::cout << "Por favor digite o valor do deposito " << std::endl;
			std::string _valor_;
			inputNumberF(_valor_);

			std::stringstream ssf(_valor_);
			float  valor_float;

			ssf >> valor_float; 

			if( ( (**it).getTipoConta() == Poupanca ) && (valor_float > 100.00) )
			{	
				int aux = (int) valor_float / 100;
				(**it).setTodosLimitesCP( aux );
			}

			float novo_saldo = valor_float + (**it).getSaldo();
			(**it).setSaldo(novo_saldo);

			(**it).addOperacao(std::make_shared<Operacao>("Deposito",Credito,valor_float) );
			
			std::cout << "Deposito efetuado com sucesso " << std::endl;

			return ;
		}
	}

	std::cout << "Erro! conta nao encontrada " << std::endl;
}

/*=====Faz um saque e adiciona uma operação de "Debito" na conta=====*/

void saque(std::vector<std::shared_ptr<Conta>> &contas)
{
	std::cout << "Por favor digite a agencia da sua conta " << std::endl;
	std::string _agencia_;
	inputNumberI(_agencia_);
			
	std::cout << "Por favor digite o numero da sua conta " << std::endl;
	std::string _numero_conta_;
	inputNumberI(_numero_conta_);

	for(auto it = contas.begin(); it != contas.end() ; it++)
	{
		if( ((**it).getAgencia() == _agencia_) && ( (**it).getNumeroConta() == _numero_conta_) )
		{
			std::cout << "Conta encontrada!" << std::endl;
			std::cout << (**it);
			
			verificaSenha((**it));

			std::cout << "Sua Conta tem: " << std::endl;
			std::cout << "R$" << (**it).getSaldo() << std::endl;

			std::cout << "Por favor digite o valor do saque " << std::endl;
			std::string _valor_;

			while(std::getline(std::cin , _valor_))
			{	
				float valor_float = stof(_valor_);

				if( ( (**it).getTipoConta() == Especial) && (valor_float > (**it).getLimite() ) )
				{
					std::cout << "Erro!" << std::endl;
					std::cout << std::setprecision(2) << std::fixed 
					<< "Sua conta tem um limite de saque de: R$" << (**it).getLimite() << std::endl;
					std::cout << "Por favor digite de novo o valor do saque " << std::endl;
					continue;
				}

				if( valor_float > (**it).getSaldo() )
				{
					std::cout << "Erro!" << std::endl;
					std::cout << "Saldo insuficiente " << std::endl;
					std::cout << "Por favor digite de novo o valor do saque " << std::endl;
					continue;
				}

				if( valor_float < (**it).getSaldo() )
				{	
					if( ( (**it).getTipoConta() == Poupanca) && ( (**it).getLimiteSaque() == 0 )  )
					{
						std::cout << "Erro!" << std::endl;
						std::cout << "Sua conta Poupanca chegou ao limite de saques" << std::endl;
						std::cout << "Por favor faça depositos acima de R$100.00" << std::endl;
						return;
					}

					if( (**it).getTipoConta() == Poupanca)
					{
						std::string auxS = "Saque";
						(**it).diminuiLimite(auxS);
					}

					float novo_saldo = (**it).getSaldo() - valor_float;
					(**it).setSaldo(novo_saldo);

					(**it).addOperacao(std::make_shared<Operacao>("Saque",Debito,valor_float) );

					std::cout << "Saque realizado com sucesso " << std::endl;
					break;
				}
			}

			return ;
		}
	}

	std::cout << "Erro! conta nao encontrada " << std::endl;

}

/*=====Deleta uma conta do banco=====*/

void deletarConta(std::vector<std::shared_ptr<Conta>> &contas)
{
	std::cout << "Por favor digite a agencia da sua conta " << std::endl;
	std::string _agencia_;
	inputNumberI(_agencia_);
			
	std::cout << "Por favor digite o numero da sua conta " << std::endl;
	std::string _numero_conta_;
	inputNumberI(_numero_conta_);

	for(auto it = contas.begin() ; it != contas.end() ; it++)
	{
		if( ((**it).getAgencia() == _agencia_) && ( (**it).getNumeroConta() == _numero_conta_) )
		{
			std::cout << "Conta encontrada!" << std::endl;
			std::cout << (**it);
			
			verificaSenha((**it));
			std::cout << "Voce tem certeza que deseja deletar sua conta?" << std::endl;

			bool opcao_usuario = verificaSim_Nao();

			if(opcao_usuario == false)
			{
				return ;
			}

			if(opcao_usuario == true)
			{
				contas.erase(it);
				Conta::totalContas--;
				std::cout << "Conta deletada com sucesso " << std::endl;
				return ;
			}
		}
	}

	std::cout << "Erro! Conta nao encontrada " << std::endl;
}

/*=====Lista todas as contas do banco=====*/

void listarContas(std::vector<std::shared_ptr<Conta>> &contas)
{
	int i = 1;

	std::cout << "O banco tem um total de " << Conta::getTotalContas() << " contas" << std::endl;

	for(auto it = contas.begin() ; it != contas.end() ; it++)
	{	
		std::cout << "Conta " << i++ << ":" << std::endl << std::endl;
		std::cout << (**it);
	}
}

/*=====Faz uma transferência de A para B, adicionando uma operação de "Debito" em A e "Credito" em B=====*/

void transferencia(std::vector<std::shared_ptr<Conta>> &contas)
{
	std::cout << "Por favor digite a agencia da sua conta" << std::endl;
	std::string sua_agencia;
	inputNumberI(sua_agencia);
			
	std::cout << "Por favor digite o numero da sua conta " << std::endl;
	std::string seu_numero;
	inputNumberI(seu_numero);

	for(auto it = contas.begin() ; it != contas.end() ; it++)
	{
		if( ((**it).getAgencia() == sua_agencia) && ( (**it).getNumeroConta() == seu_numero) )
		{
			std::cout << "Conta encontrada!" << std::endl;
			std::cout << (**it);
			verificaSenha((**it));

			std::cout << "Sua conta tem:" << std::endl;
			std::cout<< std::setprecision(2) << std::fixed << "R$" << (**it).getSaldo() << std::endl;

			std::cout << "Por favor digite a agencia da conta que voce deseja transferir o dinheiro " << std::endl;
			std::string Acc_Agencia;
			inputNumberI(Acc_Agencia);
					
			std::cout << "Por favor digite o numero da conta que voce deseja transferir o dinheiro " << std::endl;
			std::string Acc_NumeroConta;
			inputNumberI(Acc_NumeroConta);

			for(auto iterator = contas.begin() ; iterator != contas.end() ; iterator++)
			{
				if( ( (**iterator).getAgencia() == Acc_Agencia) && ( (**iterator).getNumeroConta() == Acc_NumeroConta) )
				{	
					if( ( (**it).getTipoConta() == Poupanca)  && ( (**it).getTitular() != (**iterator).getTitular() ) )
					{
						std::cout << "Erro!" << std::endl;
						std::cout << "Contas poupancas so podem fazer transferencias para as contas correntes dos proprios titulares" << std::endl;
						std::cout << "Operacao finalizada!" << std::endl;
						return;
					}

					if( ( (**it).getTipoConta() == Poupanca) && ( (**it).getLimiteTransferenciaTitular() == 0 )  )
					{
						std::cout << "Sua conta Poupanca chegou ao limite de transferencias";
						std::cout << "Operacao finalizada!" << std::endl;
						return;
					}

					if( (**it).getTipoConta() == Poupanca)
					{
						std::string auxT = "Transferencia";
						(**it).diminuiLimite(auxT);
					}
					
					std::cout << "Conta encontrada!" << std::endl;
					std::cout << (**iterator);

					std::cout << "Por favor digite o valor que voce deseja transferir " << std::endl;
					std::string _valor_;

					while(std::getline(std::cin , _valor_))
					{
						float valor_float = stof(_valor_);

						if(valor_float > (**it).getSaldo())
						{
							std::cout << "Erro! saldo insuficiente " << std::endl;
							continue;
						}

						if(valor_float < (**it).getSaldo())
						{
							float novo_saldo_debitado = (**it).getSaldo() - valor_float;
							(**it).setSaldo(novo_saldo_debitado);

							float novo_saldo_creditado = (**iterator).getSaldo() + valor_float;
							(**iterator).setSaldo(novo_saldo_creditado);

							(**it).addOperacao(std::make_shared<Operacao>("Transferencia",Debito,valor_float) );

							(**iterator).addOperacao(std::make_shared<Operacao>("Transferencia",Credito,valor_float) );

							std::cout << "Transferencia efetuada com sucesso " << std::endl;

							return;
						}
					}
				}
			}
			std::cout << "Erro! conta nao encontrada " << std::endl;
			return ;
		}
	}
	std::cout << "Erro! conta nao encontrada " << std::endl;
}

/*=====Vê o saldo da sua conta=====*/

void veSaldo(std::vector<std::shared_ptr<Conta>> &contas)
{
	std::cout << "Por favor digite a agencia da sua conta " << std::endl;
	std::string sua_agencia;
	inputNumberI(sua_agencia);
			
	std::cout << "Por favor digite o numero da sua conta " << std::endl;
	std::string seu_numero;
	inputNumberI(seu_numero);

	for(auto it = contas.begin() ; it != contas.end() ; it++)
	{
		if( ((**it).getAgencia() == sua_agencia) && ( (**it).getNumeroConta() == seu_numero) )
		{
			std::cout << "Conta encontrada!" << std::endl;
			std::cout << (**it);
			
			verificaSenha((**it));

			std::cout << "Sua conta tem:" << std::endl;
			std::cout << std::setprecision(2) << std::fixed  << "R$" << (**it).getSaldo() << std::endl;

		}
	}
}

/*=====Ve o extrato bancário da sua conta=====*/

void extratoBancario(std::vector<std::shared_ptr<Conta>> &contas)
{
	std::cout << "Por favor digite a agencia da sua conta " << std::endl;
	std::string sua_agencia;
	inputNumberI(sua_agencia);
			
	std::cout << "Por favor digite o numero da sua conta " << std::endl;
	std::string seu_numero;
	inputNumberI(seu_numero);

	for(auto it = contas.begin() ; it != contas.end() ; it++)
	{
		if( ((**it).getAgencia() == sua_agencia) && ( (**it).getNumeroConta() == seu_numero) )
		{
			std::cout << "Conta encontrada!" << std::endl;
			std::cout << (**it);
			
			verificaSenha((**it));

			if( ( (**it).getTipoConta() == Poupanca) && ( (**it).getLimiteExtrato() == 0 )  )
			{
				std::cout << "Sua conta Poupanca chegou ao limite de extratos";
				std::cout << "Operacao finalizada" << std::endl;
				return ;
			}

			if( (**it).getTipoConta() == Poupanca)
			{
				std::string auxE = "Extrato";
				(**it).diminuiLimite(auxE);
			}

			std::cout << "Sua conta tem:" << std::endl;
			std::cout << std::setprecision(2) << std::fixed  << "U$" << (**it).getSaldo() << std::endl;

			std::cout << "Operacoes realizadas:" << std::endl << std::endl;

			for(auto it_o = (**it).operacoesBEGIN() ; it_o != (**it).operacoesEND() ; it_o ++)
			{
				std::cout << (**it_o);
			}
		}
	}
}

/*===== =====*/

/*=====Funções que fazem verificações=====*/

bool verificaConta(std::string &_agencia_,std::string &_numero_conta_,std::vector<std::shared_ptr<Conta>> &contas)
{
	for(auto it = contas.begin(); it != contas.end() ; it++)
	{
		if( _agencia_ == (**it).getAgencia())
		{
			if(_numero_conta_ == (**it).getNumeroConta())
			{
				std::cout << "Essa conta ja existe!" << std::endl;
				std::cout << "Digite um numero diferente" << std::endl;
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
			continue;
		}

		if(1)
		{
			std::cout << "Entrada valida: " << name << std::endl;
			return;
		}
	}
}

/*=====Funções de mensagens=====*/

void mensagemInicio()
{
	std::cout << "==================================" << std::endl;
	std::cout << ">>Bem vindo ao simulador de banco 1.42! " << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << "Digite um dos numeros seguintes para fazera  opcao descrita apos o():" << std::endl;
}

void menu()
{
	std::cout << "(0)Sai do programa" << std::endl;
	std::cout << "(1)Cria uma conta" << std::endl;
	std::cout << "(2)Faz um deposito" << std::endl;
	std::cout << "(3)Saque" << std::endl;
	std::cout << "(4)Deletar uma conta" << std::endl;
	std::cout << "(5)Listar todas as contas do banco" << std::endl;
	std::cout << "(6)Fazer uma transferencia" << std::endl;
	std::cout << "(7)Saldo da sua conta" << std::endl;
	std::cout << "(8)Ve o extrato bancario da sua conta" << std::endl;
}
