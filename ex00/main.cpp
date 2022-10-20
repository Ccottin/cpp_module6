/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:33:56 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/20 05:36:40 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	Convert(std::string	s);

int		main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	
	int	i;

	i = 1;
	while (i < ac)
		Convert(av[i++]);
	return (0);
}
