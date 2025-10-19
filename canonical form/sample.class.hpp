/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:05 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 18:33:37 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

#include <iostream>

class Sample
{
   public:
    Sample();
    Sample(int const n);
    Sample(Sample const &source);
    ~Sample();

    Sample &operator=(Sample const &rhs);

    int getFoo(void) const;

   private:
    int _foo;
};

std::ostream &operator<<(std::ostream &o, Sample const &i);

#endif
