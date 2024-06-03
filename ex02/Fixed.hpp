/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/06/03 14:42:08 by amaucher         ###   ########.fr       */
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
		static const int	_fract_bits = 8;
	
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
		
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
		float 	toFloat(void) const;
		int 	toInt(void) const;

		// 6 comparison operators
		bool    operator>(const Fixed &other) const;
		bool    operator<(const Fixed &other) const;
		bool    operator>=(const Fixed &other) const;
		bool    operator<=(const Fixed &other) const;
		bool    operator==(const Fixed &other) const;
		bool    operator!=(const Fixed &other) const;

		// 4 arithmetic operators
		Fixed   operator+(const Fixed &other) const;
		Fixed   operator-(const Fixed &other) const;
		Fixed   operator*(const Fixed &other) const;
		Fixed   operator/(const Fixed &other) const;

		// 4 increment/decrement operators
		Fixed&  operator++(void); // pre-increment (increment before value is used)
		Fixed   operator++(int); // post-increment (increment after value is used)
		Fixed&  operator--(void); 
		Fixed   operator--(int);

		// 4 public overloaded member functions; '&' == reference
		static 			Fixed& min(Fixed &a, Fixed &b);
		static const 	Fixed& min(const Fixed &a, const Fixed &b);
		static 			Fixed& max( Fixed &a, Fixed &b );
		static const 	Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<( std::ostream & other, Fixed const & i );

#endif