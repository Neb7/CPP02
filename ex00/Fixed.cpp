/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:14:11 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/02 17:14:07 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief	Default constructor for Fixed class.
 */
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief	Copy constructor for Fixed class.
 * 
 * @param	origin The Fixed object to copy from.
 */
Fixed::Fixed(Fixed &origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

/**
 * @brief	Copy assignment operator for Fixed class.
 * 
 * @param	other The Fixed object to assign from.
 * @return	A reference to the current object.
 */
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

/**
 * @brief	Destructor for Fixed class.
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * @brief	Returns the value of the fixed-point number without any conversion.
 * 
 * @return	The value
 */
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

/**
 * @brief	Initializes the value of the fixed-point number with the one passed
 * 			as a parameter.
 * 
 * @param	raw The value.
 */
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

