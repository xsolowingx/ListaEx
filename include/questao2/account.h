/**
 *@since 09/17/2017
 *@file account.h
 *@brief this file contain the declaration of the class Account.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 09/22/2017
 */
#ifndef account_h
#define account_h

#include "operation.h"
#include <vector>
#include <ostream>

/*=====Enum For The Type Of The Account=====*/

typedef enum str_especial
{
	Special,
	Normal
}TypeAccount;

/*=====Enum To Help In The Program=====*/

typedef enum str_type
{
	Correct,
	Wrong
}TypeHelper;

class Account
{
private:
std::string agency;
std::string number;
std::string password;

TypeAccount type_account;

float limit;
std::vector<Operation*> operations;
float balance;

public:
	/*=====Static Attribute=====*/
	static int TotalAccounts;

	/*=====Static Getter=====*/
	static int getTotalAccounts();

	/*=====Parameterized Constructor=====*/
	Account(std::string _agency,std::string _number,TypeAccount _type_account,std::string _password);

	/*=====Setters=====*/
	void setLimit(float _limit);
	void setBalance(float _balance);

	/*=====Add operations=====*/
	void addOperation(Operation* _operations);

	/*=====Members That Help To Go Through The Operations=====*/
	std::vector<Operation*>::iterator operationsBEGIN();
	std::vector<Operation*>::iterator operationsEND();

	/*=====Getters=====*/
	std::string getAgency();
	std::string getNumber();
	std::string getPassword();
	float getLimit();
	TypeAccount getType_account();
	float getBalance();

	/*=====Destructor Of The Class=====*/
	~Account();

	/*=====Operators Overload=====*/
	bool operator==(Account& acc);
	friend std::ostream& operator <<(std::ostream& o,Account& acc);
};

#endif