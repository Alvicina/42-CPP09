/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:06:48 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/30 18:05:15 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file("data.csv");
	std::string		line;
	
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open database for Bitcoin data" << std::endl;
		exit(1);
	}
	if (file.peek() == EOF)
	{
		std::cerr << "Error: Database for Bitcoin is empty" << std::endl;
		exit(1);
	}
	std::getline(file, line); // nos saltamos la primera linea del fichero
	while (std::getline(file, line))
	{
		size_t lim = line.find(',');
		std::string date = trimSpace(line.substr(0, lim)); // gestionamos espacios
		std::string value = trimSpace(line.substr(lim + 1, line.length() - lim)); //gestionamos espacios
		_data[date] = value;
	}	
	file.close();
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & other)
{
	if (this != &other)
	{
		this->_data = other._data;
	}
	return (*this);
}

std::string BitcoinExchange::trimSpace(std::string const & str)
{
	size_t	first = str.find_first_not_of(' ');
	if (first == std::string::npos)
		return str;
	
	size_t	last = str.find_last_not_of(' ');
	return (str.substr(first, last - first + 1));
}

int	BitcoinExchange::checker(std::string *line, std::ifstream *inputFile)
{
	if (!(inputFile->is_open()))
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return (EXIT_FAILURE);
	}
	if (inputFile->peek() == EOF)
	{
		std::cerr << "Error: Input file is empty" << std::endl;
		return (EXIT_FAILURE);
	}
	std::getline(*inputFile,  *line); // gestionamos la primera linea que tiene que ser "date | value"
	if (*line != "date | value")
	{
		std::cerr <<"Error: incorrect format for input file" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

bool BitcoinExchange::checkDigits(std::string const & date, int(*func)(int))
{
	for (size_t i = 0; i < date.length(); i++)
	{
		if (!func(date[i]))
			return (false);
	}
	return (true);
}

bool BitcoinExchange::checkInts(std::string const &year, std::string const &month,
std::string const &day)
{
	std::stringstream	ssyear(year);
	std::stringstream	ssmonth(month);
	std::stringstream	ssday(day);
	int					intYear;
	int					intMonth;
	int					intDay;

	ssyear >> intYear;
	ssmonth >> intMonth;
	ssday	>> intDay;
	if (intYear < 2009 || intYear > 2022 || intMonth < 1 || intMonth > 12
	|| intDay < 1 || intDay > 31)
		return (false);
	if ((intMonth == 4 || intMonth == 6 || intMonth == 9 || intMonth == 11) && intDay > 30)
		return (false);
	
	
	
	
}

bool BitcoinExchange::isDateValid(std::string const & date)
{
	if (date.length() < 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	if (!checkDigits(year, isdigit) || !checkDigits(month, isdigit)
	|| !checkDigits(day, isdigit))
		return (false);
	if (!checkInts(year, month, day))
		return (false);
	return (true);
}

int	BitcoinExchange::start(std::string const & fileName)
{
	std::ifstream	inputFile(fileName);
	std::string		line;
	
	if (checker(&line, &inputFile) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(inputFile, line))
	{
		size_t	lim = line.find('|');
		if (lim == std::string::npos)
		{
			std::cerr << "Error: bad input in line" << std::endl;
			continue;
		}
		std::string date = trimSpace(line.substr(0, lim)); // gestionamos espacios 
		std::string	amount = trimSpace(line.substr(lim + 1, line.length() - lim)); // gestionamos espacios
		if (!isDateValid(date) || amount.empty())
		{
			std::cerr << "Error: Date or amount not valid:" << line << std::endl;
			continue; 
		}
		
		
		
	}
	return (EXIT_SUCCESS);
}
