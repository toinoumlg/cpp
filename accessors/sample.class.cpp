/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/12 17:01:25 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"

Sample::Sample() {
	std::cout << "Constructor called" << std::endl;
	this->setFoo(5);
	std::cout << "foo = " << this->_foo << std::endl;
}

Sample::~Sample() {
	std::cout << "Destructor called" << std::endl;
}

int Sample::getFoo() const {
	return (this->_foo);
}

void Sample::setFoo(int value) {
	if (value >= 0)
		this->_foo = value;
}
