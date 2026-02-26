/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:42 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/26 10:59:42 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "contact.class.hpp"

class PhoneBook {
   public:
	PhoneBook();
	~PhoneBook();

   private:
	Contact _contacts[8];
	int _created;
	int _index;
	void _addContact();
	void _search() const;
};

#endif