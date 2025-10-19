/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   student.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 05:23:46 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "student.class.hpp"

Student::Student() : _login("ldefault")
{
    std::cout << "Student :" << this->_login << " is born" << std::endl;
}

Student::~Student()
{
    std::cout << "Student :" << this->_login << " died" << std::endl;
}