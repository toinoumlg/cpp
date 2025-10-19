/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:28:53 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 07:00:26 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"

int main(void)
{
    Sample instance;
    instance.bar('c');
    instance.bar(2);
    instance.bar(4.0f);
    instance.bar(instance);
}