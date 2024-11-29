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
#include <iterator>

static void	createList(int argc, char *argv[], std::list<int> &_list);
static void	printList(std::list<int> &_list, const char *prefix);
static void	sortListRec(std::list<int> &_list);
static void	binaryInsert(std::list<int> &_list, std::list<std::pair<int, int> > &pairs);
static std::list<std::pair<int, int> >::iterator	findPairValue(std::list<std::pair<int, int> > &pairs, int value);
static void	createPairs(std::list<int> &_list, std::list<std::pair<int, int> > &pairs);
static void	calculateJacobsSteps(std::list<int> &_list, std::list<int> &steps);
static void	buildInsertionOrder(std::list<int> &_list, \
	std::list<std::pair<int, int> > &pairs, std::list<std::pair<int, int> > &insertPairs);

void	sortList(int argc, char *argv[], bool print)
{
	std::list<int>	_list;

	createList(argc, argv, _list);
	if (print)
		printList(_list, "Before:\t");
	sortListRec(_list);
	if (print)
		printList(_list, "After:\t");
}

static void	printList(std::list<int> &_list, const char *prefix)
{
	std::cout << prefix;
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static void	sortListRec(std::list<int> &_list)
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
	sortListRec(_list);
	binaryInsert(_list, pairs);
	return ;

}

static void	createPairs(std::list<int> &_list, std::list<std::pair<int, int> > &pairs)
{
	int			swp;
	std::size_t	i = 0;
	std::size_t	size = _list.size();
	std::list<int>::iterator	itf = _list.begin();
	std::list<int>::iterator	itb = itf;

	std::advance(itb, size / 2);

	if (size % 2 == 1)
	{
		pairs.push_back(std::pair<int, int>(-1, _list.back()));
		_list.pop_back();
		--size;
	}
	while (i < size / 2)
	{
		if (*itf < *itb)
		{
			swp = *itf;
			*itf = *itb;
			*itb = swp;
		}
		pairs.push_back(std::pair<int, int>(*itf, *itb));
		++i;
		std::advance(itf, 1);
		std::advance(itb, 1);
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
	std::size_t					jacob;
	int							i = 3;
	std::list<int>::iterator	it;

	while (true)
	{
		jacob = jacobsthal(i++);
		if (jacob > _list.size() - 1)
		{
			steps.push_back(_list.back());
			break ;
		}
		it = _list.begin();
		std::advance(it, jacob);
		steps.push_back(*it);
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

static void	createList(int argc, char *argv[], std::list<int> &_list)
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
