/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:21:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/13 19:03:47 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"

int Sample::_nbInst = 0;

Sample::Sample() {
	std::cout << "Constructor called" << std::endl;
	Sample::_nbInst++;
}



int Sample::getNbInst() {
	return (Sample::_nbInst);
}
