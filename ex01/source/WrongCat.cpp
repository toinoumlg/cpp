/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:35:43 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/10 16:17:21 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat constructed" << std::endl;
	type = "WrongCatDefault";
	_brain = new Brain();
}

WrongCat::WrongCat(const std::string type) : WrongAnimal() {
	std::cout << "WrongCat parameterized constructor" << std::endl;
	this->type = type;
	_brain = new Brain();
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy construtor called" << std::endl;
	_brain = new Brain();
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat assignement operator called";
	if (this == &other)
		return *this;
	type = other.type;
	_brain = new Brain(*other._brain);
	return *this;
}

void WrongCat::setBrainIdea(std::string idea) {
	_brain->setIdea(idea);
}

void WrongCat::setBrainIdea(std::string idea, int i) {
	_brain->setIdea(idea, i);
}

std::string WrongCat::getBrainIdea(int i) const {
	return _brain->getIdea(i);
}

void WrongCat::makeSound() const {
	std::cout << "WRONG meow meow 🐱" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Cat destucted" << std::endl;
}
