/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Acccount.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:29:04 by feberman          #+#    #+#             */
/*   Updated: 2024/02/27 09:59:54 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account( int initial_deposit ): 
_amount(initial_deposit), _accountIndex(Account::_nbAccounts)
{
	this->_nbDeposits = _nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << 
		";amount:" << this->_amount << ";created" << std::endl;
	return ;
}
Account::~Account( void )
{
	std::cout << "index:" << this->_accountIndex << 
		";amount:" << this->_amount << ";closed" << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	
}
bool	Account::makeWithdrawal( int withdrawal )
{
	
}
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}
void	Account::displayStatus( void ) const
{
	
}

void	Account::_displayTimestamp( void )
{
	tm		*now;
	time_t	now_t;

	now_t = time(NULL);
	now = localtime(&now_t);
	std::cout << "[" << now->tm_year << now->tm_mon << now->tm_yday << "_"
		<< now->tm_hour << now->tm_min << now->tm_sec << "]";
	return ;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
	return ;
}
