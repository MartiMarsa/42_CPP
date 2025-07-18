/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:20:23 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/17 19:20:24 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Here is an example of standard usage:\n";
        std::cerr << "$> ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return 1;
    }
    RPN rpn;

    if (rpn.validateInput(argv[1]))
           rpn.reversePolishNotation(argv[1]);
    else
    {
        std::cerr << "Error: bad input. Here is an example of standard usage:\n";
        std::cerr << "$> ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return 1;
    }
    return 0;
}
