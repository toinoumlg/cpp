/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/12 15:00:43 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"

Sample::Sample()
{
	std::cout << "Constructor called" << std::endl;
	this->foo = 42;
	std::cout << "this foo == " << this->foo << std::endl;
	this->bar();
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
}

void Sample::bar()
{
	std::cout << "bar called" << std::endl;
}

