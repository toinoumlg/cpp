/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:13 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 12:14:50 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_H
#define SCAVTRAP_CLASS_H

#include <iostream>

#include "ClapTrap.class.hpp"
using namespace std;

class ScavTrap : public ClapTrap {
   public:
	ScavTrap(const string& name);
	~ScavTrap();

	void attack(const string& target);
	void guardGate() const;
};

#endif