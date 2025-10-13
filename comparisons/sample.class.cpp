/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/12 17:12:33 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"

Sample::Sample(int value) : _foo(value) {
	std::cout << "Constructor called" << std::endl;
}

Sample::~Sample() {
	std::cout << "Destructor called" << std::endl;
}

int Sample::getFoo() const {
	return (this->_foo);
}

int Sample::compare(Sample *other) const {
	if (this->_foo < other->getFoo())
		return (-1);
	else if (this->_foo > other->getFoo())
		return (1);
	return (0);
}

void Sample::setFoo(int value) {
	if (value >= 0)
		this->_foo = value;
}
