/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/12 16:12:34 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"

Sample::Sample() : foo(5), _foo(3) {
	std::cout << "Constructor called" << std::endl;
	std::cout << "foo: " << this->foo << " _foo: " << this->_foo << std::endl;
	this->_bar();
	this->bar();
}

Sample::~Sample() {
	std::cout << "Destructor called" << std::endl;
}

void Sample::bar() const {
	std::cout << "publicBar" << std::endl;
}

void Sample::_bar() const {
	std::cout << "privateBar" << std::endl;
}
