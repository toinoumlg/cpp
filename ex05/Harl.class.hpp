/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:53:44 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/04 10:57:39 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_H
#define HARL_CLASS_H

#include <string>

using namespace std;

class Harl {
   public:
	Harl();
	~Harl();

	void complain(string level) const;

   private:
	void debug() const;
	void info() const;
	void warning() const;
	void error() const;
};

#endif