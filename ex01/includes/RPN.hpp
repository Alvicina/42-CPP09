/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:10:22 by alvicina          #+#    #+#             */
/*   Updated: 2024/05/01 18:30:31 by alvicina         ###   ########.fr       */
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
		
	public:
		RPN();
		~RPN();
		RPN(RPN const & copy);
		RPN& operator=(RPN const & other);
		int	start(std::string const & input);
		
};

#endif