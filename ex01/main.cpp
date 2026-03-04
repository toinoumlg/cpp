/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:07:30 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 10:48:19 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie* horde = zombieHorde(50, "Zombie");
	for (int i = 0; i < 50; i++)
		horde[i].annonce();
	delete[] horde;
}