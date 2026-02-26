/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/26 20:05:17 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : _value(copy._value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value * (1 << this->_decimal);
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_value =
	    value * float(1 << this->_decimal) + (value >= 0 ? 0.5 : -0.5);
}

Fixed& Fixed::operator=(Fixed const& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy._value;
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat() const {
	return this->_value / float(1 << this->_decimal);
}

int Fixed::toInt() const {
	return this->_value / (1 << this->_decimal);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& output, Fixed const& fixed) {
	output << fixed.toFloat();
	return output;
}