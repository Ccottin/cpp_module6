/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:35:29 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/22 18:31:47 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void	Converted::isChar(void) const
{
	char	c;

	c = getData()[0];
	if ((c < 8) || (c > 12 && c < 32) || c == 127)
		std::cout << "char: non displayable " << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "int: "	<< static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	Converted::isInt(void) const
{
	long int	l;
	int			i;

	l = (std::strtol(getData().c_str(), NULL, 10));
	if (errno || l > 2147483647 || l < -2147483648)
	{
		print_impossible();
		return ;
	}
	i = static_cast<int>(l);
	if ( i <= -129 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if ((i > -129 && i < 8) || (i > 12 && i < 32) || i == 127)
		std::cout << "char: non displayable " << std::endl;
	else
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
	
	if (!getData().compare("nanf") || !getData().compare("-inff") 
	|| !getData().compare("+inff"))
	{
		printF(getData());
		return ;
	}
	f = static_cast<float>(std::strtof(getData().c_str(), NULL));
	if (errno)
	{
		print_impossible();
		return ;
	}
	if (f <= -129 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if ((f > -129 && f < 8) || (f > 12 && f < 32) || f == 127
		|| f - static_cast<int>(f) != 0)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	
	if (f > INT_MAX || f < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else	
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	
	std::cout << std::fixed;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	Converted::isDouble(void) const
{
	double	d;

	if (!getData().compare("nan") || !getData().compare("-inf") 
	|| !getData().compare("+inf"))
	{
		printD(getData());
		return ;
	}
	d = static_cast<double>(std::strtod(getData().c_str(), NULL));
	if (errno)
	{
		print_impossible();
		return ;
	}
	if (d <= -129 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if ((d > -129 && d < 8) || (d > 12 && d < 32) || d == 127
		|| d - static_cast<int>(d) != 0)
		std::cout << "char: non displayable " << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else	
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	
	std::cout << std::fixed;
	if (d > FLT_MAX || d < -FLT_MAX)  
		std::cout << "float: imposible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

/* Canonical Form */


Converted::Converted(void) : _data(""), _type(EMPTY)
{
}

Converted::Converted(std::string const &str, tType const type) : _data(str), _type(type)
{
}

Converted::Converted(Converted const &ref) : _data(ref.getData()),
	_type(ref.getType())
{
}

Converted	&Converted::operator=(Converted const &ref)
{
	(void)ref;
	return (*this);
}

Converted::~Converted(void)
{
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
