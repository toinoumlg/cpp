/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/05 14:21:38 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) {
	this->name = name;
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	std::cout << "🤖 ScavTrap " << this->name << " created with " << this->hp
	          << " HP, " << this->ep << " EP and " << this->ad << " AD."
	          << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->hp == 0) {
		std::cout << "❌ ScavTrap " << this->name << " can't attack, "
		          << this->hp << " HP left (he is dead 🙏⚰️ )."
		          << std::endl;
		return;
	}

	if (this->ep > 0) {
		this->ep--;
		std::cout << "⚔️  ScavTrap " << this->name << " attacks " << target
		          << ", causing " << this->ad << " points of damage!"
		          << std::endl;
	} else
		std::cout << "❌ ScavTrap " << this->name << " can't attack, "
		          << this->ep << " EP left." << std::endl;
}

void ScavTrap::guardGate() const {
	if (this->hp > 0)
		std::cout << "🛡️  ScavTrap " << this->name
		          << " is guarding the gate!" << std::endl;
	else
		std::cout << "❌ ScavTrap " << this->name << " can't guard the gate, "
		          << this->hp << " HP left (he is dead 🙏⚰️ )."
		          << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "💣 ScavTrap " << this->name << " destroyed !" << std::endl;
}