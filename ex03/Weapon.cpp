/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:15:08 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/26 20:20:23 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string type) : _type(type) {}

const std::string& Weapon::getType() const { return this->_type; }

void Weapon::setType(std::string type) { this->_type = type; }

Weapon::~Weapon() {}