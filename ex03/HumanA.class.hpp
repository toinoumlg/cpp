/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:19:00 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/04 08:44:21 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_H
#define HUMANA_CLASS_H

#include "Weapon.class.hpp"

class HumanA {
   public:
	HumanA(string name, Weapon *weapon);
	~HumanA();
	void attack() const;

   private:
	string _name;
	Weapon *_weapon;
};

#endif