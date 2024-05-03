/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:15:30 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/03 16:19:50 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: enter expression to be solved" << std::endl;
		return (EXIT_FAILURE);
	}
	RPN	rpnSolver;
	if (rpnSolver.start(argv[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}