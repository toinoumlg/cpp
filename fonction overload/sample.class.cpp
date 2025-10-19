/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 06:59:07 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"

#include <iostream>

Sample::Sample() {}

void Sample::bar(char const c) const
{
    std::cout << "char overload" << std::endl;
}

void Sample::bar(int const n) const
{
    std::cout << "int overload" << std::endl;
}

void Sample::bar(float const z) const
{
    std::cout << "float overload" << std::endl;
}

void Sample::bar(Sample const &i) const
{
    std::cout << "Sample overload" << std::endl;
}

Sample::~Sample() {}