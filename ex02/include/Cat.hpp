/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:27:51 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/10 12:02:32 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_H
#define CAT_CLASS_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
   public:
	Cat();
	Cat(const std::string type);
	Cat(const Cat &other);
	~Cat();

	Cat &operator=(const Cat &other);

	void setBrainIdea(std::string idea);
	void setBrainIdea(std::string idea, int i);
	std::string getBrainIdea(int i);

	void makeSound() const;

   private:
	Brain *_brain;
};

#endif