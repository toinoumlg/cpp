/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:07:30 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/04 07:58:06 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int main() {
	string str = "HI THIS IS BRAIN";
	string* strPTR = &str;
	string& strREF = str;

	cout << "Memory address str: " << &str << endl
	     << "Memory address strPTR: " << strPTR << endl
	     << "Memory address strREF: " << &strREF << endl;

	cout << "Value str: " << str << endl
	     << "Value strPTR: " << *strPTR << endl
	     << "Value strREF: " << strREF << endl;
}