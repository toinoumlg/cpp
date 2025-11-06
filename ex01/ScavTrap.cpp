/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 12:19:29 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

ScavTrap::ScavTrap(const string& name) {
	this->name = name;
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	cout << "🤖 ScavTrap " << this->name << " created with " << this->hp
	     << " HP, " << this->ep << " EP and " << this->ad << " AD." << endl;
}

void ScavTrap::attack(const string& target) {
	if (this->hp == 0) {
		cout << "❌ ScavTrap " << this->name << " can't attack, " << this->hp
		     << " HP left (he is dead 🙏⚰️ )." << endl;
		return;
	}

	if (this->ep > 0) {
		this->ep--;
		cout << "⚔️  ScavTrap " << this->name << " attacks " << target
		     << ", causing " << this->ad << " points of damage!" << endl;
	} else
		cout << "❌ ScavTrap " << this->name << " can't attack, " << this->ep
		     << " EP left." << endl;
}

void ScavTrap::guardGate() const {
	if (this->hp > 0)
		cout << "🛡️  ScavTrap " << this->name << " is guarding the gate!"
		     << endl;
	else
		cout << "❌ ScavTrap " << this->name << " can't guard the gate, "
		     << this->hp << " HP left (he is dead 🙏⚰️ )." << endl;
}

ScavTrap::~ScavTrap() {
	cout << "💣 ScavTrap " << this->name << " destroyed !" << endl;
}