/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:39 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/26 13:39:34 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"

#include <cstdlib>

#include "display.hpp"

PhoneBook::PhoneBook() : _created(0) {
	cout << "Welcome to my Awesome PhoneBook !" << endl;
	this->_prompt();
}

void PhoneBook::_prompt() {
	string tmp;

	while (1) {
		cout << "ADD, SEARCH, EXIT> ";
		getline(cin, tmp);
		if (!tmp.compare(0, 5, "EXIT"))
			return;
		else if (!tmp.compare(0, 4, "ADD"))
			this->_addContact();
		else if (!tmp.compare(0, 7, "SEARCH"))
			this->_search();
		else
			this->_wrongInput();
	}
}

void PhoneBook::_addContact() {
	this->_created++;
	if (this->_created > 8)
		this->_created = 1;
	this->_contacts[this->_created - 1].set(this->_created);
}

void PhoneBook::_displayContacts() const {
	int i = 0;

	while (i < this->_created)
		this->_contacts[i++].display();
}

void PhoneBook::_search() const {
	int i;

	displayHeader();
	this->_displayContacts();
	i = promt_possible_nbr(this->_created);
	if (i >= 0)
		this->_contacts[i].displayFull();
}

void PhoneBook::_wrongInput() const { cout << "Wrong input !!" << endl; }

PhoneBook::~PhoneBook() {}