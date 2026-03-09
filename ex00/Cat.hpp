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

#ifndef CAT_CLASS_H
#define CAT_CLASS_H

#include "Animal.hpp"

class Cat : public Animal {
   public:
	Cat();
	Cat(const std::string type);
	Cat(const Cat &other);
	~Cat();

	Cat &operator=(const Cat &other);

	void makeSound() const;
};

#endif