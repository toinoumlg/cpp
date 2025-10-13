/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:30 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/13 22:10:49 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <ctime>
# include <string>

class Contact {
  public:
	Contact();
	~Contact();

	void set(int i);
	void display() const;
	void displayFull() const;
	int getIndex() const;
	time_t getCreation() const;

  private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkest;
	time_t _creation;
	int _index;
};

#endif