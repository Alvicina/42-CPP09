/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:44:04 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/03 16:51:59 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	(void) argc;
	PmergeMe	PmergeMeSolver;
	if (PmergeMeSolver.start(argv))
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
	
}