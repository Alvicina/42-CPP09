/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:10:22 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/03 13:38:02 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN 
{
	private:
		std::stack<int> _rpnStack;
		bool isInputValid(std::string const & input);
		bool areOperandsOK(std::string const & input);
		bool isOperator(char c);
		bool isNextSpace(char c);
		void 	replaceChars(std::string & inputNew, char c);
		int		initSolver(std::string const & inputNew);
		void	solveOperation(char c);
		int		rpnPop(void);
		void	printSolution(void);
		
	public:
		RPN();
		~RPN();
		RPN(RPN const & copy);
		RPN& operator=(RPN const & other);
		int	start(std::string input);
		
};

#endif