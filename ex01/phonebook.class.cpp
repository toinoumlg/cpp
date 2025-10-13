/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:39 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/13 22:10:27 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.hpp"
#include "phonebook.class.hpp"

PhoneBook::PhoneBook() {
	std::cout << "Welcome to my Awesome PhoneBook !" << std::endl;
	this->_created = 0;
	this->_prompt();
}

void PhoneBook::_prompt() {
	std::string tmp;
	while (1) {
		std::cout << "ADD, SEARCH, EXIT> ";
		std::cin >> tmp;
		if (!tmp.compare("ADD"))
			this->_addContact();
		else if (!tmp.compare("SEARCH"))
			this->_search();
		else if (!tmp.compare("EXIT"))
			return ;
		else
			this->_wrongInput();
	}
}

int PhoneBook::_getOldest() const {
	int i, oldest;
	i = 0;
	oldest = 0;
	while (i < 8) {
		if (difftime(this->_contacts[i].getCreation(),
				this->_contacts[oldest].getCreation()) < 0)
			oldest = i++;
		else
			i++;
	}
	return (oldest + 1);
}

void PhoneBook::_addContact() {
	int	i;

	this->_created++;
	if (this->_created == 9) {
		i = this->_getOldest();
		this->_created--;
	} else
		i = this->_created;
	this->_contacts[i - 1].set(i);
}

void PhoneBook::_displayContacts() const {
	int i = 0;
	while (i < this->_created)
		this->_contacts[i++].display();
}

void PhoneBook::_search() const {
	displayHeader();
	int i;
	this->_displayContacts();
	i = display_possible_nbr(this->_created);
	if (i >= 0)
		this->_contacts[i].displayFull();
}

void PhoneBook::_wrongInput() const {
	std::cout << "Wrong input !!" << std::endl;
}

PhoneBook::~PhoneBook() {
}