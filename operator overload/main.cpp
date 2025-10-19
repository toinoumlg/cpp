/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:28:53 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 18:05:47 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "integer.class.hpp"

int main(void)
{
    Integer x(30);
    Integer y(10);
    Integer z(0);
    std::cout << "Value of x : " << x << std::endl;
    std::cout << "Value of y : " << y << std::endl;
    y = Integer(12);
    std::cout << "Value of y : " << y << std::endl;
    std::cout << "Value of z : " << z << std::endl;
    z = x + y;
    std::cout << "Value of z : " << z << std::endl;
}