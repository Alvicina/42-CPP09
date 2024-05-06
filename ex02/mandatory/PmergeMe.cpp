/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:33:06 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/06 17:00:48 by alejandro        ###   ########.fr       */
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
		this->_dequeContainer = other._dequeContainer;
		this->_vectorContainer = other._vectorContainer;
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

void PmergeMe::saveNumbers(char **nums)
{
	size_t	i = 1;		

	while (nums[i])
	{
		int	digit = atoi(nums[i]);
		_dequeContainer.push_back(digit);
		_vectorContainer.push_back(digit);
		i++;
	}
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

void PmergeMe::printVectorNumbers(void)
{
	std::vector<int>::iterator it;

	for (it = _vectorContainer.begin(); it != _vectorContainer.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void	PmergeMe::assignPairValues(std::vector<std::pair<int, int> > & pairList, int it, int itNext)
{
	if (itNext < it)
	{
		std::pair<int, int> aux(itNext, it);
		pairList.push_back(aux);
	}
	else
	{
		std::pair<int, int> aux(it, itNext);
		pairList.push_back(aux);
	}
}

template <typename T>
void	PmergeMe::doPairs(T & container, std::vector<std::pair<int, int> > & pairList, 
int numberPairs)
{
	typename T::iterator it = container.begin();
	std::vector<std::pair<int, int> > pairAux;
	int	i = 0;

	while  (i < numberPairs)	
	{
		assignPairValues(pairList, *it, *std::next(it));
		it = std::next(it, 2);
		i++;
	}
	if (it != container.end())
	{
		std::pair<int, int>aux(-1, *it);
		pairList.push_back(aux);
	}
}

static bool	sortPairs(std::pair<int, int> const & a, std::pair<int, int> const & b)
{
	if (a.first < b.first)
		return (true);
	else
		return (false);
}

template <typename T>
void	PmergeMe::addFirstsToContainer(T & container, std::vector<std::pair<int, int> > const & pairList)
{
	for (std::vector<std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); it++)
	{
		if (it->first != -1)
			container.push_back(it->first);
	}
}

template <typename T>
void	PmergeMe::insertSort(T & container, std::vector<std::pair<int, int> > const & pairList)
{
	for (std::vector<std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); it++)
	{
		typename T::iterator itContainer = container.begin(); 
		while (*itContainer < it->second && itContainer != container.end())
			itContainer++;
		container.insert(itContainer, it->second);
	}
}

template <typename T>
clock_t	PmergeMe::MergeInsertSort(T & container)
{
	clock_t start = clock();
	std::vector<std::pair<int, int> > pairList;
	
	doPairs(container, pairList, container.size() / 2);
	container.clear();
	std::sort(pairList.begin(), pairList.end(), sortPairs);
	addFirstsToContainer(container, pairList);
	insertSort(container, pairList);
	return (clock() - start);
}

int	PmergeMe::start(char **nums)
{
	std::string	numbers;
	inputToString(nums, numbers);
	if (!isInputOk(numbers) || !checkForMaxInt(nums))
		return (EXIT_FAILURE);
	saveNumbers(nums);
	std::cout << "Before:" << std::setw(3);
	printVectorNumbers();
	clock_t dequeTime = MergeInsertSort<std::deque<int> >(_dequeContainer);
	clock_t vectorTime = MergeInsertSort<std::vector<int> >(_vectorContainer);
	std::cout << "After:" << std::setw(4);
	printVectorNumbers();
	std::cout << "Time to process a range of " << _dequeContainer.size() << " elements with std::deque: " << dequeTime << "us" <<std::endl;
	std::cout << "Time to process a range of " << _vectorContainer.size() << " elements with std::vector: " << vectorTime << "us" << std::endl;
	return (EXIT_SUCCESS);
}

