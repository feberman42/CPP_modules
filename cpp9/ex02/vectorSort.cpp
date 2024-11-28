/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:31:30 by feberman          #+#    #+#             */
/*   Updated: 2024/11/28 19:08:30 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "pmergeMe.h"

static void	createVector(int argc, char *argv[], std::vector<int> &vec);
static void	printVector(std::vector<int> &vec, const char *prefix);
static void	sortVectorRec(std::vector<int> &vec);
static void	binaryInsert(std::vector<int> &vec, std::vector<std::pair<int, int> > &pairs);
static std::vector<std::pair<int, int> >::iterator	findPairValue(std::vector<std::pair<int, int> > &pairs, int value);
static void	createPairs(std::vector<int> &vec, std::vector<std::pair<int, int> > &pairs);
static void	calculateJacobsSteps(std::vector<int> &vec, std::vector<int> &steps);
static void	buildInsertionOrder(std::vector<int> &vec, \
	std::vector<std::pair<int, int> > &pairs, std::vector<std::pair<int, int> > &insertPairs);

void	sortVector(int argc, char *argv[], bool print)
{
	std::vector<int>	vec;

	createVector(argc, argv, vec);
	if (print)
		printVector(vec, "Before:\t");
	sortVectorRec(vec);
	if (print)
		printVector(vec, "After:\t");
}

static void	printVector(std::vector<int> &vec, const char *prefix)
{
	std::cout << prefix;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static void	sortVectorRec(std::vector<int> &vec)
{
	std::vector<std::pair<int, int> >	pairs;
	

	if (vec.size() == 1)
		return ;
	
	createPairs(vec, pairs);
	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	// 	std::cout << "<" << it->first << " " << it->second << ">" << std::endl;
	// std::cout << std::endl;
	sortVectorRec(vec);
	binaryInsert(vec, pairs);
	return ;

}

static void	createPairs(std::vector<int> &vec, std::vector<std::pair<int, int> > &pairs)
{
	int			swp;
	std::size_t	i = 0;
	std::size_t	size = vec.size();

	if (size % 2 == 1)
	{
		pairs.push_back(std::pair<int, int>(-1, *(vec.end() - 1)));
		vec.erase(vec.end() - 1);
		--size;
	}
	while (i < size / 2)
	{
		if (vec[i] < vec[i + (size / 2)])
		{
			swp = vec[i];
			vec[i] = vec[i + (size / 2)];
			vec[i + (size / 2)] = swp;
		}
		pairs.push_back(std::pair<int, int>(vec[i], vec[i + (size / 2)]));
		++i;
	}
	i = size / 2;
	while (i++ < size)
		vec.erase(vec.end() - 1);
}

static void	binaryInsert(std::vector<int> &vec, std::vector<std::pair<int, int> > &pairs)
{
	std::vector<std::pair<int, int> >	insertPairs;
	std::vector<std::pair<int, int> >::iterator	pair;

	// insert first element
	pair = findPairValue(pairs, vec[0]);
	vec.insert(vec.begin(), pair->second);
	pairs.erase(pair);

	buildInsertionOrder(vec, pairs, insertPairs);
	
	while (insertPairs.size() > 0)
	{
		if (insertPairs[0].first == -1)
			vec.insert(std::lower_bound(vec.begin(), vec.end(), insertPairs[0].second), insertPairs[0].second);
		else
			vec.insert(std::lower_bound(vec.begin(), std::find(vec.begin(), vec.end(), insertPairs[0].first), insertPairs[0].second), insertPairs[0].second);
		insertPairs.erase(insertPairs.begin());
	}
}

static void	buildInsertionOrder(std::vector<int> &vec, \
	std::vector<std::pair<int, int> > &pairs, std::vector<std::pair<int, int> > &insertPairs)
{
	std::vector<std::pair<int, int> >::iterator	pair;
	std::vector<int>	jacobsSteps;

	calculateJacobsSteps(vec, jacobsSteps);
	for (std::vector<int>::iterator j = jacobsSteps.begin(); j != jacobsSteps.end(); ++j)
	{
		for (std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), *j); it != vec.begin(); --it)
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

static void	calculateJacobsSteps(std::vector<int> &vec, std::vector<int> &steps)
{
	std::size_t	jacob;
	int			i = 3;

	while (true)
	{
		jacob = jacobsthal(i++);
		if (jacob > vec.size() - 1)
		{
			steps.push_back(vec[vec.size() - 1]);
			break ;
		}
		steps.push_back(vec[jacob - 1]);
	}
}

static std::vector<std::pair<int, int> >::iterator	findPairValue(std::vector<std::pair<int, int> > &pairs, int value)
{
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first == value)
			return (it);
	}
	return (pairs.end());
}

static void	createVector(int argc, char *argv[], std::vector<int> &vec)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		vec.push_back(std::atoi(argv[i]));
		++i;
	}
	return ;
}
