/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/12 14:29:37 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"
#include <iostream>

Sample::Sample()
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}