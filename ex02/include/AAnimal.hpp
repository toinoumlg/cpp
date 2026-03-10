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

#ifndef AANIMAL_CLASS_H
#define AANIMAL_CLASS_H

#include <iostream>

class AAnimal {
   public:
	virtual ~AAnimal();

	AAnimal &operator=(const AAnimal &other);

	const std::string getType() const;
	virtual void makeSound() const = 0;

   protected:
	AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal(const std::string type);
	std::string type;
};

#endif