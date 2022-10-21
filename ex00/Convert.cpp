/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:35:29 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/21 05:37:35 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <cmath> //could be useful for inf and nan
//#include <climits> //int lim
//#include <cfloat> //float lim
//#include <limits> //should do it for all isntead
#include <iostream>
#include <cstdlib>
#include <string>
#include "Convert.hpp"
/*gerer le cas des + et - que ascii*/
void	Converted::isChar(void) const
{
	char	c;

	c = getData()[0];
	std::cout << "char: " << c << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "int: "	<< static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}
/*gerer les cas des nan et autre + overflow et lims, gerer l overflow de int max*/
void	Converted::isInt(void) const
{
	int i;

	i = atoi(getData().c_str());
	std::cout << "char: " << static_cast<char>(i) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1); 
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void	Converted::isFloat(void) const
{
	float	f;

	f = (atof(getData().c_str()));
	if (f / f == 1) //objectif == trucer une vraie condition
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "char: impossible " << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	Converted::isDouble(void) const
{
	double	d;

	d = static_cast<double>(atof(getData().c_str()));
	if (d / d == 1)
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "char: impossible " << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<int>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

/* Canonical Form */


Converted::Converted(void) : _data(""), _type(EMPTY)
{
	std::cout << "Default constructor called" << std::endl;
}

Converted::Converted(std::string const &str, tType const type) : _data(str), _type(type)
{
	std::cout << "Type constructor called" << std::endl;
}

Converted::Converted(Converted const &ref) : _data(ref.getData()),
	_type(ref.getType())
{
	std::cout << "Copy constructor called" << std::endl;
}

Converted	&Converted::operator=(Converted const &ref)
{
	(void)ref;
	std::cout << "Copy operator called" << std::endl;
	return (*this);
}

Converted::~Converted(void)
{
	std::cout << "Destructor called" << std::endl;	
}

/* Getters */

tType const			&Converted::getType(void) const
{
	return (_type);
}

std::string const	&Converted::getData(void) const
{
	return (_data);
}
