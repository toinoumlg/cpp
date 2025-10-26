/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:30 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/26 13:32:42 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <string>
using namespace std;

class Contact {
   public:
	Contact();
	~Contact();

	void set(int i);
	void display() const;
	void displayFull() const;

   private:
	string _firstname;
	string _lastname;
	string _nickname;
	string _phonenumber;
	string _darkest;
	int _index;
};

#endif