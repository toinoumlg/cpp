/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/09 18:45:55 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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