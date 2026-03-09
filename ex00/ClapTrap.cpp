/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/09 15:01:36 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hp(10), _ep(10), _ad(0) {
	std::cout << "🤖 ClapTrap default contructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hp(10), _ep(10), _ad(0) {
	std::cout << "🤖 ClapTrap " << _name << " created with " << _hp << " HP, "
	          << _ep << " EP and " << _ad << " AD." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hp(other._hp), _ep(other._ep), _ad(other._ad) {
	std::cout << "🤖 ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "🤖 ClapTrap assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	_name = other._name;
	_ep = other._ep;
	_ad = other._ad;
	_hp = other._hp;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (_hp == 0) {
		std::cout << "❌ ClapTrap " << _name << " can't attack, " << _hp
		          << " HP left (he is dead 🙏⚰️ )." << std::endl;
		return;
	}

	if (_ep > 0) {
		_ep--;
		std::cout << "⚔️  ClapTrap " << _name << " attacks " << target
		          << ", causing " << _ad << " points of damage!" << std::endl;
	} else
		std::cout << "❌ ClapTrap " << _name << " can't attack, " << _ep
		          << " EP left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hp > 0) {
		_hp -= amount;
		if (_hp < 0)
			_hp = 0;
		std::cout << "🩸 ClapTrap " << _name << " took " << amount
		          << " of damage, " << _hp << " HP left!" << std::endl;
	} else
		std::cout << "❌ ClapTrap " << _name << " has " << _hp
		          << " HP left (he is dead 🙏⚰️ )." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hp == 0) {
		std::cout << "❌ ClapTrap " << _name << " can't repare, " << _hp
		          << " HP left (he is dead 🙏⚰️ )." << std::endl;
		return;
	}
	if (_ep > 0) {
		_ep--;
		_hp += amount;
		std::cout << "🔨 ClapTrap " << _name << " is reparing " << amount
		          << " of HP, " << _name << " now has " << _hp << " HP!"
		          << std::endl;
	} else
		std::cout << "❌ ClapTrap " << _name << " can't repare, " << _ep
		          << " EP left." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "💣 ClapTrap " << _name << " destroyed !" << std::endl;
}