/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 12:27:49 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"

using namespace std;

int main(void) {
	ClapTrap first("GOAT");
	ScavTrap second("NOT GOAT");
	FragTrap third("HIGH");
	second.takeDamage(50);
	second.guardGate();
	second.takeDamage(25);
	second.takeDamage(25);
	second.takeDamage(25);
	second.beRepaired(500);
	second.takeDamage(25);
	second.guardGate();
	third.highFivesGuys();
	third.takeDamage(10);
	third.takeDamage(10);
	third.takeDamage(10);
	third.takeDamage(10);
	third.takeDamage(100);
	third.takeDamage(10);
	third.beRepaired(10);
	first.beRepaired(10);
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.beRepaired(10);
	first.takeDamage(5);
	first.takeDamage(15);
	first.takeDamage(15);
	first.takeDamage(15);
	return 0;
}