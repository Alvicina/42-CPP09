/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:20:04 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/03 12:01:37 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{
	
}

RPN::RPN(RPN const & copy)
{
	*this = copy;
}

RPN& RPN::operator=(RPN const & other)
{
	if (this != &other)
	{
		this->_rpnStack = other._rpnStack;
	}
	return (*this);
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return (true);
	else
		return (false);
}

bool	RPN::isNextSpace(char c)
{
	std::string whiteSpace = "\t\n\v\f\r ";
	size_t	j = 0;

	while (whiteSpace[j] && c != whiteSpace[j])
		j++;
	if (c == whiteSpace[j])
		return (true);
	else if (c == '\0')
		return (true);
	return (false);

}

bool	RPN::isInputValid(std::string const & input)
{
	size_t	i = 0;
	std::string whiteSpace = "\t\n\v\f\r ";
	
	while (input[i])
	{
		size_t	j = 0;
		while (input[i] != whiteSpace[j] && whiteSpace[j])
			j++;
		if (input[i] == whiteSpace[j])
			i++;
		else
		{
			if (!((isdigit(input[i]) || isOperator(input[i])) && isNextSpace(input[i + 1])) && input[i])
			{
				std::cerr << "Error: Invalid input" << std::endl;
				return (false);
			}
			i++;
		}
	}
	return (true);
	
}

bool	RPN::areOperandsOK(std::string const & input)
{
	size_t	numCount = 0;
	size_t	operandCount = 0;

	for (size_t i = 0; input[i]; i++)
	{
		if (isdigit(input[i]))
			numCount++;
		else if (isOperator(input[i]))
			operandCount++;
	}
	if (numCount > operandCount)
		return (true);
	else
	{
		std::cerr << "Error: Too many operators" << std::endl;
		return (false);
	}
}

void	RPN::replaceChars(std::string & inputNew, char c)
{
	std::string whiteSpace = "\t\n\v\f\r";
	size_t		i = 0;
	while (inputNew[i])
	{	
		size_t j = 0;
		while (whiteSpace[j] && inputNew[i] != whiteSpace[j])
			j++;
		if (inputNew[i] == whiteSpace[j])
		{
			inputNew[i] = c;
			i++;
		}
		else
			i++;
	}
}

int	RPN::start(std::string input)
{
	if ((!isInputValid(input) || !areOperandsOK(input)))
		return (EXIT_FAILURE);
	std::string intputNew = input;
	replaceChars(intputNew, ' ');
	return (EXIT_SUCCESS);
}