/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:11:56 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/30 12:07:59 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc != 2)
	{
		std::cerr << "Please insert one file with data to evaluate" << std::endl;
		return (EXIT_FAILURE);
	}
	BitcoinExchange btc;
	if (btc.start(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
	
	
}