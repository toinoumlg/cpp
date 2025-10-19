/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:05 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 18:00:57 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_CLASS_H
#define INTEGER_CLASS_H

#include <iostream>
#include <ostream>

class Integer
{
   public:
    Integer(int const n);
    ~Integer();

    int getValue() const;

    Integer &operator=(Integer const &rhs);
    Integer operator+(Integer const &rhs) const;

   private:
    int _n;
};

std::ostream &operator<<(std::ostream &o, Integer const &rhs);

#endif
