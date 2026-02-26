/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:12:44 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/26 20:39:29 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_H
#define WEAPON_CLASS_H

#include <string>

class Weapon {
   public:
	Weapon();
	Weapon(std::string type);
	~Weapon();

	const std::string& getType() const;
	void setType(std::string type);

   private:
	std::string _type;
};

#endif