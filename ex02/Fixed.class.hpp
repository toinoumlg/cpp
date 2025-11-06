/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:28:13 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/06 10:55:23 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
#define FIXED_CLASS_H

#include <iostream>
using namespace std;

class Fixed {
   public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int value);
	Fixed(const float value);

	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);

	// convertion
	int toInt() const;
	float toFloat() const;

	// operation
	Fixed& operator=(Fixed const& copy);
	Fixed operator+(Fixed const& addition) const;
	Fixed operator-(Fixed const& negate) const;
	Fixed operator*(Fixed const& mult) const;
	Fixed operator/(Fixed const& divider) const;

	// increment/decrement
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	// comparaison
	Fixed operator>(Fixed const& cmp) const;
	Fixed operator>=(Fixed const& cmp) const;
	Fixed operator<(Fixed const& cmp) const;
	Fixed operator<=(Fixed const& cmp) const;
	Fixed operator==(Fixed const& cmp) const;
	Fixed operator!=(Fixed const& cmp) const;

	// member functions
	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);

   private:
	int _value;
	static const int _decimal = 8;
};

ostream& operator<<(ostream& output, Fixed const& fixed);

#endif