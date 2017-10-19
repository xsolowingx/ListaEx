/**
 *@since 10/10/2017
 *@file main1.cpp
 *@brief arquivo principal do programa.
 *@author Matheus de Jesus Leandro de Medeiros
 *@date 13/10/2017
 */
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "produto.h"
#include "fruta.h"
#include "roupa.h"
#include "bebida.h"

int main()
{	
	std::vector<std::shared_ptr<Produto>> lista;
	lista.push_back(std::make_shared<Fruta>("001002003-45","Maca verde",8.70,"01/10/2017",18));
	lista.push_back(std::make_shared<Fruta>("001002004-44","Laranja",4.75,"23/09/2017",15));
	lista.push_back(std::make_shared<Fruta>("001002005-11","Limao verde",2.30,"01/10/2017",25));
	lista.push_back(std::make_shared<Roupa>("001002005-69","Camisa esportiva",30.00,"Lacoste",'M',"P adulto"));
	lista.push_back(std::make_shared<Bebida>("001002005-99","Smirnoff",15.75,"41"));

	for (auto it = lista.begin(); it != lista.end(); it++)
	{
		std::cout << (**it) << std::endl;	
	}

	return 0;
}