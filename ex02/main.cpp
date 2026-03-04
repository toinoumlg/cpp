/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:07:30 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 10:54:44 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* strPTR = &str;
	std::string& strREF = str;

	std::cout << "Memory address str: " << &str << std::endl
	          << "Memory address strPTR: " << strPTR << std::endl
	          << "Memory address strREF: " << &strREF << std::endl;

	std::cout << "Value str: " << str << std::endl
	          << "Value strPTR: " << *strPTR << std::endl
	          << "Value strREF: " << strREF << std::endl;
}