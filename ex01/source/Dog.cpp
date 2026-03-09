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

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "Dog constructed" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const std::string type) : Animal(type) {
	std::cout << "Dog parameterized constructor" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy construtor called" << std::endl;
	brain = new Brain();
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignement operator called";
	if (this == &other)
		return *this;
	type = other.type;
	brain = other.brain;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "woof woof 🐶" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destuctred" << std::endl;
	delete brain;
}