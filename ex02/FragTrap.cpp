/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:10 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/09 15:19:42 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "🤖 FragTrap default contructor called !" << std::endl;
	hp = 100;
	ep = 100;
	ad = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap() {
	this->name = name;
	hp = 100;
	ep = 100;
	ad = 30;
	std::cout << "🤖 FragTrap " << this->name << " created with " << hp
	          << " HP, " << ep << " EP and " << ad << " AD." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "🤖 FragTrap copy operator called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "🤖 ClapTrap assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	name = other.name;
	ep = other.ep;
	ad = other.ad;
	hp = other.hp;
	return *this;
}

void FragTrap::highFivesGuys() const {
	if (hp > 0)
		std::cout << "🤚 FragTrap " << name << " wants to do a High Five!"
		          << std::endl;
	else
		std::cout << "❌ FragTrap " << name << " can't do a high five, " << hp
		          << " HP left (he is dead 🙏⚰️ )." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "💣 FragTrap " << name << " destroyed !" << std::endl;
}