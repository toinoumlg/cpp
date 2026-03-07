/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/05 16:42:23 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "🤖 ClapTrap default contructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hp(10), _ep(10), _ad(10) {
	std::cout << "🤖 ClapTrap " << this->_name << " created with "
	          << this->_hp << " HP, " << this->_ep << " EP and " << this->_ad
	          << " AD." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hp(other._hp), _ep(other._ep), _ad(other._ad) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_ep = other._ep;
		this->_ad = other._ad;
		this->_hp = other._hp;
	}
	std::cout << "ClapTrap assignment operator called" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hp == 0) {
		std::cout << "❌ ClapTrap " << this->_name << " can't attack, "
		          << this->_hp << " HP left (he is dead 🙏⚰️ )."
		          << std::endl;
		return;
	}

	if (this->_ep > 0) {
		this->_ep--;
		std::cout << "⚔️  ClapTrap " << this->_name << " attacks " << target
		          << ", causing " << this->_ad << " points of damage!"
		          << std::endl;
	} else
		std::cout << "❌ ClapTrap " << this->_name << " can't attack, "
		          << this->_ep << " EP left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp > 0) {
		this->_hp -= amount;
		if (this->_hp < 0)
			this->_hp = 0;
		std::cout << "🩸 ClapTrap " << this->_name << " took " << amount
		          << " of damage, " << this->_hp << " HP left!" << std::endl;
	} else
		std::cout << "❌ ClapTrap " << this->_name << " has " << this->_hp
		          << " HP left (he is dead 🙏⚰️ )." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hp == 0) {
		std::cout << "❌ ClapTrap " << this->_name << " can't repare, "
		          << this->_hp << " HP left (he is dead 🙏⚰️ )."
		          << std::endl;
		return;
	}
	if (this->_ep > 0) {
		this->_ep--;
		this->_hp += amount;
		std::cout << "🔨 ClapTrap " << this->_name << " is reparing " << amount
		          << " of HP, " << this->_name << " now has " << this->_hp
		          << " HP!" << std::endl;
	} else
		std::cout << "❌ ClapTrap " << this->_name << " can't repare, "
		          << this->_ep << " EP left." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "💣 ClapTrap " << this->_name << " destroyed !" << std::endl;
}