/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:29:53 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/03 18:41:19 by alvicina         ###   ########.fr       */
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

class PmergeMe
{
	private:
		std::deque<int> dequeContainer;
		std::list<int> listContainer;
		void	inputToString(char **argv, std::string & numbers);
		bool	isInputOk(std::string const & numbers);
		bool	saveNumbersOk(std::string const & numbers);
		bool	checkForMaxInt(char **argv);
		double	stringToDouble(std::string const & str);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const & copy);
		PmergeMe& operator=(PmergeMe const & other);
		int	start(char **nums);		
};

#endif