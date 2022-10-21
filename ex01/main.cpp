/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 00:28:24 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/22 01:07:49 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void	print_members(Data d)
{
	std::cout << "print int : " << d.i << std::endl;
	std::cout << "print str : " << d.str << std::endl;
	std::cout << "print moreStr : " << d.moreStr << std::endl;
}

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main(void)
{
	uintptr_t	raw;
	Data		*ptr;
	Data		data;

	data.i = 7;
	data.str = "Hello World";
	data.moreStr = "This time i will make it longer but i dont think it would have an impact";
	std::cout << "data address = " << &data << std::endl;
	raw = serialize(&data);
	ptr = deserialize(raw);
	std::cout << "ptr address = " << ptr << std::endl;
	print_members(*ptr);
	return (0);
}
