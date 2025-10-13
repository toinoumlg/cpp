/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample1.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/12 15:24:42 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample1.class.hpp"

Sample1::Sample1(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) {
	std::cout << "Constructor called" << std::endl;
	std::cout << "a1 : " << this->a1 << std::endl;
	std::cout << "a2 : " << this->a2 << std::endl;
	std::cout << "a3 : " << this->a3 << std::endl;
}

Sample1::~Sample1() {
	std::cout << "Destructor called" << std::endl;
}
