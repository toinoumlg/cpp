/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:24:57 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/10 11:32:53 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructed" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = "default";
	}
}

Brain::Brain(const std::string &idea) {
	std::cout << "Brain parameterized constructor" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = idea;
	}
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain assignement operator" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	return *this;
}

void Brain::setIdea(std::string idea) {
	for (int i = 0; i < 100; i++) {
		ideas[i] = idea;
	}
}

void Brain::setIdea(std::string idea, int i) {
	if (i >= 0 && i < 100)
		ideas[i] = idea;
}

std::string Brain::getIdea(int i) {
	if (i >= 0 && i < 100)
		return ideas[i];
	else
		return "";
}

Brain::~Brain() {
	std::cout << "Brain destructed" << std::endl;
}