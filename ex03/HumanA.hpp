/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:19:00 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 10:45:28 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_H
#define HUMANA_CLASS_H

#include "Weapon.hpp"

class HumanA {
   public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
	void attack() const;

   private:
	const std::string& _name;
	Weapon& _weapon;
};

#endif