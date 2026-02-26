/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2026/02/26 21:12:28 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

std::string replace_occurence(std::string line, std::string to_find,
                              std::string to_replace, size_t* i) {
	std::string new_line;
	new_line = line;
	new_line.erase(*i);
	new_line += to_replace;
	*i += to_find.length();
	new_line += &line.at(*i);
	return new_line;
}

void parse_line(std::string line, std::string to_find, std::string to_replace,
                std::fstream* outfile) {
	size_t i = 0;

	if (!line.length())
		return;
	while (i < line.length()) {
		if (!line.compare(i, to_find.length(), to_find)) {
			line = replace_occurence(line, to_find, to_replace, &i);
		} else
			i++;
	}
	*outfile << line << std::endl;
}

int init_files(std::fstream* input, std::fstream* output, char* input_path) {
	try {
		input->open(input_path, std::ios::in);
		if (!input->is_open())
			throw std::exception();
		std::string output_path = input_path;
		output_path.append(".replace");

		output->open(output_path.c_str(), std::ios::out | std::ios::trunc);
		if (!output->is_open())
			throw std::exception();
	} catch (std::exception& e) {
		std::cerr << "Error opening files" << std::endl;
		if (input->is_open())
			input->close();
		return 1;
	}
	return 0;
}

int main(int ac, char** av) {
	std::fstream input;
	std::fstream output;

	if (ac != 4 || init_files(&input, &output, av[1]))
		return 1;

	std::string line;
	std::string to_find = av[2];
	std::string to_replace = av[3];

	if (!to_find.length() || !to_replace.length()) {
		input.close();
		output.close();
		std::cerr << "Invalid arguments (empty argv)" << std::endl;
		return 1;
	}

	while (getline(input, line))
		parse_line(line, to_find, to_replace, &output);

	output.close();
	if (!input.eof()) {
		input.close();
		std::cerr << "Error while reading file (eof not reached)" << std::endl;
		return 1;
	}
	input.close();
	return 0;
}