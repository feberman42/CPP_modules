/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:24:56 by feberman          #+#    #+#             */
/*   Updated: 2024/10/18 16:58:34 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	intputToStack(std::string input, std::stack<char> &stack);
static bool calculate(std::stack<char> &stack, double *result);

double	rpn(const char *input, int *err_flag)
{
	std::stack<char>	stack;
	double				result;

	if (intputToStack(static_cast<std::string>(input), stack) == false)
	{
		if (err_flag != NULL)
			*err_flag = -1;
		std::cerr << "Input contains unsupported characters. Or is not space seperated." << std::endl;
		return (0);
	}
	if (calculate(stack, &result) == false)
	{
		if (err_flag != NULL)
			*err_flag = -1;
		std::cerr << "Invalid input syntax." << std::endl;
		return (0);
	}
	if (err_flag != NULL)
			*err_flag = 0;
	return (result);
}

static bool	intputToStack(std::string input, std::stack<char> &stack)
{
	char	c;

	if (input.empty() == true)
		return (false);
	while (input.empty() != true)
	{
		c = input[input.length() - 1];
		if (c == ' ')
		{
			input.erase(input.length() - 1, 1);
			continue ;
		}
		else if ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/')
		{
			stack.push(c);
			input.erase(input.length() - 1, 1);
			if (input.length() != 0 && input[input.length() - 1] != ' ')
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

static bool calculate(std::stack<char> &stack, double *result)
{
	std::stack<double>	values;
	double				num;
	char				c;

	while (stack.empty() == false)
	{
		c = stack.top();
		if (c >= '0' && c <= '9')
		{
			values.push(c - '0');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (values.size() < 2)
				return (false);
			num = values.top();
			values.pop();
			if (c == '+')
				values.top() += num;
			else if (c == '-')
				values.top() -= num;
			else if (c == '*')
				values.top() *= num;
			else if (c == '/')
				values.top() /= num;
		}
		else
			return (false);
		stack.pop();
	}
	if (values.size() != 1)
		return (false);
	*result = values.top();
	return (true);
}
