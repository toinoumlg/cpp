/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:31:59 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/04 08:44:01 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanB.class.hpp"

using namespace std;

HumanB::HumanB(string name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon* weapon) { this->_weapon = weapon; }

void HumanB::attack() const {
	if (this->_weapon)
		cout << this->_name << " attacks with their "
		     << this->_weapon->getType() << endl;
}

HumanB::~HumanB() {};