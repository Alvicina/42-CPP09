/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:20:04 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/01 18:31:24 by alvicina         ###   ########.fr       */
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

int	RPN::start(std::string const & input)
{
	(void) input;
	return (0);
}

	