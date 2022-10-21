/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:33:56 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/21 04:52:53 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Convert.hpp"
//void	Convert(std::string	s);

eType	FindType(std::string str);


int		main(int ac, char **av)
{
/*	if (ac != 2)
		return (0);
	std::string	literal = static_cast<std::string>(av[1]);
	Converted	converted(litteral, FindType(litteral));
*/	int	i;

	i = 1; //prog ne prend qu un parametre
	while ( i < ac )
	{
	std::string	litteral = static_cast<std::string>(av[i]);
	Converted	converted(litteral, FindType(litteral));
	
	switch (converted.getType())
	{
		case 0 :
			converted.isChar();
			break ;
		case 1 :
			converted.isInt();
			break ;
		case 2 :
			converted.isFloat();
			break ; 
		case 3 :
			converted.isDouble();
			break ;
		default :
			std::cout << "Invalid Input." << std::endl;
	}
	i++;
	}
	return (0);
}
