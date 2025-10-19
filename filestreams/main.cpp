/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:28:53 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/19 06:24:28 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int main(void)
{
    std::ifstream ifs("test.txt");
    unsigned int dst1;
    unsigned int dst2;
    ifs >> dst1 >> dst2;
    std::cout << dst1 << " " << dst2 << std::endl;
    ifs.close();

    std::ofstream ofs("test.log");
    ofs << "logs lalalala";
    ofs.close();
}
