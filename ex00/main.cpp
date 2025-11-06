/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 11:40:35 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

using namespace std;

int main(void) {
	ClapTrap first("GOAT");
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