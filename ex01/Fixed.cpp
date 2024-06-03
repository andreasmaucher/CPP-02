/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/06/03 17:43:53 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point = 0;
}

// shifts the integer n left by _fract_bits positions
// -> converts int to fixed-point
Fixed::Fixed(const int n): _fixed_point(n << _fract_bits) 
{
    std::cout << "Int constructor called" << std::endl;
}

// -> convert float to fixed-point
// roundf: rounds the result to the nearest int
Fixed::Fixed(const float n): _fixed_point(roundf(n * (1 << _fract_bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}

// Copy assignment operator overload; only copies if the current object is
// different from the 'other' object
// other.getRawBits(): Calls the getRawBits method on the other object, 
// which returns the raw fixed-point value stored in other.
Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixed_point = other.getRawBits();
	std::cout <<"Copy assignment operator called" << std::endl;
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->_fixed_point;
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixed_point = raw;
}

// converts the fixed-point value to a floating-point value.
float   Fixed::toFloat(void) const
{
    return static_cast<float>(this->getRawBits()) / (1 << _fract_bits);
}

// converts the fixed-point value to an integer value
int     Fixed::toInt(void) const
{
    return this->_fixed_point >> _fract_bits;
}

// allows to insert data into the output stream
// o is the output stream & '<<' the insertion operator
// the result of i.toFloat() is inserted into the output stream 'o'
std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return o;
}