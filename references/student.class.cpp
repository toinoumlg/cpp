/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   student.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 06:11:38 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "student.class.hpp"

Student::Student(std::string const &login) : _login(login) {}

std::string &Student::getLoginRef() { return this->_login; }

std::string const &Student::getLoginRefConst() const { return this->_login; }

std::string *Student::getLoginPtr() { return &this->_login; }

std::string const *Student::getLoginPtrConst() const { return &this->_login; }

Student::~Student()
{
    std::cout << "Student :" << this->_login << " died" << std::endl;
}