/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:50:33 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 19:05:53 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"

Animal::Animal() {}
Animal::Animal(Animal const &) {}

Animal &Animal::operator=(Animal const &) {}

void Animal::run(int distance) {}

Animal::~Animal() {}

Cat::Cat() {}
Cat::Cat(Cat const &) {}

Cat &Cat::operator=(Cat const &) {}

void Cat::scornSomeone(std::string const &target) {}

Cat::~Cat() {}

Pony::Pony() {}
Pony::Pony(Pony const &) {}

Pony &Pony::operator=(Pony const &) {}

void Pony::doMagic(std::string const &target) {}

Pony::~Pony() {}