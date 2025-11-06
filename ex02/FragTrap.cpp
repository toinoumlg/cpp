/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 12:25:32 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"

FragTrap::FragTrap(const string& name) {
	this->name = name;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	cout << "🤖 FragTrap " << this->name << " created with " << this->hp
	     << " HP, " << this->ep << " EP and " << this->ad << " AD." << endl;
}

void FragTrap::highFivesGuys() const {
	if (this->hp > 0)
		cout << "🤚 FragTrap " << this->name << " wants to do a High Five!"
		     << endl;
	else
		cout << "❌ FragTrap " << this->name << " can't guard the gate, "
		     << this->hp << " HP left (he is dead 🙏⚰️ )." << endl;
}

FragTrap::~FragTrap() {
	cout << "💣 FragTrap " << this->name << " destroyed !" << endl;
}