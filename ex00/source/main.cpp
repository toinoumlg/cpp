/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/10 16:54:35 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main(void) {
	Animal *first = new Animal();
	Animal *second = new Dog("second");
	Animal *third = new Cat();

	WrongAnimal *wrong = new WrongAnimal();
	WrongAnimal *wrong2 = new WrongCat();

	std::cout << first->getType() << std::endl;
	std::cout << second->getType() << std::endl;
	std::cout << third->getType() << std::endl;
	std::cout << wrong->getType() << std::endl;
	std::cout << wrong2->getType() << std::endl;

	first->makeSound();
	second->makeSound();
	third->makeSound();
	wrong->makeSound();
	wrong2->makeSound();

	delete first;
	delete second;
	delete third;
	delete wrong;
	delete wrong2;
}