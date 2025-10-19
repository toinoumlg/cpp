/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 18:36:14 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"

Sample::Sample() : _foo(0) {}
Sample::Sample(int const n) : _foo(n) {}
Sample::Sample(Sample const &source) { *this = source; }

Sample &Sample::operator=(Sample const &rhs)
{
    if (this != &rhs)
        this->_foo = rhs.getFoo();
    return *this;
}
int Sample::getFoo() const { return this->_foo; };

Sample::~Sample() {}

std::ostream &operator<<(std::ostream &o, Sample const &i)
{
    o << i.getFoo();
    return o;
}