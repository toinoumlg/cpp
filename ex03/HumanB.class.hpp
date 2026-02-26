/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:32:17 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/26 20:47:17 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_H
#define HUMANB_CLASS_H

#include "Weapon.class.hpp"

class HumanB {
   public:
	HumanB(std::string name);
	~HumanB();
	void attack() const;
	void setWeapon(Weapon& weapon);

   private:
	std::string _name;
	Weapon* _weapon;
};

#endif