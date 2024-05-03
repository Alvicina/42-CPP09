/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:20:04 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/03 16:20:17 by alvicina         ###   ########.fr       */
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
	if (c == '+' || c == '-' || c == '*' || c == '/')
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
				std::cout << "Error: Invalid input" << std::endl;
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
		std::cout << "Error: Too many operators" << std::endl;
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

int	RPN::rpnPop(void)
{
	int aux = _rpnStack.top();
	_rpnStack.pop();
	return (aux);
}

void RPN::solveOperation(char c)
{
	if (c == '+')
		_rpnStack.push(rpnPop() + rpnPop());
	else if ( c == '*')
		_rpnStack.push(rpnPop() * rpnPop());
	else if (c == '-')
	{
		int aux = rpnPop();
		_rpnStack.push(rpnPop() - aux);
	}
	else if (c == '/')
	{
		int aux = rpnPop();
		_rpnStack.push(rpnPop() / aux);
	}
}

int RPN::initSolver(std::string const & inputNew)
{
	size_t i = 0;

	while (inputNew[i])
	{
		while (inputNew[i] == ' ')
			i++;
		if (isdigit(inputNew[i]))
			_rpnStack.push(atoi(&inputNew[i]));
		else if (isOperator(inputNew[i]) && _rpnStack.size() >= 2)
			solveOperation(inputNew[i]);
		else
		{
			if (inputNew[i])
			{
				std::cout << "Error: Solver-> not enough operands" << std::endl;
				return (EXIT_FAILURE);
			}
			break ;
		}
		i++;
	}
	if (_rpnStack.size() >= 2)
	{
		std::cout << "Error: Solver-> not enough operators" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void RPN::printSolution()
{
	size_t size = _rpnStack.size();
	size_t i = 0;

	while (i < size)
	{
		std::cout << rpnPop() << std::endl;
		i++;
	}
}

int	RPN::start(std::string input)
{
	if ((!isInputValid(input) || !areOperandsOK(input)))
		return (EXIT_FAILURE);
	std::string inputNew = input;
	replaceChars(inputNew, ' ');
	if (initSolver(inputNew))
		return (EXIT_FAILURE);
	printSolution();
	return (EXIT_SUCCESS);
}