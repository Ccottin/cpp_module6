/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:10:02 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/22 01:37:56 by ccottin          ###   ########.fr       */
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

	srand(time(NULL));
	i = rand() %3;
	switch (i)
	{
		case (0) :
			return (a);
		case (1) :
			return (b);
		default :
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
/*
void	identifyy(Base &p) // a modifier
{
	try
	{
		dynamic_cast<A*>(p);
		std::cout << "class is type A" << std::endl;
		return ;

	} catch { }
	try
	{
		dynamic_cast<B*>(p);
		std::cout << "class is type B" << std::endl;
		return ;

	} catch { }
	try
	{
		dynamic_cast<C*>(p);
		std::cout << "class is type C" << std::endl;
		return ;

	} catch { }

}
*/
int	main(void)
{
	Base	*base;

	base = generate();
	identify(base);
	base = generate();
//	identifyy(base);
	delete base;
}
