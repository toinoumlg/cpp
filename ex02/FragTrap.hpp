/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:13 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/09 15:15:36 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_H
#define FRAGTRAP_CLASS_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
   public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	~FragTrap();

	FragTrap& operator=(const FragTrap& other);

	void highFivesGuys() const;
};

#endif