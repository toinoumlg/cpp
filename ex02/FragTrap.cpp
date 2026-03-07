/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/05 14:49:46 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) {
	this->name = name;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "🤖 FragTrap " << this->name << " created with " << this->hp
	          << " HP, " << this->ep << " EP and " << this->ad << " AD."
	          << std::endl;
}

void FragTrap::highFivesGuys() const {
	if (this->hp > 0)
		std::cout << "🤚 FragTrap " << this->name
		          << " wants to do a High Five!" << std::endl;
	else
		std::cout << "❌ FragTrap " << this->name << " can't guard the gate, "
		          << this->hp << " HP left (he is dead 🙏⚰️ )."
		          << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "💣 FragTrap " << this->name << " destroyed !" << std::endl;
}