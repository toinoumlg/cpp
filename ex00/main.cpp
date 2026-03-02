/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/02 12:01:14 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main(void) {
	ClapTrap first("GOAT");
	first.beRepaired(10);
	first.attack("TARGET");
	first.attack("TARGET");
	first.attack("TARGET");
	first.attack("TARGET");
	first.attack("TARGET");
	first.attack("TARGET");
	first.attack("TARGET");
	first.attack("TARGET");
	first.attack("TARGET");
	first.attack("TARGET");
	first.attack("TARGET");
	first.attack("TARGET");
	first.beRepaired(10);
	first.takeDamage(5);
	first.takeDamage(15);
	first.takeDamage(15);
	first.takeDamage(15);
	return 0;
}