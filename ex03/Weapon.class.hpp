/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:12:44 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/04 08:39:54 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_H
#define WEAPON_CLASS_H

#include <string>



using namespace std;

class Weapon {
   public:
	Weapon();
	Weapon(string type);
	~Weapon();

	const string& getType() const;
	void setType(string type);

   private:
	string _type;
};

#endif