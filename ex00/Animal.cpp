/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:19:51 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/09 18:45:36 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("AnimalDefault") {
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const std::string type) : type(type) {
	std::cout << "Animal parameterized constructor" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal assignement operator called" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

const std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Animal made a sound" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructed" << std::endl;
}