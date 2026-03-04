/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:19:51 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 16:08:34 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal() {
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const std::string type) : type(type) {
	std::cout << "Animal parameterized constructor" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "Animal assignement operator called" << std::endl;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal made a sound" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destucted" << std::endl;
}