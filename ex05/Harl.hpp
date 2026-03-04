/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:53:44 by amalangu          #+#    #+#             */
/*   Updated: 2026/03/04 14:32:20 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_H
#define HARL_CLASS_H

#include <string>

class Harl {
   public:
	Harl();
	~Harl();

	void complain(std::string level);

   private:
	void debug();
	void info();
	void warning();
	void error();
};

#endif