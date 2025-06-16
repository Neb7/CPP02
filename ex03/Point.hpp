/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:24:06 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/16 14:06:22 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

/**
 * @brief Represents a point in 2D space using fixed-point coordinates.
 */
class Point
{
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		Point();
		Point(float const a, float const b);
		Point(Point &origin);
		Point	&operator=(const Point &other);
		~Point();
		Fixed	getX() const;
		Fixed	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
