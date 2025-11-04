/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:59:27 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/27 13:51:20 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.class.hpp"

Zombie::Zombie() {}

void Zombie::annonce() {
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void Zombie::setName(string name) { this->_name = name; }

Zombie::~Zombie() { cout << this->_name << ": Died !" << endl; }