/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/06/03 15:10:31 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	// Create a constant Fixed object 'b' initialized with the product of 
	// two Fixed objects: 5.05f and 2
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	// Output the value of 'a' to the standard output
	std::cout << a << std::endl;
	// Pre-increment 'a' and output the result
	std::cout << ++a << std::endl;
	// Output the value of 'a' after pre-increment
	std::cout << a << std::endl;
	// Post-increment 'a' and output the value before the increment
    std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	// Output the value of 'a' after post-increment
	std::cout << a << std::endl;
	// Output the value of 'b' to the standard output
	std::cout << b << std::endl;
	// Output the maximum value between 'a' and 'b'
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}