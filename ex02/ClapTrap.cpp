/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/09 15:38:43 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hp(10), ep(10), ad(0) {
	std::cout << "🤖 ClapTrap default contructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hp(10), ep(10), ad(0) {
	std::cout << "🤖 ClapTrap " << name << " created with " << hp << " HP, "
	          << ep << " EP and " << ad << " AD." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hp(other.hp), ep(other.ep), ad(other.ad) {
	std::cout << "🤖 ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "🤖 ClapTrap assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	name = other.name;
	ep = other.ep;
	ad = other.ad;
	hp = other.hp;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (hp == 0) {
		std::cout << "❌ ClapTrap " << name << " can't attack, " << hp
		          << " HP left (he is dead 🙏⚰️ )." << std::endl;
		return;
	}

	if (ep > 0) {
		ep--;
		std::cout << "⚔️  ClapTrap " << name << " attacks " << target
		          << ", causing " << ad << " points of damage!" << std::endl;
	} else
		std::cout << "❌ ClapTrap " << name << " can't attack, " << ep
		          << " EP left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hp > 0) {
		hp -= amount;
		if (hp < 0)
			hp = 0;
		std::cout << "🩸 ClapTrap " << name << " took " << amount
		          << " of damage, " << hp << " HP left!" << std::endl;
	} else
		std::cout << "❌ ClapTrap " << name << " has " << hp
		          << " HP left (he is dead 🙏⚰️ )." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hp == 0) {
		std::cout << "❌ ClapTrap " << name << " can't repare, " << hp
		          << " HP left (he is dead 🙏⚰️ )." << std::endl;
		return;
	}
	if (ep > 0) {
		ep--;
		hp += amount;
		std::cout << "🔨 ClapTrap " << name << " is reparing " << amount
		          << " of HP, " << name << " now has " << hp << " HP!"
		          << std::endl;
	} else
		std::cout << "❌ ClapTrap " << name << " can't repare, " << ep
		          << " EP left." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "💣 ClapTrap " << name << " destroyed !" << std::endl;
}