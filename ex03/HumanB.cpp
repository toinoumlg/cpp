/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:31:59 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 10:45:28 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) { _weapon = &weapon; }

void HumanB::attack() const {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their "
		          << this->_weapon->getType() << std::endl;
}

HumanB::~HumanB(){};