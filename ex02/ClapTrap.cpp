/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 12:19:29 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

ClapTrap::ClapTrap() {
	cout << "🤖 ClapTrap default contructor called" << endl;
}

ClapTrap::ClapTrap(const string& name) : name(name), hp(10), ep(10), ad(0) {
	cout << "🤖 ClapTrap " << this->name << " created with " << this->hp
	     << " HP, " << this->ep << " EP and " << this->ad << " AD." << endl;
}

void ClapTrap::attack(const string& target) {
	if (this->hp == 0) {
		cout << "❌ ClapTrap " << this->name << " can't attack, " << this->hp
		     << " HP left (he is dead 🙏⚰️ )." << endl;
		return;
	}

	if (this->ep > 0) {
		this->ep--;
		cout << "⚔️  ClapTrap " << this->name << " attacks " << target
		     << ", causing " << this->ad << " points of damage!" << endl;
	} else
		cout << "❌ ClapTrap " << this->name << " can't attack, " << this->ep
		     << " EP left." << endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hp > 0) {
		this->hp -= amount;
		if (this->hp < 0)
			this->hp = 0;
		cout << "🩸 ClapTrap " << this->name << " took " << amount
		     << " of damage, " << this->hp << " HP left!" << endl;
	} else
		cout << "❌ ClapTrap " << this->name << " has " << this->hp
		     << " HP left (he is dead 🙏⚰️ )." << endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hp == 0) {
		cout << "❌ ClapTrap " << this->name << " can't repare, " << this->hp
		     << " HP left (he is dead 🙏⚰️ )." << endl;
		return;
	}
	if (this->ep > 0) {
		this->ep--;
		this->hp += amount;
		cout << "🔨 ClapTrap " << this->name << " is reparing " << amount
		     << " of HP, " << this->name << " now has " << this->hp << " HP!"
		     << endl;
	} else
		cout << "❌ ClapTrap " << this->name << " can't repare, " << this->ep
		     << " EP left." << endl;
}

ClapTrap::~ClapTrap() {
	cout << "💣 ClapTrap " << this->name << " destroyed !" << endl;
}