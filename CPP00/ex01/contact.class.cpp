/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:25 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/13 22:33:52 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"
#include "display.hpp"

Contact::Contact() : _index(0) {
}

std::string getValue(const std::string promt) {
	std::string tmp;
	std::cout << promt;
	std::cin >> tmp;
	return (tmp);
}

void Contact::set(int i) {
	this->_firstname = getValue("First Name: ");
	this->_lastname = getValue("Last Name: ");
	this->_nickname = getValue("Nickname: ");
	this->_phonenumber = getValue("Phonenumber: ");
	this->_darkest = getValue("Darkest secret: ");
	this->_index = i;
	std::time(&this->_creation);
}

void Contact::display() const {
	std::cout << "|";
	display_nbr(this->_index);
	std::cout << "|";
	display_10(this->_firstname);
	std::cout << "|";
	display_10(this->_lastname);
	std::cout << "|";
	display_10(this->_nickname);
	std::cout << "|";
	std::cout << std::endl;
}

void Contact::displayFull() const {
	std::cout << "Index: " << this->_index << std::endl;
	std::cout << "First Name: " << this->_firstname << std::endl;
	std::cout << "Last Name: " << this->_lastname << std::endl;
	std::cout << "Nick Name: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phonenumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkest << std::endl;
}

time_t Contact::getCreation() const {
	return (this->_creation);
}

Contact::~Contact() {
}