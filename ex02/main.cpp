/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:10:02 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/22 18:33:59 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	A	*a = new A;
	B	*b = new B;
	C	*c = new C;

	int	i;

	std::srand(std::time(NULL));
	i = std::rand() %3;
	switch (i)
	{
		case (0) :
			std::cout << "val returned = A" << std::endl;
			delete b;
			delete c;
			return (a);
		case (1) :
			std::cout << "val returned = B" << std::endl;
			delete a;
			delete c;
			return (b);
		default :
			std::cout << "val returned = C" << std::endl;
			delete b;
			delete a;
			return (c);
	}
}

void	identify(Base *p)
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A*>(p);
	if (a != NULL)
		std::cout << "Class is type A" << std::endl;
	b = dynamic_cast<B*>(p);
	if (b != NULL)
		std::cout << "Class is type B" << std::endl;
	c = dynamic_cast<C* >(p);
	if (c!= NULL)
		std::cout << "Class is type C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "class is type A" << std::endl;
		return ;

	}
	catch (std::exception &e)
	{ }
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "class is type B" << std::endl;
		return ;

	} 
	catch (std::exception &e)
	{ }
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "class is type C" << std::endl;
		return ;

	} 
	catch (std::exception &e)
	{ }
}


int	main(void)
{
	Base	*base;

	base = generate();
	identify(base);
	identify(base);
	delete base;
}
