/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:35:43 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/10 13:18:42 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat constructed" << std::endl;
	type = "WrongCatDefault";
}

WrongCat::WrongCat(const std::string type) : WrongAnimal() {
	std::cout << "WrongCat parameterized constructor" << std::endl;
	this->type = type;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy construtor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat assignement operator called";
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "WRONG meow meow 🐱" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Cat destucted" << std::endl;
}
