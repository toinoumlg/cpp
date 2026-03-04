/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:59:31 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 10:43:33 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP

#include <string>

class Zombie {
   public:
	Zombie();
	~Zombie();

	void announce();
	void setName(std::string name);

   private:
	std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif