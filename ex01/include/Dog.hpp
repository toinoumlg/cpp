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
#include "Brain.hpp"

class Dog : public Animal {
   public:
	Dog();
	Dog(const std::string type);
	Dog(const Dog& other);
	~Dog();

	Dog& operator=(const Dog& other);

	void makeSound() const;
	void setIdea(std::string idea);
	void setIdea(std::string idea, int i);
	std::string getIdea(int i) const;

   private:
	Brain* brain;
};

#endif