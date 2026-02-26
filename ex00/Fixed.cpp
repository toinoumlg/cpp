/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/26 20:12:15 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : _value(copy._value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}
void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}