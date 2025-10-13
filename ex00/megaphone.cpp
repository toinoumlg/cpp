/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:14:44 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/13 19:50:37 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {
	int i = 1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		while (argv[i]) {
			int j = 0;
			while (argv[i][j])
				std::cout << static_cast<char>(toupper(argv[i][j++]));
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}