/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:13:15 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/10 16:13:53 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
#define BRAIN_CLASS_HPP

#include <iostream>

class Brain {
   public:
	Brain();
	Brain(const std::string& idea);
	Brain(const Brain& other);
	~Brain();

	Brain& operator=(const Brain& other);

	void setIdea(std::string idea);
	void setIdea(std::string idea, int i);
	std::string getIdea(int i) const;

   private:
	std::string ideas[100];
};

#endif