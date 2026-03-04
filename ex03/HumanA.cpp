/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:23:16 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 10:45:28 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
    : _name(name), _weapon(weapon) {}

void HumanA::attack() const {
	std::cout << this->_name << " attacks with their "
	          << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA(){};
