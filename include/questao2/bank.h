/**
 *@since 09/17/2017
 *@file bank.h
 *@brief this file contain the declaration of the functions that the bank do.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 09/22/2017
 */
#ifndef bank_h
#define bank_h

#include "account.h"

void createAccount(std::vector<Account*>& accounts);
void deposit(std::vector<Account*>& accounts);
void withdraw(std::vector<Account*>& accounts);
void deleteAccount(std::vector<Account*>& accounts);
void listAccounts(std::vector<Account*>& accounts);
void transfer(std::vector<Account*>& accounts);
void seeBalance(std::vector<Account*>& accounts);
void BankStatement(std::vector<Account*>& accounts);

bool verifyAccount(std::string& _agency_,std::string& _number_,std::vector<Account*>& accounts);
bool verifyYes_No();
void verifyPassword(Account& acc);

void beginMessage();
void menu();

void inputNumber(std::string& number);
void inputNumberF(std::string& number);

#endif