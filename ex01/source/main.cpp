/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/10 10:40:20 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
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
