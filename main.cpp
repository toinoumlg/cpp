/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:00:01 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/20 17:07:47 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

void test1()
{
    try
    {
        if (1)
            throw std::exception();
        else
            ;
    }
    catch (std::exception e)
    {
    }
}

void test2() {}