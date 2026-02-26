/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:13:39 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/26 20:52:58 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

void randomChump(std::string name) {
	Zombie tmp;
	tmp.setName(name);
	tmp.announce();
	return;
}