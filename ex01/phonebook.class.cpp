/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:39 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/02 11:49:47 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"

#include <cstdlib>

#include "display.hpp"

PhoneBook::PhoneBook() : _created(0), _index(0) {
	std::string input;

	std::cout << "Welcome to my Awesome PhoneBook !" << std::endl;

	while (1) {
		std::cout << "ADD, SEARCH, EXIT> ";
		getline(std::cin, input);
		if (std::cin.eof())
			throw "Standard input closed ending...";
		if (!input.compare(0, 5, "EXIT"))
			return;
		else if (!input.compare(0, 4, "ADD"))
			this->_addContact();
		else if (!input.compare(0, 7, "SEARCH"))
			this->_search();
		else
			std::cout << "Wrong input !!" << std::endl;
	}
}

void PhoneBook::_addContact() {
	if (this->_index >= 8)
		this->_index = 0;
	this->_contacts[this->_index].set(this->_index);
	if (this->_created < 8)
		this->_created++;
	this->_index++;
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
		throw "Standard input closed ending...";
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