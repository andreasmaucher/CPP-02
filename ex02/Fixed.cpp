/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/06/03 15:07:02 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	this->_fixed_point = 0;
}

// Int constructor called
Fixed::Fixed( const int n ) : _fixed_point( n << _fract_bits ) 
{	
}

// Float constructor called
Fixed::Fixed( const float n ) : _fixed_point( std::roundf( n * ( 1 << _fract_bits ) ) ) 
{
}

// Copy constructor called
Fixed::Fixed(const Fixed &other)
{
	this->setRawBits(other.getRawBits());
}

// Copy assignment operator called
Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixed_point = other.getRawBits();
	return *this;
}

// Destructor called
Fixed::~Fixed()
{
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

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return o;
}

/* comparison operators */

bool    Fixed::operator>(const Fixed &other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool    Fixed::operator<(const Fixed &other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool   Fixed::operator<=(const Fixed &other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool  Fixed::operator==(const Fixed &other)const
{
    return this->getRawBits() == other.getRawBits();
}

bool    Fixed::operator!=(const Fixed &other)const
{
    return this->getRawBits() != other.getRawBits();
}

/* arithmetic operators */
Fixed   Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed   Fixed::operator*(const Fixed &other) const 
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

/* increment / decrement */
Fixed&   Fixed::operator++(void)
{
    ++this->_fixed_point;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp(*this);
    tmp._fixed_point = this->_fixed_point++;
    return tmp;
}

Fixed& Fixed::operator--(void)
{
    --this->_fixed_point;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    tmp._fixed_point = this->_fixed_point--;
    return tmp;
}

/*
max / min for overload
e.g. min takes as parameters two references a & b on fixed-point
numbers, and returns a reference to the smallest one
*/
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

/* same method as above only this time for constant fixed-points */
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}