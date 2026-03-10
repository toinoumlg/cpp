/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:19:51 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/10 16:43:18 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal() : type("AAnimalDefault") {
	std::cout << "AAnimal constructor" << std::endl;
}

AAnimal::AAnimal(const std::string type) : type(type) {
	std::cout << "AAnimal parameterized constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type) {
	std::cout << "AAnimal copy constructor" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	std::cout << "AAnimal assignement operator called" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

const std::string AAnimal::getType() const {
	return type;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructed" << std::endl;
}