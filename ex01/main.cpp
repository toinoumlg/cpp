/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/09 15:23:17 by amalangu         ###   ########.fr       */
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
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	second.attack("NO RATIO");
	second.attack("NO RATIO");
	second.attack("NO RATIO");
	second.guardGate();
	second.guardGate();
	second.attack("NO RATIO");
	second.attack("NO RATIO");
	second.attack("NO RATIO");
	second.attack("NO RATIO");
	first.attack("RATIO");
	first.attack("RATIO");
	first.beRepaired(10);
	first.takeDamage(5);
	first.takeDamage(15);
	first.takeDamage(15);
	first.takeDamage(15);
	return 0;
}