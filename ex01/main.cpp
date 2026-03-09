/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/09 15:35:00 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap first("GOAT");
	ScavTrap second("Not Goat");
	ScavTrap third;
	third = second;
	first.beRepaired(10);
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	second.attack("TARGET 2");
	second.attack("TARGET 2");
	second.attack("TARGET 2");
	second.guardGate();
	second.guardGate();
	second.attack("TARGET 2");
	second.attack("TARGET 2");
	second.attack("TARGET 2");
	second.attack("TARGET 2");
	first.attack("TARGET 1");
	first.attack("TARGET 1");
	first.beRepaired(10);
	first.takeDamage(5);
	first.takeDamage(15);
	first.takeDamage(15);
	first.takeDamage(15);
	return 0;
}