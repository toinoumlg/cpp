/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/05 14:50:57 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "🤖 ClapTrap default contructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hp(10), ep(10), ad(0) {
	std::cout << "🤖 ClapTrap " << this->name << " created with " << this->hp
	          << " HP, " << this->ep << " EP and " << this->ad << " AD."
	          << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->hp == 0) {
		std::cout << "❌ ClapTrap " << this->name << " can't attack, "
		          << this->hp << " HP left (he is dead 🙏⚰️ )."
		          << std::endl;
		return;
	}

	if (this->ep > 0) {
		this->ep--;
		std::cout << "⚔️  ClapTrap " << this->name << " attacks " << target
		          << ", causing " << this->ad << " points of damage!"
		          << std::endl;
	} else
		std::cout << "❌ ClapTrap " << this->name << " can't attack, "
		          << this->ep << " EP left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hp > 0) {
		this->hp -= amount;
		if (this->hp < 0)
			this->hp = 0;
		std::cout << "🩸 ClapTrap " << this->name << " took " << amount
		          << " of damage, " << this->hp << " HP left!" << std::endl;
	} else
		std::cout << "❌ ClapTrap " << this->name << " has " << this->hp
		          << " HP left (he is dead 🙏⚰️ )." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hp == 0) {
		std::cout << "❌ ClapTrap " << this->name << " can't repare, "
		          << this->hp << " HP left (he is dead 🙏⚰️ )."
		          << std::endl;
		return;
	}
	if (this->ep > 0) {
		this->ep--;
		this->hp += amount;
		std::cout << "🔨 ClapTrap " << this->name << " is reparing " << amount
		          << " of HP, " << this->name << " now has " << this->hp
		          << " HP!" << std::endl;
	} else
		std::cout << "❌ ClapTrap " << this->name << " can't repare, "
		          << this->ep << " EP left." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "💣 ClapTrap " << this->name << " destroyed !" << std::endl;
}