/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:32:47 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/26 14:13:09 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.hpp"

#include <cstdlib>

using namespace std;

void displayNbr(int nbr) { cout << setw(10) << left << nbr; }

void display10(string tmp) {
	if (tmp.length() > 10) {
		tmp.replace(9, 1, ".");
		tmp.erase(10);
	}
	cout << setw(10) << left << tmp;
}

void displayHeader(void) {
	cout << "|";
	display10("Index");
	cout << "|";
	display10("First name");
	cout << "|";
	display10("Last name");
	cout << "|";
	display10("Nick name");
	cout << "|" << endl;
}
