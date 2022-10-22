/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FindType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:41:24 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/22 16:40:38 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Convert.hpp"

eType	checkElse(std::string str)
{
	if (!str.compare("-inff") || !str.compare("nanf")
		|| !str.compare("+inff"))
		return (FLOAT);
	if (!str.compare("-inf") || !str.compare("nan")
		|| !str.compare("+inf"))
		return (DOUBLE);
	else
		return (DEFAULT);
}

eType	isFloat(std::string str, long unsigned int i, bool number)
{
	long unsigned int const	size = str.size();
	bool					point = false;

	while (i < size)
	{
		if (number == false && (str[i] >= '0' && str[i] <= '9'))
			number = true;
		if (str[i] == '.')
		{
			if (point == true)
				return (DEFAULT);
			i++;
			point = true;
		}
		if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] == '.' && point == false)
			|| (i == size - 1 && str[i] == 'f'))
			i++;
		else
			return (checkElse(str));
	}
	if (i == size && str[i - 1] == 'f' && number == true
			&& point == true)
		return (FLOAT);
	return (DEFAULT);
}

eType	isDouble(std::string str, long unsigned int i, bool number)
{
	long unsigned int const	size = str.size();
	bool					point = false;
	
	while (i < size)
	{
		if (number == false && (str[i] >= '0' && str[i] <= '9'))
			number = true;
		if (str[i] == '.')
		{
			if (point == true)
				return (DEFAULT);
			i++;
			if (i == size && number == true)
				return (DOUBLE);
			point = true;
		}
		if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] == '.' && point == false))
			i++;
		else
			return (DEFAULT);
	}
	if (i == size && number == true && point == true)
		return (DOUBLE);
	return (DEFAULT);
}

eType	FindType(std::string str)
{
	long unsigned int	i;
	bool				number = false;
	
	if (!str.compare(""))
		return (EMPTY);
	i = 0;
	if (str.size() == 1)
	{
		if (str[i] < '0' || str[i] > '9')
			return (CHAR);
		else
			return (INT);
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		number = true;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[str.size() - 1] == 'f')
		return (isFloat(str, i, number));
	if (str[i] == '.')
		return (isDouble(str, i, number));
	if (i == str.size())
		return (INT);
	else
		return (checkElse(str));
}
