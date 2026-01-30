/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:39 by amalangu          #+#    #+#             */
/*   Updated: 2026/01/30 09:56:58 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"

#include <cstdlib>

#include "display.hpp"

PhoneBook::PhoneBook() : _created(0) {
	std::string input;

	std::cout << "Welcome to my Awesome PhoneBook !" << endl;

	while (1) {
		std::cout << "ADD, SEARCH, EXIT> ";
		getline(std::cin, input);
		if (std::cin.eof())
			throw "Stdcin got closed";
		if (!input.compare(0, 5, "EXIT"))
			return;
		else if (!input.compare(0, 4, "ADD"))
			this->_addContact();
		else if (!input.compare(0, 7, "SEARCH"))
			this->_search();
		else
			std::cout << "Wrong input !!" << endl;
	}
}

void PhoneBook::_addContact() {
	int i;

	this->_created++;
	if (this->_created > 8) {
		this->_created--;
		this->_oldest++;
		if (this->_oldest > 8)
			this->_oldest = 1;
		i = this->_oldest;
	} else
		i = this->_created;
	this->_contacts[i - 1].set(i);
}

int promtIndex(int i) {
	int j;
	std::string input;

	j = 1;
	std::cout << "Possible contact nbr: ";
	while (j < i)
		std::cout << j++ << ", ";
	std::cout << j << " > ";
	getline(std::cin, input);
	if (std::cin.eof())
		throw "Stdcin got closed";
	if (input.length() != 1 || input.at(0) - 48 < 1 || input.at(0) - 48 > i)
		return (promtIndex(i));
	return (input.at(0) - 48 - 1);
}

void PhoneBook::_search() const {
	int i = 0;

	displayHeader();
	if (!this->_created)
		return;
	while (i < this->_created)
		this->_contacts[i++].display();
	this->_contacts[promtIndex(this->_created)].displayFull();
}

PhoneBook::~PhoneBook() {}