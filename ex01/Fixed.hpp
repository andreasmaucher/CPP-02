/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/06/03 14:08:37 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

class Fixed
{
	private:
		int					_fixed_point;
		static const int 	_fract_bits = 8;
	
	public:
		// Default constructor
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		// Copy constructor (create a new object as a copy of an existing one)
		Fixed(const Fixed &other);
		// Copy assignment operator overload (an already initialized object is
		// assigned the value of another object)
		Fixed& operator=(const Fixed &other);
		// Destructor (in this case no dynamically allocated resources)
		~Fixed();
		
		// getter
		int 	getRawBits(void) const;
		// setter
		void 	setRawBits(int const raw);
		float 	toFloat(void) const;
		int 	toInt(void) const;
};

std::ostream & operator<<( std::ostream & other, Fixed const & i );

#endif