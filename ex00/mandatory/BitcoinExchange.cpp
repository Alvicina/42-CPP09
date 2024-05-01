/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:06:48 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/01 16:23:12 by alvicina         ###   ########.fr       */
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
	} // gestionamos la primera linea que tiene que ser "date | value"
	std::getline(*inputFile,  *line); 
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

bool BitcoinExchange::LeapYear(int const &intYear)
{
	if ((intYear % 4 == 0 && intYear % 100 != 0) || intYear % 400 == 0)
		return (true);
	return (false);
}

bool BitcoinExchange::checkInts(std::string const &year, std::string const &month,
std::string const &day)
{
	int	intYear = stringToInt(year);
	int	intMonth = stringToInt(month);
	int	intDay = stringToInt(day);

	if (intYear < 2009 || intYear > 2022 || intMonth < 1 || intMonth > 12
	|| intDay < 1 || intDay > 31)
		return (false);
	if ((intMonth == 4 || intMonth == 6 || intMonth == 9 || intMonth == 11) && intDay > 30) 
		return (false); // chequeo de meses que tienen 30 diaas
	if (intMonth == 2) 
	{
		bool isLeapYear = LeapYear(intYear);
		if (intDay > (isLeapYear ? 29 : 28))
			return (false); // chequeo de febrero si es bisiesto o no
	}
	return (true);
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

bool BitcoinExchange::isAmountValid(std::string const & amount)
{
	if (amount.empty()) // que no este vacio
	{
		std::cerr << "Error: Amount empty" << std::endl;
		return (false);
	}
	size_t	point1 = amount.find_first_of('.', 0); // que no haya dos puntos en el amount
	if (point1 != std::string::npos)
	{
		size_t	point2 = amount.find_last_of('.', amount.length());
		if (point1 != point2)
		{
			std::cerr << "Error: Amount not valid. Too many decimal points";
			std::cerr << std::endl;
			return (false);
		}
	}
	bool hasSign = (amount[0] == '+' || amount[0] == '-');
	for (size_t i = hasSign ? 1 : 0; i < amount.length(); i++) // que el amount sea un numero
	{
		if (isdigit(amount[i]) || amount[i] == '.')
			continue;
		std::cerr << "Error: Amount not valid. Not a number" << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::isAmountInRange(std::string const & amount)
{
	double	amountDouble = stringToDouble(amount);//necesitamos un double porque nos pueden pasar decimales. double > float;
												//sino con un int y un atoi se podria haber hecho;
	if (amountDouble < 0)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		return (false);
	}
	if (amountDouble > 1000)
	{
		std::cerr << "Error: too large a number" << std::endl;
		return (false);
	}
	return (true);
}

int	BitcoinExchange::stringToInt(std::string const & str)
{
	std::stringstream ssint(str);
	int	toInt;

	ssint >> toInt;
	return (toInt);
}

double	BitcoinExchange::stringToDouble(std::string const & str)
{
	std::stringstream ssdouble(str);
	double	toDouble;

	ssdouble >> toDouble;
	return (toDouble);
}

std::string BitcoinExchange::intToString(int const &toString)
{
	std::stringstream ss;

	ss << toString;
	return (ss.str());
}

std::string BitcoinExchange::getPrevDate(std::string const & actualDate)
{
	int	year = stringToInt(actualDate.substr(0, 4));
	int	month = stringToInt(actualDate.substr(5, 2));
	int	day = stringToInt(actualDate.substr(8, 2));

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //nº de dias en año no bisiesto
	if (LeapYear(year)) // chequeamos si es bisiesto el año. 
		daysInMonth[2] = 29;
	day--; //vamos restando un dia a la fecha que no hemoss encontrado en nuestra base de datos.
	if (day == 0) //  
	{
		month--; //si dia = 0; entonces tenemos que restar un mes;
		if (month == 0)
		{
			month = 12; //si mes = 0; entonces estamos en Diciembre del año anterior;
			year--;
		}
		day = daysInMonth[month]; // y en el ultimo dia del mes.
	} //formateamos fecha
	std::string strYear = intToString(year);
	std::string strMonth = (month < 10) ? "0" + intToString(month) : intToString(month);
	std::string strDay = (day < 10) ? "0" + intToString(day) : intToString(day);
	return (strYear + "-" + strMonth + "-" + strDay);
}

std::string	BitcoinExchange::getNextDate(std::string const & actualDate)
{
	int	year = stringToInt(actualDate.substr(0, 4));
	int	month = stringToInt(actualDate.substr(5, 2));
	int	day = stringToInt(actualDate.substr(8, 2));

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //nº de dias en año no bisiesto
	if (LeapYear(year)) // chequeamos si es bisiesto el año. 
		daysInMonth[2] = 29;
	day++; // sumamos un dia, para encontrar la fecha siguiente
	if (day > daysInMonth[month])
	{
		day = 1; 
		month++; //comprobamos si nos hemos pasado de dias para el mes corriente
		if (month > 12)
		{
			month = 1; //comprobamos si nos hemos pasado de meses
			year++;
		}
	}//Formateamos fecha
	std::string strYear = intToString(year);
	std::string strMonth = (month < 10) ? "0" + intToString(month) : intToString(month);
	std::string strDay = (day < 10) ? "0" + intToString(day) : intToString(day);
	return (strYear + "-" + strMonth + "-" + strDay);
}

std::string BitcoinExchange::prevRoutine(std::string const & date,
std::map<std::string, std::string>::iterator	it)
{
	std::string prevDate = date;
	
	while (it == _data.end())
	{
		std::string const & actualDate = prevDate;
		prevDate = getPrevDate(actualDate);
		if (!isDateValid(prevDate))
			return (date);
		it = _data.find(prevDate);
	}
	return (prevDate);
}

std::string BitcoinExchange::nextRoutine(std::string const & date,
std::map<std::string, std::string>::iterator	it)
{
	std::string nextDate = date;

	while (it == _data.end())
	{
		std::string const & actualDate = nextDate;
		nextDate = getNextDate(actualDate);
		if (!isDateValid(nextDate))
			return (date);
		it = _data.find(nextDate);
	}
	return (nextDate);
}

std::string	BitcoinExchange::whichDate(std::string const & preDate,
std::string const & nextDate, std::string const & date)
{
	int intPreDate = stringToInt(preDate.substr(0, 4)) + stringToInt(preDate.substr(5, 2))
	+ stringToInt(preDate.substr(8, 2));
	int	intNextDate = stringToInt(nextDate.substr(0, 4)) + stringToInt(nextDate.substr(5, 2))
	+ stringToInt(nextDate.substr(8, 2));
	int	intDate = stringToInt(date.substr(0, 4)) + stringToInt(date.substr(5, 2))
	+ stringToInt(date.substr(8, 2));

	if (std::abs(intPreDate - intDate) > std::abs(intNextDate - intPreDate))
		return (nextDate);
	else 
		return (preDate);
}

void	BitcoinExchange::outputData(std::string const & date, std::string const & amount)
{	
	std::map<std::string, std::string>::iterator	it;
	std::string dateToUse;
	it = _data.find(date); //1)buscamos la fecha en nuesta base de datos

	if (it == _data.end()) //2)si no la encontramos, buscamos la anterior y la siguiente
	{
		std::string	preDate = prevRoutine(date, it);
		std::string nextDate = nextRoutine(date, it);
		if (preDate == date)
			dateToUse = nextDate;
		else if (nextDate == date)
			dateToUse = preDate;
		else
			dateToUse = whichDate(preDate, nextDate, date);
		it = _data.find(dateToUse);
	}
	std::cout << date << " => " << amount << " = ";
	std::cout << stringToDouble(it->second) * stringToDouble(amount) << std::endl;
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
			std::cerr << "Error: missing '|' in line: " << line << std::endl;
			continue;
		}
		std::string date = trimSpace(line.substr(0, lim)); // gestionamos espacios 
		std::string	amount = trimSpace(line.substr(lim + 1, line.length() - lim)); // gestionamos espacios
		if (!isDateValid(date))
		{
			std::cerr << "Error: Date not valid:" << line << std::endl;
			continue; 
		}
		if (!isAmountValid(amount) || !isAmountInRange(amount))
			continue;
		outputData(date, amount);
	}
	inputFile.close();
	return (EXIT_SUCCESS);
}
