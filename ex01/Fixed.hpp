/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:05:37 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/03 11:34:38 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

/**
 * @brief Represents a fixed-point number.
 */
class Fixed
{
	private:
		int					_value;
		static const int	_frac = 8;

	public:
		Fixed();
		Fixed(Fixed const &origin);
		Fixed(int const val);
		Fixed(float const flo);
		~Fixed();
		Fixed	&operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif
