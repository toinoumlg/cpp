/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:15:08 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/04 08:38:40 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"

Weapon::Weapon() {}
Weapon::Weapon(string type) : _type(type) {}

const string& Weapon::getType() const { return this->_type; }

void Weapon::setType(string type) { this->_type = type; }

Weapon::~Weapon() {}