/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:47:59 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 19:09:19 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
#define CLASS_HPP

#include <string>

class Animal
{
   private:
    int _nbrOfLegs;

   public:
    Animal();
    Animal(Animal const &);
    Animal &operator=(Animal const &);
    ~Animal();

    void run(int distance);
};

class Cat : public Animal
{
   public:
    Cat();
    Cat(Cat const &);
    Cat &operator=(Cat const &);
    ~Cat();

    void scornSomeone(std::string const &target);
};

class Pony : public Animal
{
   public:
    Pony();
    Pony(Pony const &);
    Pony &operator=(Pony const &);
    ~Pony();

    void doMagic(std::string const &target);
};

#endif