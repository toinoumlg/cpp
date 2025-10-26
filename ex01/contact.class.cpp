/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:25 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/26 14:13:09 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"

#include "display.hpp"

Contact::Contact() : _index(0) {}

void wrongValue(void) { cout << "Wrong input" << endl; }

string getValue(const string promt) {
	string tmp;

	cout << promt;
	getline(cin, tmp);
	if (!tmp.length())
		return (wrongValue(), getValue(promt));
	return (tmp);
}

void Contact::set(int i) {
	this->_index = i;
	this->_firstname = getValue("First Name: ");
	this->_lastname = getValue("Last Name: ");
	this->_nickname = getValue("Nickname: ");
	this->_phonenumber = getValue("Phonenumber: ");
	this->_darkest = getValue("Darkest secret: ");
}

void Contact::display() const {
	cout << "|";
	displayNbr(this->_index);
	cout << "|";
	display10(this->_firstname);
	cout << "|";
	display10(this->_lastname);
	cout << "|";
	display10(this->_nickname);
	cout << "|" << endl;
}

void Contact::displayFull() const {
	cout << "Index: " << this->_index << endl
	     << "First Name: " << this->_firstname << endl
	     << "Last Name: " << this->_lastname << endl
	     << "Nick Name: " << this->_nickname << endl
	     << "Phone Number: " << this->_phonenumber << endl
	     << "Darkest Secret: " << this->_darkest << endl;
}

Contact::~Contact() {}