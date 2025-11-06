/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 10:59:24 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const Fixed& copy) : _value(copy._value) {
}

Fixed::Fixed(const int value) {
	this->_value = value * (1 << this->_decimal);
}

Fixed::Fixed(const float value) {
	this->_value = value * (1 << this->_decimal) + (value >= 0 ? 0.5 : -0.5);
}

// operation
Fixed& Fixed::operator=(Fixed const& copy) {
	this->_value = copy._value;
	return *this;
}

Fixed Fixed::operator+(Fixed const& addition) const {
	return this->toFloat() + addition.toFloat();
}
Fixed Fixed::operator-(Fixed const& negate) const {
	return this->toFloat() - negate.toFloat();
}
Fixed Fixed::operator*(Fixed const& mult) const {
	return this->toFloat() * mult.toFloat();
}

Fixed Fixed::operator/(Fixed const& divider) const {
	return this->toFloat() / divider.toFloat();
}

// increment/decrement
Fixed& Fixed::operator++() {
	++this->_value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++this->_value;
	return tmp;
}

Fixed& Fixed::operator--() {
	--this->_value;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--this->_value;
	return tmp;
}

// comparaison
Fixed Fixed::operator>(Fixed const& cmp) const {
	return this->_value > cmp._value;
}

Fixed Fixed::operator>=(Fixed const& cmp) const {
	return this->_value >= cmp._value;
}

Fixed Fixed::operator<(Fixed const& cmp) const {
	return this->_value < cmp._value;
}

Fixed Fixed::operator<=(Fixed const& cmp) const {
	return this->_value <= cmp._value;
}

Fixed Fixed::operator==(Fixed const& cmp) const {
	return this->_value == cmp._value;
}

Fixed Fixed::operator!=(Fixed const& cmp) const {
	return this->_value != cmp._value;
}

int Fixed::getRawBits() const {
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

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
	if (f1._value > f2._value)
		return f2;
	else
		return f1;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
	if (f1._value > f2._value)
		return f2;
	else
		return f1;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
	if (f1._value < f2._value)
		return f2;
	else
		return f1;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
	if (f1._value < f2._value)
		return f2;
	else
		return f1;
}

Fixed::~Fixed() {
}

ostream& operator<<(ostream& output, Fixed const& fixed) {
	output << fixed.toFloat();
	return output;
}