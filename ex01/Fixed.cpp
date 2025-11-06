/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 08:10:00 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed() : _value(0) {
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed& copy) : _value(copy._value) {
	cout << "Copy constructor called" << endl;
}

Fixed::Fixed(const int value) {
	cout << "Int constructor called" << endl;
	this->_value = value * (1 << this->_decimal);
}

Fixed::Fixed(const float value) {
	cout << "Float constructor called" << endl;
	this->_value =
	    value * float(1 << this->_decimal) + (value >= 0 ? 0.5 : -0.5);
}

Fixed& Fixed::operator=(Fixed const& copy) {
	cout << "Copy assignment operator called" << endl;
	this->_value = copy._value;
	return *this;
}

int Fixed::getRawBits() const {
	cout << "getRawBits member function called" << endl;
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
	cout << "Destructor called" << endl;
}

ostream& operator<<(ostream& output, Fixed const& fixed) {
	output << fixed.toFloat();
	return output;
}