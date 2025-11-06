/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 12:11:48 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

ClapTrap::ClapTrap() {
	cout << "🤖 ClapTrap default contructor called" << endl;
}

ClapTrap::ClapTrap(const string& name) : _name(name), _hp(10), _ep(10), _ad(0) {
	cout << "🤖 ClapTrap " << this->_name << " created with " << this->_hp
	     << " HP, " << this->_ep << " EP and " << this->_ad << " AD." << endl;
}

void ClapTrap::attack(const string& target) {
	if (this->_hp == 0) {
		cout << "❌ ClapTrap " << this->_name << " can't attack, " << this->_hp
		     << " HP left (he is dead 🙏⚰️ )." << endl;
		return;
	}

	if (this->_ep > 0) {
		this->_ep--;
		cout << "⚔️  ClapTrap " << this->_name << " attacks " << target
		     << ", causing " << this->_ad << " points of damage!" << endl;
	} else
		cout << "❌ ClapTrap " << this->_name << " can't attack, " << this->_ep
		     << " EP left." << endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp > 0) {
		this->_hp -= amount;
		if (this->_hp < 0)
			this->_hp = 0;
		cout << "🩸 ClapTrap " << this->_name << " took " << amount
		     << " of damage, " << this->_hp << " HP left!" << endl;
	} else
		cout << "❌ ClapTrap " << this->_name << " has " << this->_hp
		     << " HP left (he is dead 🙏⚰️ )." << endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hp == 0) {
		cout << "❌ ClapTrap " << this->_name << " can't repare, " << this->_hp
		     << " HP left (he is dead 🙏⚰️ )." << endl;
		return;
	}
	if (this->_ep > 0) {
		this->_ep--;
		this->_hp += amount;
		cout << "🔨 ClapTrap " << this->_name << " is reparing " << amount
		     << " of HP, " << this->_name << " now has " << this->_hp << " HP!"
		     << endl;
	} else
		cout << "❌ ClapTrap " << this->_name << " can't repare, " << this->_ep
		     << " EP left." << endl;
}

ClapTrap::~ClapTrap() {
	cout << "💣 ClapTrap " << this->_name << " destroyed !" << endl;
}