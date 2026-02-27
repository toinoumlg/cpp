/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:30 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/27 18:02:31 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <iostream>

class Contact {
   public:
	Contact();
	~Contact();

	void set(int i);
	void display() const;
	void displayFull() const;

   private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkest;
	int _index;
};

#endif