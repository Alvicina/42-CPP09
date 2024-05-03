/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:33:06 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/03 18:59:26 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe::PmergeMe(PmergeMe const & copy)
{
	*this = copy;
}

PmergeMe& PmergeMe::operator=(PmergeMe const & other)
{
	if (this != &other)
	{
		this->dequeContainer = other.dequeContainer;
		this->listContainer = other.listContainer;
	}
	return (*this);
}

void PmergeMe::inputToString(char **nums, std::string & numbers)
{
	size_t	i = 1;
	while (nums[i])
	{
		numbers = numbers + nums[i];
		numbers = numbers + ' ';
		i++;
	}
}

bool PmergeMe::isInputOk(std::string const & numbers)
{
	if (numbers.empty())
	{
		std::cout << "Error: Empty input" << std::endl;
		return (false);
	}
	size_t	i = 0;
	while (numbers[i])
	{
		if (numbers[i] != ' ' && !isdigit(numbers[i]))
		{
			std::cout << "Error: Invalid chars in input" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

double	PmergeMe::stringToDouble(std::string const & str)
{
	std::stringstream ssdouble(str);
	double	toDouble;

	ssdouble >> toDouble;
	return (toDouble);
}

bool PmergeMe::saveNumbersOk(std::string const & numbers)
{
	size_t	i = 0;

	while 
}

bool PmergeMe::checkForMaxInt(char **argv)
{
	size_t	i = 1;

	while (argv[i])
	{
		if (stringToDouble(argv[i]) > std::numeric_limits<int>::max())
		{
			std::cout << "Error: max int value surpassed" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

int	PmergeMe::start(char **nums)
{
	std::string	numbers;
	inputToString(nums, numbers);
	std::cout << numbers << std::endl;
	if (!isInputOk(numbers) || !checkForMaxInt(nums) || !saveNumbersOk(numbers))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

