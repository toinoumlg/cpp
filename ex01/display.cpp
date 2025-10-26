/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:32:47 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/26 13:32:44 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.hpp"

#include <cstdlib>

using namespace std;

void display_nbr(int nbr) { cout << setw(10) << left << nbr; }

void display_10(string tmp) {
	if (tmp.length() > 10) {
		tmp.replace(9, 1, ".");
		tmp.erase(10);
	}
	cout << setw(10) << left << tmp;
}

int promt_possible_nbr(int i) {
	int j;
	string input;

	j = 1;
	if (!i)
		return (-1);
	cout << "Possible contact nbr: ";
	while (j < i)
		cout << j++ << ", ";
	cout << j << " > ";
	getline(cin, input);
	if (input.length() != 1 || input.at(0) - 48 < 1 || input.at(0) - 48 > i)
		return (promt_possible_nbr(i));
	return (input.at(0) - 48 - 1);
}

void displayHeader(void) {
	cout << "|";
	display_10("Index");
	cout << "|";
	display_10("First name");
	cout << "|";
	display_10("Last name");
	cout << "|";
	display_10("Nick name");
	cout << "|" << endl;
}
