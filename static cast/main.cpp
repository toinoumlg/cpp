/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 02:56:25 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/26 03:03:16 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Parent
{
};

class Child1 : public Parent
{
};

class Child2 : public Parent
{
};

class Unrealated
{
};

int main()
{
    Child1 a;

    Parent* b = &a;
    Child1* c = b;
    Child2* d = static_cast<Child2*>(b);
    Unrealated* e = static_cast<Unrealated*>(&a);
}