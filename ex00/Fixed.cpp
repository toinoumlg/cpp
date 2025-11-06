/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 08:06:02 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
using namespace std;

Fixed::Fixed() : _value(0) {
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed& copy) : _value(copy._value) {
	cout << "Copy constructor called" << endl;
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

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
}