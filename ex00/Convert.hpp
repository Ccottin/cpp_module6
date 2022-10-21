/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 05:53:25 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/21 03:50:30 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>
# include "Convert.hpp"

typedef	enum eType {
			CHAR,		//0
			INT,		//1
			FLOAT,		//2
			DOUBLE,		//3
			DEFAULT,	//4
			EMPTY		//5
}			tType;

class Converted {

	public :
		
		Converted(void);
		Converted(std::string const &str, tType const type);
		Converted(Converted const &ref);
		Converted &operator=(Converted const &ref);
		virtual ~Converted(void);

		tType const	&		getType(void) const ;
		std::string const &	getData(void) const ;

		void			isChar(void) const;
		void			isInt(void) const;
		void			isFloat(void) const;
		void			isDouble(void) const;

	private :

		std::string const	_data;
		tType const			_type;

};

#endif
