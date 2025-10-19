/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   student.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:05 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 06:01:07 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H

#include <iostream>

class Student
{
   public:
    Student(std::string const &login);
    ~Student();
    std::string &getLoginRef();
    std::string const &getLoginRefConst() const;
    std::string *getLoginPtr();
    std::string const *getLoginPtrConst() const;

   private:
    std::string _login;
};

#endif
