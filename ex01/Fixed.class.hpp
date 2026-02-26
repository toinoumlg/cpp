/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:13 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/26 20:04:24 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
#define FIXED_CLASS_H

#include <iostream>

class Fixed {
   public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int value);
	Fixed(const float value);

	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);

	int toInt() const;
	float toFloat() const;

	Fixed& operator=(Fixed const& copy);

   private:
	int _value;
	static const int _decimal = 8;
};

std::ostream& operator<<(std::ostream& output, Fixed const& fixed);

#endif