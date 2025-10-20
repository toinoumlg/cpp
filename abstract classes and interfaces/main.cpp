/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:19:56 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/20 16:57:43 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ACharacter
{
   public:
    virtual void attack() = 0;
    void sayHello();
};

class Warrior : public ACharacter
{
   public:
    virtual void attack();
};

class ICharacter
{
   public:
    virtual void spwanCharacter() = 0;
    virtual void kill() = 0;
};

void ACharacter::sayHello() { std::cout << "character" << std::endl; }
void Warrior::attack() { std::cout << "warrior attack" << std::endl; }

int main()
{
    ACharacter *b = new Warrior;

    b->sayHello();
}
