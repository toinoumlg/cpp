/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:13 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 12:19:29 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_H
#define CLAPTRAP_CLASS_H

#include <iostream>
using namespace std;

class ClapTrap {
   public:
	ClapTrap();
	ClapTrap(const string& name);
	~ClapTrap();

	void attack(const string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

   protected:
	string name;
	int hp;
	int ep;
	int ad;
};

#endif