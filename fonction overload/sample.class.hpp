/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:05 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 06:54:58 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

class Sample
{
   public:
    Sample();
    ~Sample();
    void bar(char const c) const;
    void bar(int const n) const;
    void bar(float const z) const;
    void bar(Sample const &i) const;
};

#endif
