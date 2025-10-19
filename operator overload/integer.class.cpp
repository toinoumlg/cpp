/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 18:05:13 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "integer.class.hpp"

Integer::Integer(int const n) : _n(n)
{
    std::cout << "Constructor called with value " << n << std::endl;
}

int Integer::getValue() const { return this->_n; }

Integer &Integer::operator=(Integer const &rhs)
{
    std::cout << "Assignation operator called from " << this->_n;
    std::cout << " to " << rhs.getValue() << std::endl;

    this->_n = rhs.getValue();
    return *this;
};

Integer Integer::operator+(Integer const &rhs) const
{
    std::cout << "Addition operator called with " << this->_n << " and "
              << rhs.getValue() << std::endl;
    return Integer(this->_n + rhs.getValue());
};

std::ostream &operator<<(std::ostream &o, Integer const &rhs)
{
    o << rhs.getValue();
    return o;
}

Integer::~Integer() { std::cout << "Destructor called" << std::endl; }