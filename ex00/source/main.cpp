/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/10 13:15:39 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main(void) {
	Animal *test1 = new Animal();
	Animal *test2 = new Dog();
	Animal *test3 = new Cat();
	Animal *test4;

	WrongAnimal *wrong = new WrongAnimal();
	WrongAnimal *wrong2 = new WrongCat();

	test4 = test2;
	std::cout << test1->getType() << std::endl;
	std::cout << test2->getType() << std::endl;
	std::cout << test3->getType() << std::endl;
	std::cout << test4->getType() << std::endl;
	std::cout << wrong->getType() << std::endl;
	std::cout << wrong2->getType() << std::endl;

	test1->makeSound();
	test2->makeSound();
	test3->makeSound();
	test4->makeSound();
	wrong->makeSound();
	wrong2->makeSound();

	delete test1;
	delete test2;
	delete test3;
	delete wrong;
	delete wrong2;
}