#include <iostream>
#include <memory>
#include <sstream>
#include "conta.h"
#include "contaCorrente.h"
#include "contaPoupanca.h"
#include "operacao.h"
#include "banco.h"

int main()
{
	std::vector<std::shared_ptr<Conta>> contas;
	mensagemInicio();
	menu();
	std::string OpcaoUsuario;
	int NumeroOpcao;

	while(std::getline(std::cin , OpcaoUsuario) )
	{
		std::stringstream ss(OpcaoUsuario);
		ss >> NumeroOpcao;
		
		switch (NumeroOpcao)
		{
			case 0:
			{	/*=====Sai do programa=====*/
				std::cout << "Saindo..." << std::endl;
				return -1;
			}

			case 1:
			{	/*=====Cria uma conta=====*/
				
				criarConta(contas);	
				
				std::cout << std::endl << "O que voce gostaria de fazer agora? " << std::endl;
				menu();
				break;
			}

			case 2:
			{	 /*=====Faz um depósito=====*/
				if(contas.empty())
				{
					std::cout << "Voce nao criou uma conta ainda" << std::endl;
					break;
				}

				deposito(contas);

				std::cout << std::endl << "O que voce gostaria de fazer agora? " << std::endl;
				menu();
				break;
			}

			case 3:
			{	/*=====Realiza um saque=====*/
				if(contas.empty())
				{
					std::cout << "Voce nao criou uma conta ainda" << std::endl;
					break;
				}

				saque(contas);

				std::cout << std::endl << "O que voce gostaria de fazer agora? " << std::endl;
				menu();
				break;
			}

			case 4:
			{	/*=====Deleta uma conta=====*/
				if(contas.empty())
				{
					std::cout << "Voce nao criou uma conta ainda" << std::endl;
					break;
				}

				deletarConta(contas);

				std::cout << std::endl << "O que voce gostaria de fazer agora? " << std::endl;
				menu();
				break;
			}

			case 5:
			{	/*=====Lista todas as contas do banco=====*/
				if(contas.empty())
				{
					std::cout << "Voce nao criou uma conta ainda" << std::endl;
					break;
				}

				listarContas(contas);

				std::cout << std::endl << "O que voce gostaria de fazer agora? " << std::endl;
				menu();
				break;
			}

			case 6:
			{	/*=====Realiza uma transferência=====*/
				if(contas.empty())
				{
					std::cout << "Voce nao criou uma conta ainda" << std::endl;
					break;
				}

				transferencia(contas);

				std::cout << std::endl << "O que voce gostaria de fazer agora? " << std::endl;
				menu();
				break;
			}

			case 7:
			{	
				/*=====Ve o saldo da sua conta=====*/
				
				if(contas.empty())
				{
					std::cout << "Voce nao criou uma conta ainda" << std::endl;
					break;
				}

				veSaldo(contas);

				std::cout << std::endl << "O que voce gostaria de fazer agora? " << std::endl;
				menu();
				break;
			}

			case 8:
			{	
				/*=====Ve o extrato bancário da sua conta=====*/
				
				if(contas.empty())
				{
					std::cout << "Voce nao criou uma conta ainda" << std::endl;
					break;
				}

				extratoBancario(contas);

				std::cout << std::endl << "O que voce gostaria de fazer agora? " << std::endl;
				menu();
				break;
			}

			default:
			{	
				/*=====Opção "default"=====*/

				std::cout << "Opcao invalida" << std::endl;
				break;
			}
		}
	}
	return 0;
}
