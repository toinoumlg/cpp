/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:28:53 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 05:25:29 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "student.class.hpp"

int main(void)
{
    int test;
    std::cin >> test;
    Student *students = new Student[test];
    delete[] students;
    return (0);
}
