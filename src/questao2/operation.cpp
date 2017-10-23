/**
 *@since 09/17/2017
 *@file operation.cpp
 *@brief this file contain the implementation of the class Operation.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 10/23/2017
 */
#include "operation.h"

/*=====Constructor=====*/

Operation::Operation(std::string _description,TypeOperation _type_operation,float _value)
{
	this->description = _description;
	this->type_operation = _type_operation;
	this->value = _value;
}

/*=====Get Methods=====*/

float Operation::getValue()
{
	return value;
}

std::string Operation::getDescription()
{
	return description;
}

TypeOperation Operation::getType_operation()
{
	return type_operation;
}

/*=====Overload Of The Operator "<<"=====*/

std::ostream& operator <<(std::ostream& o,Operation operation)
{
	o << "Description: " << operation.getDescription() << std::endl;
	
	if(operation.getType_operation() == Debit)
	{
		o << "Operation type: Debit" << std::endl;
	}

	else if(operation.getType_operation() == Credit)
	{
		o << "Operation type: Credit" << std::endl;
	}

	o << "Value: " << operation.getValue() << std::endl << std::endl;
	
	return o;
}