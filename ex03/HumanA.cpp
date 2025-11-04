/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:23:16 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/04 08:44:31 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanA.class.hpp"

using namespace std;

HumanA::HumanA(string name, Weapon *weapon) : _name(name), _weapon(weapon) {}

void HumanA::attack() const {
	cout << this->_name << " attacks with their " << this->_weapon->getType()
	     << endl;
}

HumanA::~HumanA() {};
