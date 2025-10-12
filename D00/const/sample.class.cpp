/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/12 16:01:51 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"

Sample::Sample(float const f) : pi(f), qd(42) {
	std::cout << "Constructor called" << std::endl;
	this->bar();
}

Sample::~Sample() {
	std::cout << "Destructor called" << std::endl;
}

void Sample::bar() const {
	std::cout << "pi" << this->pi << std::endl;
}
