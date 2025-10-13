/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:28:53 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/13 14:02:08 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.class.hpp"

int	main(void) {
	Sample	instance;
	Sample	*instance_ptr;

	instance_ptr = &instance;
	int Sample::*p = NULL;
	void (Sample::*f)(void) const;
}
