/**
 *@since 09/17/2017
 *@file bank.cpp
 *@brief this file contain the implementation of the functions that the bank do.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 10/23/2017
 */
#include "bank.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

/*=====FUNCTIONS OF THE BANK=====*/

void createAccount(std::vector<Account*>& accounts)
{	
	/*=====Create An Account And Add It To The Vector Of Accounts=====*/
	
	std::cout << "Please, type the Agency of your account: " << std::endl;

	std::string _agency_;

	int _int_helper;

	inputNumber(_agency_);

	std::cout << "Please type the Number of your account: " << std::endl;

	std::string _number_;

	while(std::getline(std::cin , _number_) )
	{
		std::stringstream ss(_number_);

		if(ss >> _int_helper && ss.eof())
		{
			if(verifyAccount(_agency_,_number_,accounts) )
			{
				continue;
			}

			else
			{
				std::cout << "Valid input: " << _number_ << std::endl;
				break;
			}
		}

		std::cout << "Error! invalid input. " << std::endl;
	}

	std::cout << "Please type the type of your account: " << std::endl;

	std::string _type_account_;
	TypeAccount Type_Account_;
	
	while(std::getline(std::cin , _type_account_))
	{
		if(_type_account_ == "Special")
		{
			Type_Account_ = Special;
			break;
		}

		if(_type_account_ == "Normal")
		{
			Type_Account_ = Normal;
			break;
		}

		std::cout << "Error! invalid input. " << std::endl;
	}

	std::cout << "Please type the password of your account: " << std::endl;

	std::string _password_;

	std::getline(std::cin,_password_);

	accounts.push_back(new Account(_agency_,_number_,Type_Account_,_password_) );

}

void deposit(std::vector<Account*>& accounts)
{

	/*=====Make A Deposit And Add An Operation Of "Credit" To The Account=====*/

	std::cout << "Please type the agency of the account that you like to make a deposit" << std::endl;
	std::string _Agency;
	inputNumber(_Agency);
			
	std::cout << "Please type the number of the account that you like to make a deposit" << std::endl;
	std::string _Number;
	inputNumber(_Number);

	for(auto it = accounts.begin(); it != accounts.end() ; it++)
	{
		if( ((*it)->getAgency() == _Agency) && ( (*it)->getNumber() == _Number) )
		{
			std::cout << "Account found!" << std::endl;
			std::cout << (**it);

			std::cout << "Please type the value of the deposit" << std::endl;
			std::string _Value;
			inputNumberF(_Value);
			float value = stof(_Value);
			float new_balance = value + (*it)->getBalance();
			(*it)->setBalance(new_balance);

			Operation* op = new Operation("Deposit",Credit,value);

			(*it)->addOperation(op);
			
			std::cout << "Deposit sucessfull " << std::endl;

			return ;
		}
	}

	std::cout << "Error! Account not found" << std::endl;

}

void withdraw(std::vector<Account*>& accounts)
{
	
	/*=====Make A Withdraw And Add An Operation Of "Debit" To The Account=====*/

	std::cout << "Please type the agency of your account " << std::endl;
	std::string _Agency;
	inputNumber(_Agency);
			
	std::cout << "Please type the number of your account " << std::endl;
	std::string _Number;
	inputNumber(_Number);

	for(auto it = accounts.begin(); it != accounts.end() ; it++)
	{
		if( ((*it)->getAgency() == _Agency) && ( (*it)->getNumber() == _Number) )
		{
			std::cout << "Account found!" << std::endl;
			std::cout << (**it);
			
			verifyPassword((**it));

			std::cout << "Your account has:" << std::endl;
			std::cout << "U$" << (*it)->getBalance() << std::endl;

			std::cout << "Please type the value of the withdraw" << std::endl;
			std::string _Value;

			while(std::getline(std::cin , _Value))
			{	
				float value = stof(_Value);

				if( ( (*it)->getType_account() == Special) && (value > (*it)->getLimit() ) )
				{
					std::cout << "Error!" << std::endl;
					std::cout << std::setprecision(2) << std::fixed 
					<< "Your account has a limit to withdraw of: U$" << (*it)->getLimit() << std::endl;
					std::cout << "Please type the value of the withdraw" << std::endl;
					continue;
				}

				if( value > (*it)->getBalance() )
				{
					std::cout << "Error!" << std::endl;
					std::cout << "Insufficient funds" << std::endl;
					std::cout << "Please type the value of the withdraw" << std::endl;
					continue;
				}

				if( value < (*it)->getBalance() )
				{
					float new_balance = (*it)->getBalance() - value;
					(*it)->setBalance(new_balance);

					Operation* op = new Operation("Withdraw",Debit,value);

					(*it)->addOperation(op);

					std::cout << "Withdraw sucessfull" << std::endl;
					break;
				}
			}

			return ;
		}
	}

	std::cout << "Error! Account not found" << std::endl;
}

void deleteAccount(std::vector<Account*>& accounts)
{

	/*=====Delete An Account Of The Bank=====*/

	std::cout << "Please type the agency of your account " << std::endl;
	std::string _Agency;
	inputNumber(_Agency);
			
	std::cout << "Please type the number of your account " << std::endl;
	std::string _Number;
	inputNumber(_Number);

	for(auto it = accounts.begin() ; it != accounts.end() ; it++)
	{
		if( ((*it)->getAgency() == _Agency) && ( (*it)->getNumber() == _Number) )
		{
			std::cout << "Account found!" << std::endl;
			std::cout << (**it);
			
			verifyPassword((**it));
			std::cout << "Are you sure that you want to delete your account?" << std::endl;

			bool option_User = verifyYes_No();

			if(option_User == false)
			{
				return ;
			}

			if(option_User == true)
			{
				accounts.erase(it);
				Account::TotalAccounts--;
				std::cout << "Account delet sucesfull" << std::endl;
				return ;
			}
		}
	}

	std::cout << "Error! Account not found" << std::endl;
}

void listAccounts(std::vector<Account*>& accounts)
{	
	/*=====List All The Accounts Of The Bank=====*/

	int i = 1;

	std::cout << "The bank has a total of " << Account::getTotalAccounts() << " accounts" << std::endl;

	for(auto it = accounts.begin() ; it != accounts.end() ; it++)
	{	
		std::cout << "Account " << i++ << ":" << std::endl;
		std::cout << (**it);
	}
}

void transfer(std::vector<Account*>& accounts)
{
	/*=====Make A Transference From "A" To "B",Adding An Operation Of "Debit" To A, And "Credit" To B=====*/

	std::cout << "Please type the agency of your account " << std::endl;
	std::string Your_Agency;
	inputNumber(Your_Agency);
			
	std::cout << "Please type the number of your account " << std::endl;
	std::string Your_Number;
	inputNumber(Your_Number);

	for(auto it = accounts.begin() ; it != accounts.end() ; it++)
	{
		if( ((*it)->getAgency() == Your_Agency) && ( (*it)->getNumber() == Your_Number) )
		{
			std::cout << "Account found!" << std::endl;
			std::cout << (**it);
			verifyPassword((**it));

			std::cout << "Your account has:" << std::endl;
			std::cout<< std::setprecision(2) << std::fixed << "U$" << (*it)->getBalance() << std::endl;

			std::cout << "Please type the agency of the account that you wish to transfer " << std::endl;
			std::string Acc_Agency;
			inputNumber(Acc_Agency);
					
			std::cout << "Please type the number of the account that you wish to transfer " << std::endl;
			std::string Acc_Number;
			inputNumber(Acc_Number);

			for(auto iterator = accounts.begin() ; iterator != accounts.end() ; iterator++)
			{
				if( ( (*iterator)->getAgency() == Acc_Agency) && ( (*iterator)->getNumber() == Acc_Number) )
				{
					std::cout << "Account found!" << std::endl;
					std::cout << (**iterator);

					std::cout << "Please type the value that you want to transfer" << std::endl;
					std::string _value_;

					while(std::getline(std::cin , _value_))
					{
						float Value = stof(_value_);

						if(Value > (*it)->getBalance())
						{
							std::cout << "Error! Insufficient funds" << std::endl;
							continue;
						}

						if(Value < (*it)->getBalance())
						{
							float new_balance = (*it)->getBalance() - Value;
							(*it)->setBalance(new_balance);

							float new_balance_T = (*iterator)->getBalance() + Value;
							(*iterator)->setBalance(new_balance_T);

							Operation* op = new Operation("Transference",Debit,Value);
							(*it)->addOperation(op);

							Operation* op_T = new Operation("Transference",Credit,Value);
							(*iterator)->addOperation(op_T);

							std::cout << "Transference sucessfull" << std::endl;

							return;
						}
					}
				}
			}
			std::cout << "Error! Account not found" << std::endl;
			return ;
		}
	}
	std::cout << "Error! Account not found" << std::endl;
}

void seeBalance(std::vector<Account*>& accounts)
{	
	/*=====See The Current Balance Of Your Account=====*/
	
	std::cout << "Please type the agency of your account " << std::endl;
	std::string Your_Agency;
	inputNumber(Your_Agency);
			
	std::cout << "Please type the number of your account " << std::endl;
	std::string Your_Number;
	inputNumber(Your_Number);

	for(auto it = accounts.begin() ; it != accounts.end() ; it++)
	{
		if( ((*it)->getAgency() == Your_Agency) && ( (*it)->getNumber() == Your_Number) )
		{
			std::cout << "Account found!" << std::endl;
			std::cout << (**it);
			
			verifyPassword((**it));

			std::cout << "Your account has:" << std::endl;
			std::cout << std::setprecision(2) << std::fixed  << "U$" << (*it)->getBalance() << std::endl;

		}
	}
}

void BankStatement(std::vector<Account*>& accounts)
{
	/*=====See The Bank Statement Of Your Account=====*/

	std::cout << "Please type the agency of your account " << std::endl;
	std::string Your_Agency;
	inputNumber(Your_Agency);
			
	std::cout << "Please type the number of your account " << std::endl;
	std::string Your_Number;
	inputNumber(Your_Number);

	for(auto it = accounts.begin() ; it != accounts.end() ; it++)
	{
		if( ((*it)->getAgency() == Your_Agency) && ( (*it)->getNumber() == Your_Number) )
		{
			std::cout << "Account found!" << std::endl;
			std::cout << (**it);
			
			verifyPassword((**it));

			std::cout << "Your account has:" << std::endl;
			std::cout << std::setprecision(2) << std::fixed  << "U$" << (*it)->getBalance() << std::endl;

			std::cout << "Operations performed:" << std::endl << std::endl;

			for(auto it_o = (*it)->operationsBEGIN() ; it_o != (*it)->operationsEND() ; it_o ++)
			{
				std::cout << (**it_o);
			}
		}
	}
}

/*=====VERIFY FUNCTIONS=====*/

bool verifyAccount(std::string& _agency_,std::string& _number_,std::vector<Account*>& accounts)
{
	for(auto it = accounts.begin(); it != accounts.end() ; it++)
	{
		if( _agency_ == (*it)->getAgency())
		{
			if(_number_ == (*it)->getNumber())
			{
				std::cout << "This account already exist!" << std::endl;
				std::cout << "Type a diferent number" << std::endl;
				return true;
			}
		}
	}
	return false;
}

bool verifyYes_No()
{
	std::string option;
	while(std::getline(std::cin , option))
	{
		if((option == "Y") || (option == "y"))
		{
			return true;
		}

		if((option == "N") || (option == "n"))
		{
			return false;
		}
	}
	return false;
}

void verifyPassword(Account& acc)
{
	std::cout << "Please type your password" << std::endl;
	std::string _password_;
	while(std::getline(std::cin , _password_))
	{
		if(_password_ == acc.getPassword())
		{
			std::cout << "Correct Password" << std::endl << std::endl;
			return ;
		}

		else
		{	
			std::cout << "Wrong Password" << std::endl << std::endl;
			std::cout << "Please type your password" << std::endl;
		}
	}
}

/*=====MESSAGE FUNCTIONS=====*/

void beginMessage()
{
	std::cout << "==================================" << std::endl;
	std::cout << ">>Welcome to the Bank Simulator! " << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << "Type one of the following numbers to do the option after the ():" << std::endl;
}

void menu()
{
	std::cout << "(0)Leave the Program" << std::endl;
	std::cout << "(1)Create a account" << std::endl;
	std::cout << "(2)Make a deposit" << std::endl;
	std::cout << "(3)To Withdraw" << std::endl;
	std::cout << "(4)Delete a account" << std::endl;
	std::cout << "(5)List all accounts of the bank" << std::endl;
	std::cout << "(6)Make a transference" << std::endl;
	std::cout << "(7)Balance of your account" << std::endl;
	std::cout << "(8)See the bank statement of your account" << std::endl;
}

/*=====INPUT FUNCTIONS=====*/

void inputNumber(std::string& number)
{
	int _int_helper;

	while(std::getline(std::cin , number) )
	{
		std::stringstream ss(number);

		if(ss >> _int_helper && ss.eof())
		{
			std::cout << "Valid input: " << number << std::endl;
			return ;
		}

		std::cout << "Error! invalid input. " << std::endl;

	}
}

void inputNumberF(std::string& number)
{
	float _float_helper;

	while(std::getline(std::cin , number) )
	{
		std::stringstream ss(number);

		if(ss >> _float_helper && ss.eof())
		{
			std::cout << "Valid input: " << number << std::endl;
			return ;
		}

		std::cout << "Error! invalid input. " << std::endl;

	}
}