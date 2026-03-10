/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/10 11:30:00 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void test_array() {
	Animal *array[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}
	for (int i = 0; i < 10; i++) {
		array[i]->makeSound();
	}

	for (int i = 0; i < 10; i++) {
		delete array[i];
	}
}

void test_copy() {
	Cat first("little cat");
	Cat second;

	std::cout << "first idea[5]: " << first.getBrainIdea(5) << std::endl;
	first.setBrainIdea("ILLUMINATION", 5);
	std::cout << "first idea[5]: " << first.getBrainIdea(5) << std::endl
	          << std::endl;

	std::cout << "second idea[5]: " << second.getBrainIdea(5) << std::endl;
	second = first;
	std::cout << "second idea[5]: " << second.getBrainIdea(5) << std::endl
	          << std::endl;

	first.setBrainIdea("no idea");
	std::cout << "first idea[65]: " << first.getBrainIdea(65) << std::endl;
	std::cout << "second idea[65]: " << second.getBrainIdea(65) << std::endl
	          << std::endl;

	Cat third(first);

	std::cout << "first idea[65]: " << first.getBrainIdea(65) << std::endl;
	std::cout << "third idea[65]: " << third.getBrainIdea(65) << std::endl
	          << std::endl;
}

int main(void) {
	test_array();
	test_copy();
}
