/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:51:47 by amalangu          #+#    #+#             */
/*   Updated: 2025/11/04 11:14:13 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

using namespace std;

string replace_occurence(string line, string to_find, string to_replace,
                         size_t* i) {
	string new_line;
	new_line = line;
	new_line.erase(*i);
	new_line += to_replace;
	*i += to_find.length();
	new_line += &line.at(*i);
	return new_line;
}

void parse_line(string line, string to_find, string to_replace,
                fstream* outfile) {
	size_t i = 0;
	
	while (i < line.length()) {
		if (!line.compare(i, to_find.length(), to_find)) {
			line = replace_occurence(line, to_find, to_replace, &i);
		} else
			i++;
	}
	*outfile << line << endl;
}

int init_files(fstream* input, fstream* output, char* input_path) {
	try {
		input->open(input_path, ios::in);
		if (!input->is_open())
			throw exception();
		output->open("outfile.txt", ios::out | ios::trunc);
		if (!output->is_open())
			throw exception();
	} catch (exception& e) {
		cerr << "Error opening files" << endl;
		if (input->is_open())
			input->close();
		return 1;
	}
	return 0;
}

int main(int ac, char** av) {
	fstream input;
	fstream output;

	if (ac != 4 || init_files(&input, &output, av[1]))
		return 1;

	string line;
	string to_find = av[2];
	string to_replace = av[3];

	while (getline(input, line))
		parse_line(line, to_find, to_replace, &output);

	output.close();
	if (!input.eof()) {
		input.close();
		cerr << "Error while reading file (eof not reached)" << endl;
		return 1;
	}
	input.close();
	return 0;
}