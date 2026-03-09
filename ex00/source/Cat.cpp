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

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal() {
	std::cout << "Cat constructed" << std::endl;
	type = "Cat";
}

Cat::Cat(const std::string type) : Animal() {
	std::cout << "Cat parameterized constructor" << std::endl;
	this->type = type;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy construtor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignement operator called";
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "meow meow 🐱" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destucted" << std::endl;
}
