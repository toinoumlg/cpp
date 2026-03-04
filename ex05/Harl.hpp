/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:53:44 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 10:44:28 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_H
#define HARL_CLASS_H

#include <string>

class Harl {
   public:
	Harl();
	~Harl();

	void complain(std::string level) const;

   private:
	void debug() const;
	void info() const;
	void warning() const;
	void error() const;
};

#endif