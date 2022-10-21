/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 00:29:40 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/22 01:07:00 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>
# include <string>

typedef	unsigned long int uintptr_t ;

typedef	struct s_Struct {

	int			i;
	std::string	str;
	std::string	moreStr;
}				Data;

#endif
