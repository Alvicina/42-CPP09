/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:56:59 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/30 17:52:00 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, std::string> _data;
		std::string trimSpace(std::string const & str);
		int		checker(std::string *line, std::ifstream *inputFile);
		bool	isDateValid(std::string const & date);
		bool	checkDigits(std::string const & date, int (*func)(int));
		bool	checkInts(std::string const &year, std::string const &month,
				std::string const &day);
		
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & copy);
		BitcoinExchange& operator=(BitcoinExchange const & other);
		int	start(std::string const & fileName);
};

#endif