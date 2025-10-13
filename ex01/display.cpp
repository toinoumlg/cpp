/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:32:47 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/13 22:32:00 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.hpp"

void	display_nbr(int nbr) {
	std::cout << std::setw(10) << std::right << nbr;
}

void	display_10(std::string tmp) {
	if (tmp.length() > 10) {
		tmp.replace(9, 1, ".");
		tmp.erase(10);
	}
	std::cout << std::setw(10) << std::right << std::string(tmp);
}

int	display_possible_nbr(int i) {
	int	j;
	int	input;

	j = 1;
	if (!i)
		return (-1);
	std::cout << "Possible contact nbr: ";
	while (j < i)
		std::cout << j++ << ", ";
	std::cout << j << " > ";
	std::cin >> input;
	if (input > i)
		return (display_possible_nbr(i));
	return (j - 1);
}

void	displayHeader(void) {
	std::cout << std::string("|");
	display_10(std::string("Index"));
	std::cout << std::string("|");
	display_10(std::string("First name"));
	std::cout << std::string("|");
	display_10(std::string("Last name"));
	std::cout << std::string("|");
	display_10(std::string("Nick name"));
	std::cout << std::string("|") << std::endl;
}