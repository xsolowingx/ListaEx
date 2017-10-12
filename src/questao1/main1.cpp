#include <iostream>
#include <vector>
#include <memory>
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

	for (auto it = lista.begin(); it != lista.end(); it++)
	{
		std::cout << (**it) << std::endl;	
	}
	
	return 0;
}