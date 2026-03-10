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

#include "../include/Cat.hpp"

#include <iostream>

Cat::Cat() : AAnimal() {
	std::cout << "Cat constructed" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const std::string type) : AAnimal(type) {
	std::cout << "Cat parameterized constructor" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	std::cout << "Cat copy construtor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignement operator called" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	if (_brain)
		delete _brain;
	_brain = new Brain(*other._brain);
	return *this;
}

void Cat::setBrainIdea(std::string idea) {
	_brain->setIdea(idea);
}

void Cat::setBrainIdea(std::string idea, int i) {
	_brain->setIdea(idea, i);
}

std::string Cat::getBrainIdea(int i) {
	return _brain->getIdea(i);
}

void Cat::makeSound() const {
	std::cout << "meow meow 🐱" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destucted" << std::endl;
	delete _brain;
}
