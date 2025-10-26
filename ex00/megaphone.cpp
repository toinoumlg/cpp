/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:14:44 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/26 13:35:08 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int j;
	int i = 1;

	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		while (argv[i]) {
			j = 0;
			while (argv[i][j])
				cout << static_cast<char>(toupper(argv[i][j++]));
			i++;
		}
	}
	cout << endl;
	return (0);
}