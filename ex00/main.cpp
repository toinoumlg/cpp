/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/05 16:29:49 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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