/**
 *@since 09/17/2017
 *@file account.cpp
 *@brief this file contain the implementation of the class Account.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 10/23/2017
 */
#include "account.h"
#include <iostream>
#include <sstream>

/*=====Static Member Of Account To Have An Idea Of How Many Accounts The Bank Have=====*/

int Account::TotalAccounts = 0;

/*=====Static Function Of Account=====*/

int Account::getTotalAccounts()
{
	return TotalAccounts;
}

/*=====Constructor Of The Class Account=====*/

Account::Account(std::string _agency,std::string _number,TypeAccount _type_account,std::string _password)
{
	this->agency = _agency;
	this->number = _number;
	this->type_account = _type_account;
	this->password = _password;

	if(this->type_account == Special)
	{
		this->limit = 500.00;
	}
	TotalAccounts++;
}

/*=====Set Methods=====*/

void Account::setLimit(float _limit)
{
	this->limit = _limit;
}

void Account::setBalance(float _balance)
{
	this->balance = _balance;
}

/*=====Add Operations To The Account, So The Bank Can Show The Bank Statement=====*/

void Account::addOperation(Operation* _operations)
{
	this->operations.push_back(_operations);
}

/*=====Get Methods=====*/

std::string Account::getAgency()
{
	return agency;
}
	
std::string Account::getNumber()
{
	return number;
}

std::string Account::getPassword()
{
	return password;
}

float Account::getLimit()
{
	return limit;
}

TypeAccount Account::getType_account()
{
	return type_account;
}

float Account::getBalance()
{
	return balance;
}

/*=====Destructor Of The Class=====*/

Account::~Account()
{
	delete[] operations[0];
}

/*=====Overload Of The Operator "=="=====*/

bool Account::operator==(Account& acc)
{
	if(this->number == acc.getNumber())
	{
		return true;
	}

	else 
		return false;
}

/*=====Overload Of The Operator "<<"=====*/

std::ostream& operator <<(std::ostream& o,Account& acc)
{
	o << "Agency: " << acc.getAgency() << std::endl
	<< "Number: " << acc.getNumber() << std::endl;
	
	if(acc.getType_account() == Special)
	{
		o << "Type: Special" << std::endl << std::endl;
	}
	
	else if(acc.getType_account() == Normal)
	{
		o << "Type: Normal" << std::endl << std::endl;
	}

	return o;
}

/*=====Functions That Returns An Iterator Pointing To The Vector Operations=====*/

std::vector<Operation*>::iterator Account::operationsBEGIN()
{
	return this->operations.begin();
}

std::vector<Operation*>::iterator Account::operationsEND()
{
	return this->operations.end();
}