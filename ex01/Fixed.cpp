/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:14:11 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/03 11:17:48 by benpicar         ###   ########.fr       */
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
 */
Fixed::Fixed(Fixed const &origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

/**
 * @brief	Constructor that initializes the fixed-point number with 
 * 			an integer value.
 */
Fixed::Fixed(int const val) : _value(val << _frac)
{
	std::cout << "Int constructor called" << std::endl;
}

/**
 * @brief	Constructor that initializes the fixed-point number with
 * 			a floating-point value.
 */
Fixed::Fixed(float const flo) : _value(roundf(flo * (1 << _frac)))
{
	std::cout << "Float constructor called" << std::endl;
}

/**
 * @brief	Destructor for Fixed class.
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
 * @brief	Returns the value of the fixed-point number without any conversion.
 * 
 * @return	The raw value
 */
int	Fixed::getRawBits(void) const
{
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
	this->_value = raw;
}

/**
 * @brief	Converts the fixed-point number to a floating-point number.
 * 
 * @return	The floating-point representation of the fixed-point number.
 */
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _frac));
}

/**
 * @brief	Converts the fixed-point number to an integer.
 * 
 * @return	The integer representation of the fixed-point number.
 */
int	Fixed::toInt(void) const
{
	return (_value >> _frac);
}

/**
 * @brief	Overloads the output stream operator to print the fixed-point number.
 * 
 * @param	os The output stream.
 * @param	fixed The Fixed object to print.
 */
std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
