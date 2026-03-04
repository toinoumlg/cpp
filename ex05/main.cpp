/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:03:34 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 15:13:52 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int main() {
	Harl test;
	test.complain("INFO");
	test.complain("DEBUG");
	test.complain("G");
	test.complain("5");
	test.complain("G");
	test.complain("3");
	test.complain("ERROR");
	test.complain("G");
	test.complain("G");
}
