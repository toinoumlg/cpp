/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:59:31 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 10:44:02 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP

#include <string>

class Zombie {
   public:
	Zombie();
	~Zombie();

	void annonce();
	void setName(std::string name);

   private:
	std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif