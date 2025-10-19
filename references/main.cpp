/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:28:53 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 06:16:05 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "student.class.hpp"

int main(void)
{
    Student bob = Student("bfubar");
    Student const jim = Student("jfubar");

    std::cout << bob.getLoginRef() << " " << jim.getLoginRefConst()
              << std::endl;
    std::cout << *bob.getLoginPtrConst() << " " << *jim.getLoginPtrConst()
              << std::endl;

    bob.getLoginRef() = "caca";
    std::cout << bob.getLoginRef() << std::endl;
    *bob.getLoginPtr() = "prout";
    std::cout << bob.getLoginRef() << std::endl;
}
