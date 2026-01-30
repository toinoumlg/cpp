/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:34:34 by amalangu          #+#    #+#             */
/*   Updated: 2026/01/30 10:20:23 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>

#include <csignal>

#include "contact.class.hpp"
#include "phonebook.class.hpp"

void signalHandler(int sig) { (void)sig; }

int main(void) {
	struct termios tty;
	tcgetattr(0, &tty);
	tty.c_lflag &= ~(ISIG);
	tcsetattr(0, 0, &tty);
	signal(SIGINT, signalHandler);
	try {
		PhoneBook phonebook;
	} catch (const char* e) {
		std::cerr << std::endl << e << std::endl;
		return (1);
	}
}