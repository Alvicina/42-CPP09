/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:56:59 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/09 19:03:36 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, std::string> _data;
		std::string trimSpace(std::string const & str);
		int		checker(std::string *line, std::ifstream *inputFile);
		bool	isDateValid(std::string const & date);
		bool	isAmountValid(std::string const & amount);
		bool	isAmountInRange(std::string const & amount);
		bool	checkDigits(std::string const & date, int (*func)(int));
		bool	checkInts(std::string const &year, std::string const &month,
				std::string const &day);
		bool	LeapYear(int const &intYear);
		void	outputData(std::string const & date, std::string const & amount);
		std::string getPrevDate(std::string const & actualDate);
		int		stringToInt(std::string const & str);
		double	stringToDouble(std::string const & str);
		std::string intToString(int const &toString);
		std::string	getNextDate(std::string const & actualDate);
		std::string prevRoutine(std::string const & date, std::map<std::string, std::string>::iterator	it);
		std::string nextRoutine(std::string const & date, std::map<std::string, std::string>::iterator	it);
		std::string	whichDate(std::string const & preDate, std::string const & nextDate, std::string const & date);
		
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & copy);
		BitcoinExchange& operator=(BitcoinExchange const & other);
		int	start(std::string const & fileName);
};

#endif