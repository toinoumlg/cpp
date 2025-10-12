/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample1.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:05 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/12 15:02:53 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

# include <iostream>

class Sample1
{
  public:
	char a1;
	int a2;
	float a3;
	Sample1(char p1, int p2, float p3);
	~Sample1();
};

#endif