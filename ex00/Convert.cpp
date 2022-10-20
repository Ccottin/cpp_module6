/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:35:29 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/20 06:09:34 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath> //could be useful for inf and nan
#include <climits> //int lim
#include <cfloat> //float lim
#include <limits> //should do it for all isntead
#include <iostream>
#include <typeinfo>

void	convertChar(std::string s)
{
//	char	*c;

//	*c = reinter_cast<char*>(s);
//	std::cout << "char : " << *c << std::endl;
}

void	Convert(std::string	s)
{
	std::cout << s.data() << std::endl;
//	convertChar(s);
}
