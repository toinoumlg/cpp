/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   student.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:05 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 05:23:30 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H

#include <iostream>

class Student
{
   public:
    Student();
    ~Student();

   private:
    std::string _login;
};

#endif
