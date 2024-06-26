/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:29:53 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/11 12:39:09 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
#include <sstream>
#include <limits>
#include <iomanip>
#include <time.h>
#include <vector>

class PmergeMe
{
	private:
		std::deque<int> _dequeContainer;
		std::vector<int> _vectorContainer;
		void	inputToString(char **argv, std::string & numbers);
		bool	isInputOk(std::string const & numbers);
		void	saveNumbers(char **nums);
		bool	checkForMaxInt(char **argv);
		double	stringToDouble(std::string const & str);
		void	printVectorNumbers(void);
		template <typename T>
		clock_t	MergeInsertSort(T & container);
		template <typename Iterator>
		Iterator next(Iterator iter, typename std::iterator_traits<Iterator>::difference_type n);
		template <typename T>
		void	doPairs(T & container, std::vector<std::pair<int, int> > & pairList, int numberPais);
		template <typename T>
		void	addFirstsToContainer(T & container, std::vector<std::pair<int, int> > const & pairList);
		template <typename T>
		void	insertSort(T & container, std::vector<std::pair<int, int> > const & pairList);
		void	assignPairValues(std::vector<std::pair<int, int> > & pairList, int it, int itNext);
		
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const & copy);
		PmergeMe& operator=(PmergeMe const & other);
		int	start(char **nums);		
};

#endif