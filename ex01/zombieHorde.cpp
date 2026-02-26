/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:59:27 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/26 20:53:28 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.class.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* zombies = new Zombie[N];
	if (N <= 0)
		return NULL;
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return zombies;
}