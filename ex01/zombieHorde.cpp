/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:59:27 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 10:45:28 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;
	Zombie* zombies = new (std::nothrow) Zombie[N];
	if (!zombies)
		return NULL;
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return zombies;
}