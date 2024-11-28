/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:31:30 by feberman          #+#    #+#             */
/*   Updated: 2024/11/28 19:08:30 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "pmergeMe.h"

static void	createlist(int argc, char *argv[], std::list<int> &_list);
static void	printlist(std::list<int> &_list, const char *prefix);
static void	sortlistRec(std::list<int> &_list);
static void	binaryInsert(std::list<int> &_list, std::list<std::pair<int, int> > &pairs);
static std::list<std::pair<int, int> >::iterator	findPairValue(std::list<std::pair<int, int> > &pairs, int value);
static void	createPairs(std::list<int> &_list, std::list<std::pair<int, int> > &pairs);
static void	calculateJacobsSteps(std::list<int> &_list, std::list<int> &steps);
static void	buildInsertionOrder(std::list<int> &_list, \
	std::list<std::pair<int, int> > &pairs, std::list<std::pair<int, int> > &insertPairs);

void	sortlist(int argc, char *argv[], bool print)
{
	std::list<int>	_list;

	createlist(argc, argv, _list);
	if (print)
		printlist(_list, "Before:\t");
	sortlistRec(_list);
	if (print)
		printlist(_list, "After:\t");
}

static void	printlist(std::list<int> &_list, const char *prefix)
{
	std::cout << prefix;
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static void	sortlistRec(std::list<int> &_list)
{
	std::list<std::pair<int, int> >	pairs;
	

	if (_list.size() == 1)
		return ;
	
	createPairs(_list, pairs);
	// for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	// 	std::cout << "<" << it->first << " " << it->second << ">" << std::endl;
	// std::cout << std::endl;
	sortlistRec(_list);
	binaryInsert(_list, pairs);
	return ;

}

static void	createPairs(std::list<int> &_list, std::list<std::pair<int, int> > &pairs)
{
	int			swp;
	std::size_t	i = 0;
	std::size_t	size = _list.size();

	if (size % 2 == 1)
	{
		pairs.push_back(std::pair<int, int>(-1, _list.back()));
		_list.pop_back();
		--size;
	}
	while (i < size / 2)
	{
		if (_list[i] < _list[i + (size / 2)])
		{
			swp = _list[i];
			_list[i] = _list[i + (size / 2)];
			_list[i + (size / 2)] = swp;
		}
		pairs.push_back(std::pair<int, int>(_list[i], _list[i + (size / 2)]));
		++i;
	}
	i = size / 2;
	while (i++ < size)
		_list.pop_back();
}

static void	binaryInsert(std::list<int> &_list, std::list<std::pair<int, int> > &pairs)
{
	std::list<std::pair<int, int> >	insertPairs;
	std::list<std::pair<int, int> >::iterator	pair;

	// insert first element
	pair = findPairValue(pairs, _list.front());
	_list.insert(_list.begin(), pair->second);
	pairs.erase(pair);

	buildInsertionOrder(_list, pairs, insertPairs);
	
	while (insertPairs.size() > 0)
	{
		if (insertPairs.front().first == -1)
			_list.insert(std::lower_bound(_list.begin(), _list.end(), insertPairs.front().second), insertPairs.front().second);
		else
			_list.insert(std::lower_bound(_list.begin(), std::find(_list.begin(), _list.end(), insertPairs.front().first), insertPairs.front().second), insertPairs.front().second);
		insertPairs.erase(insertPairs.begin());
	}
}

static void	buildInsertionOrder(std::list<int> &_list, \
	std::list<std::pair<int, int> > &pairs, std::list<std::pair<int, int> > &insertPairs)
{
	std::list<std::pair<int, int> >::iterator	pair;
	std::list<int>	jacobsSteps;

	calculateJacobsSteps(_list, jacobsSteps);
	for (std::list<int>::iterator j = jacobsSteps.begin(); j != jacobsSteps.end(); ++j)
	{
		for (std::list<int>::iterator it = std::find(_list.begin(), _list.end(), *j); it != _list.begin(); --it)
		{
			pair = findPairValue(pairs, *it);
			if (pair == pairs.end())
				continue ;
			insertPairs.push_back(*pair);
			pairs.erase(pair);
		}
	}
	pair = findPairValue(pairs, -1);
	if (pair != pairs.end())
	{
		insertPairs.push_back(*pair);
		pairs.erase(pair);
	}
}

static void	calculateJacobsSteps(std::list<int> &_list, std::list<int> &steps)
{
	std::size_t	jacob;
	int			i = 3;

	while (true)
	{
		jacob = jacobsthal(i++);
		if (jacob > _list.size() - 1)
		{
			steps.push_back(_list.back());
			break ;
		}
		steps.push_back(_list[jacob - 1]);
	}
}

static std::list<std::pair<int, int> >::iterator	findPairValue(std::list<std::pair<int, int> > &pairs, int value)
{
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first == value)
			return (it);
	}
	return (pairs.end());
}

static void	createlist(int argc, char *argv[], std::list<int> &_list)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		_list.push_back(std::atoi(argv[i]));
		++i;
	}
	return ;
}
