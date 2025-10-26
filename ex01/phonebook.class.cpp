/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:39 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/26 14:36:37 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"

#include <cstdlib>

#include "display.hpp"

PhoneBook::PhoneBook() : _created(0) {
	string input;

	cout << "Welcome to my Awesome PhoneBook !" << endl;
	while (1) {
		cout << "ADD, SEARCH, EXIT> ";
		getline(cin, input);
		if (!input.compare(0, 5, "EXIT"))
			return;
		else if (!input.compare(0, 4, "ADD"))
			this->_addContact();
		else if (!input.compare(0, 7, "SEARCH"))
			this->_search();
		else
			cout << "Wrong input !!" << endl;
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
	string input;

	j = 1;
	cout << "Possible contact nbr: ";
	while (j < i)
		cout << j++ << ", ";
	cout << j << " > ";
	getline(cin, input);
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