/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:51:09 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/26 20:56:07 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.class.hpp"

Harl::Harl() {}

void Harl::complain(std::string level) const {
	if (!level.compare("DEBUG"))
		this->debug();
	if (!level.compare("INFO"))
		this->info();
	if (!level.compare("WARNING"))
		this->warning();
	if (!level.compare("ERROR"))
		this->error();
}

void Harl::debug() const {
	std::cout << "I love having extra bacon for my "
	          << "7XL-double-cheese-triple-"
	          << "pickle-special-ketchup burger.I really do !" << std::endl;
}

void Harl::info() const {
	std::cout << "I cannot believe adding extra bacon costs more money. "
	          << "You didn't put enough bacon in my burger! "
	          << "If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning() const {
	std::cout << "I think I deserve to have some extra bacon for free. "
	          << "I've been coming for years,whereas you started "
	          << "working here just last month." << std::endl;
}
void Harl::error() const {
	std::cout << "This is unacceptable! I want to speak to the manager now."
	          << std::endl;
}

Harl::~Harl() {}
