/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:59:31 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/27 13:51:24 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP

#include <string>

using namespace std;

class Zombie {
   public:
	Zombie();
	~Zombie();

	void annonce();
	void setName(string name);

   private:
	string _name;
};

Zombie* zombieHorde(int N, string name);

#endif