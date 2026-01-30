/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:25 by amalangu          #+#    #+#             */
/*   Updated: 2026/01/30 09:56:13 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"

#include "display.hpp"

Contact::Contact() : _index(0) {}

void wrongValue(void) { std::cout << "Wrong input" << std::endl; }

std::string getValue(const std::string promt) {
	std::string tmp;

	std::cout << promt;
	std::getline(std::cin, tmp);
	if (std::cin.eof())
		throw "Stdcin got closed";
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
	std::cout << "|";
	displayNbr(this->_index);
	std::cout << "|";
	display10(this->_firstname);
	std::cout << "|";
	display10(this->_lastname);
	std::cout << "|";
	display10(this->_nickname);
	std::cout << "|" << std::endl;
}

void Contact::displayFull() const {
	std::cout << "Index: " << this->_index << std::endl
	          << "First Name: " << this->_firstname << std::endl
	          << "Last Name: " << this->_lastname << std::endl
	          << "Nick Name: " << this->_nickname << std::endl
	          << "Phone Number: " << this->_phonenumber << std::endl
	          << "Darkest Secret: " << this->_darkest << std::endl;
}

Contact::~Contact() {}