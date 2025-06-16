/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:04:59 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/01 18:16:18 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(0.0f, 3.0f);
	Point c(4.0f, 0.0f);

	Point inside(1.0f, 1.0f);
	Point outside(4.0f, 3.0f);
	Point edge(0.0f, 1.5f);
	Point vertex(0.0f, 0.0f);

	std::cout << "Inside: " << (bsp(a, b, c, inside) ? "True" : "False") << std::endl;
	std::cout << "Outside: " << (bsp(a, b, c, outside) ? "True" : "False") << std::endl;
	std::cout << "Edge: " << (bsp(a, b, c, edge) ? "True" : "False") << std::endl;
	std::cout << "Vertex: " << (bsp(a, b, c, vertex) ? "True" : "False") << std::endl;

	return 0;
}
