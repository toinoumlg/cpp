/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:35:48 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/09 18:36:43 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_CLASS_H
#define WRONG_CAT_CLASS_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
   public:
	WrongCat();
	WrongCat(const std::string type);
	WrongCat(const WrongCat &other);
	~WrongCat();

	WrongCat &operator=(const WrongCat &other);

	void makeSound() const;
};

#endif