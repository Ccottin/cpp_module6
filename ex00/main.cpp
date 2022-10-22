/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:33:56 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/22 17:03:39 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

eType	FindType(std::string str);


int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	std::string	literal = static_cast<std::string>(av[1]);
	Converted	converted(literal, FindType(literal));
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
	return (0);
}
