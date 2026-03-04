/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:19:51 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 16:00:41 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_H
#define ANIMAL_CLASS_H

#include <iostream>

class Animal {
   public:
	Animal();
	Animal(const std::string type);
	Animal(const Animal &other);
	~Animal();

	Animal &operator=(const Animal &other);

	virtual void makeSound() const;

   protected:
	std::string type;
};

#endif