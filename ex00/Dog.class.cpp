/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:19:51 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/03 14:30:13 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

#include <iostream>

Dog::Dog() {
	std::cout << "Dog constructed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "woof woof 🐶" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destucted" << std::endl;
}