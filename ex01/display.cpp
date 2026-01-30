/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:32:47 by amalangu          #+#    #+#             */
/*   Updated: 2026/01/30 09:49:54 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.hpp"

#include <cstdlib>

void displayNbr(int nbr) { std::cout << std::setw(10) << std::left << nbr; }

void display10(std::string tmp) {
	if (tmp.length() > 10) {
		tmp.replace(9, 1, ".");
		tmp.erase(10);
	}
	std::cout << std::setw(10) << std::left << tmp;
}

void displayHeader(void) {
	std::cout << "|";
	display10("Index");
	std::cout << "|";
	display10("First name");
	std::cout << "|";
	display10("Last name");
	std::cout << "|";
	display10("Nick name");
	std::cout << "|" << endl;
}
