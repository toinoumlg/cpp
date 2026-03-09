/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/09 15:22:00 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "🤖 ClapTrap default contructor called !" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) {
	this->name = name;
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	std::cout << "🤖 ScavTrap " << name << " created with " << hp << " HP, "
	          << ep << " EP and " << ad << " AD." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "🤖 ScavTrap copy operator called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this == &other)
		return *this;
	name = other.name;
	ep = other.ep;
	ad = other.ad;
	hp = other.hp;
	std::cout << "ClapTrap assignment operator called" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (hp == 0) {
		std::cout << "❌ ScavTrap " << name << " can't attack, " << hp
		          << " HP left (he is dead 🙏⚰️ )." << std::endl;
		return;
	}

	if (ep > 0) {
		ep--;
		std::cout << "⚔️  ScavTrap " << name << " attacks " << target
		          << ", causing " << ad << " points of damage!" << std::endl;
	} else
		std::cout << "❌ ScavTrap " << name << " can't attack, " << ep
		          << " EP left." << std::endl;
}

void ScavTrap::guardGate() const {
	if (hp > 0)
		std::cout << "🛡️  ScavTrap " << name << " is guarding the gate!"
		          << std::endl;
	else
		std::cout << "❌ ScavTrap " << name << " can't guard the gate, " << hp
		          << " HP left (he is dead 🙏⚰️ )." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "💣 ScavTrap " << name << " destroyed !" << std::endl;
}