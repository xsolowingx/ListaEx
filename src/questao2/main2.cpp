/**
 *@since 09/17/2017
 *@file main2.cpp
 *@brief this file contain the main program.
 *@author Matheus de Jesus Leandro de Medeiros
 *@sa bank.cpp for the implementation of each function.
 *@date 10/23/2017
 */
#include "account.h"
#include "operation.h"
#include "bank.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

int main()
{
	std::vector<Account*> accounts;
	beginMessage();
	menu();
	std::string UserOption;
	int NumberOption;

	while(std::getline(std::cin , UserOption) )
	{
		std::stringstream ss(UserOption);
		ss >> NumberOption;
		
		switch (NumberOption)
		{
			case 0:
			{	/*=====Leave The Program=====*/
				std::cout << "Quiting..." << std::endl;
				return -1;
			}

			case 1:
			{	/*=====Create An Account=====*/
				createAccount(accounts);	
				
				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 2:
			{	 /*=====Make A Deposit=====*/
				if(accounts.empty())
				{
					std::cout << "You haven't created an account yet" << std::endl;
					break;
				}

				deposit(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 3:
			{	/*=====Make A Withdraw=====*/
				if(accounts.empty())
				{
					std::cout << "You haven't created an account yet" << std::endl;
					break;
				}

				withdraw(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 4:
			{	/*=====Delete An Account=====*/
				if(accounts.empty())
				{
					std::cout << "You haven't created an account yet" << std::endl;
					break;
				}

				deleteAccount(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 5:
			{	/*=====List All Accounts Of The Bank=====*/
				if(accounts.empty())
				{
					std::cout << "You haven't created an account yet" << std::endl;
					break;
				}

				listAccounts(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 6:
			{	/*=====Make A Transference=====*/
				if(accounts.empty())
				{
					std::cout << "You haven't created an account yet" << std::endl;
					break;
				}

				transfer(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 7:
			{	
				/*=====See The Balance Of Your Account=====*/
				
				if(accounts.empty())
				{
					std::cout << "You haven't created an account yet" << std::endl;
					break;
				}

				seeBalance(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			case 8:
			{	
				/*=====See The Bank Statement Of Your Account=====*/
				
				if(accounts.empty())
				{
					std::cout << "You haven't created an account yet" << std::endl;
					break;
				}

				BankStatement(accounts);

				std::cout << std::endl << "What would you like to do now?" << std::endl;
				menu();
				break;
			}

			default:
			{	
				/*=====Default Option=====*/

				std::cout << "Invalid option" << std::endl;
				break;
			}
		}
	}
	return 0;
}
