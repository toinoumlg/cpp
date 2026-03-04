/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:51:09 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 14:45:35 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>
#include <tuple>

Harl::Harl() {}

void Harl::complain(std::string level) {
	void (Harl::*comp[4])(void) = {
	    &Harl::debug,
	    &Harl::info,
	    &Harl::warning,
	    &Harl::error,
	};

	std::string lvls[4] = {
	    "DEBUG",
	    "INFO",
	    "WARNING",
	    "ERROR",
	};

	for (int i = 0; i < 4; i++) {
		if (level == lvls[i])
			(this->*comp[i])();
	};
}

void Harl::debug() {
	std::cout << "I love having extra bacon for my "
	          << "7XL-double-cheese-triple-"
	          << "pickle-special-ketchup burger.I really do !" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. "
	          << "You didn't put enough bacon in my burger! "
	          << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. "
	          << "I've been coming for years,whereas you started "
	          << "working here just last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now."
	          << std::endl;
}

Harl::~Harl() {}
