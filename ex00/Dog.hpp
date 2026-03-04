/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:19:51 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/03 14:33:09 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_H
#define DOG_CLASS_H

#include "Animal.hpp"

class Dog : Animal {
   public:
	Dog();
	Dog(const std::string type);
	Dog(const Dog& other);
	~Dog();

	Dog& Dog::operator=(const Dog& other);
	virtual void makeSound() const;

   protected:
	std::string type;
};

#endif