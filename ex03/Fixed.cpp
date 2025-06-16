/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:14:11 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/03 11:36:37 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief	Default constructor for Fixed class.
 */
Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief	Copy constructor for Fixed class.
 * 
 * @param	origin The Fixed object to copy from.
 */
Fixed::Fixed(Fixed const &origin)
{
	// std::cout << "Copy constructor called" << std::endl;
	//_value = origin.getRawBits();
	*this = origin;
}

/**
 * @brief	Constructor that initializes the fixed-point number with
 * 			an integer value.
 * 
 * @param	val The integer value to initialize the fixed-point number.
 */
Fixed::Fixed(int const val) : _value(val << _frac)
{
	// std::cout << "Int constructor called" << std::endl;
}

/**
 * @brief	Constructor that initializes the fixed-point number with
 * 			a floating-point value.
 * 
 * @param	flo The floating-point value to initialize the fixed-point number.
 */
Fixed::Fixed(float const flo) : _value(roundf(flo * (1 << _frac)))
{
	// std::cout << "Float constructor called" << std::endl;
}

/**
 * @brief	Destructor for Fixed class.
 */
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

/**
 * @brief	Copy assignment operator for Fixed class.
 * 
 * @param	other The Fixed object to assign from.
 * @return	A reference to the current object.
 */
Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

/**
 * @brief	Returns the value of the fixed-point number without any conversion.
 * 
 * @return	The value of the fixed-point number.
 */
int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

/**
 * @brief	Sets the value of the fixed-point number without any conversion.
 * 
 * @param	raw The value to set.
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
 * @brief	Overloaded comparison operators for Fixed class.
 * 
 * These operators allow comparison between two Fixed objects.
 */
bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

/**
 * @brief	Overloaded comparison operators for Fixed class.
 * 
 * These operators allow comparison between two Fixed objects.
 */
bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

/**
 * @brief	Overloaded comparison operators >= for Fixed class.
 * 
 * These operators allow comparison between two Fixed objects.
 */
bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

/**
 * @brief	Overloaded comparison operators <= for Fixed class.
 * 
 * These operators allow comparison between two Fixed objects.
 */
bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

/**
 * @brief	Overloaded comparison operators == for Fixed class.
 * 
 * These operators allow comparison between two Fixed objects.
 */
bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

/**
 * @brief	Overloaded comparison operators != for Fixed class.
 * 
 * These operators allow comparison between two Fixed objects.
 */
bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

/**
 * @brief	Overloaded arithmetic operators + for Fixed class.
 * 
 * These operators allow addition between two Fixed objects.
 */
Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	tmp = this->_value;

	tmp.setRawBits(this->_value + other._value);
	return (tmp);
}

/**
 * @brief	Overloaded arithmetic operators - for Fixed class.
 * 
 * These operators allow subtraction between two Fixed objects.
 */
Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	tmp = this->_value;

	tmp.setRawBits(this->_value - other._value);
	return (tmp);
}

/**
 * @brief	Overloaded arithmetic operators * for Fixed class.
 * 
 * These operators allow multiplication between two Fixed objects.
 */
Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed		tmp;
	long long	n = static_cast<long long>(this->_value * other._value); 

	tmp.setRawBits(static_cast<int>(n >> _frac));
	return (tmp);
}

/**
 * @brief	Overloaded arithmetic operators / for Fixed class.
 * 
 * These operators allow division between two Fixed objects.
 * If the divisor is zero, an error message is printed and a 
 * default Fixed object is returned.
 */
Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed		tmp;
	long long	n;

	if (other._value == 0)
	{
		std::cerr << "Error: Division by zero." << std::endl;
		return (tmp);
	}
	n = (static_cast<long long>(this->_value) << _frac) / other._value;
	tmp.setRawBits(static_cast<int>(n));
	return (tmp);
}

/**
 * @brief	Overloaded increment and decrement operators for Fixed class.
 * 
 * These operators allow pre-increment, post-increment, pre-decrement, and
 * post-decrement operations on Fixed objects.
 */
Fixed	&Fixed::operator++(void)
{
	(this->_value)++;
	return (*this);
}

/**
 * @brief	Post-increment operator for Fixed class.
 * 
 * @return	A new Fixed object representing the value before incrementing.
 */
Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	++(*this);
	return (tmp);
}

/**
 * @brief	Pre-decrement operator for Fixed class.
 * 
 * @return	A reference to the current object after decrementing.
 */
Fixed	&Fixed::operator--(void)
{
	(this->_value)--;
	return (*this);
}

/**
 * @brief	Post-decrement operator for Fixed class.
 * 
 * @return	A new Fixed object representing the value before decrementing.
 */
Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	--(*this);
	return (tmp);
}

/**
 * @brief	Returns the minimum of two Fixed objects.
 * 
 * @param	a The first Fixed object.
 * @param	b The second Fixed object.
 * @return	The Fixed object with the smaller value.
 */
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}

/**
 * @brief	Returns the minimum of two Fixed objects (const version).
 * 
 * @param	a The first Fixed object.
 * @param	b The second Fixed object.
 * @return	The Fixed object with the smaller value.
 */
Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}

/**
 * @brief	Returns the maximum of two Fixed objects.
 * 
 * @param	a The first Fixed object.
 * @param	b The second Fixed object.
 * @return	The Fixed object with the larger value.
 */
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

/**
 * @brief	Returns the maximum of two Fixed objects (const version).
 * 
 * @param	a The first Fixed object.
 * @param	b The second Fixed object.
 * @return	The Fixed object with the larger value.
 */
Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

/**
 * @brief	Overloads the output stream operator to print the fixed-point number.
 * 
 * @param	os The output stream.
 * @param	fixed The Fixed object to print.
 * @return	The output stream with the fixed-point number printed.
 */
std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
