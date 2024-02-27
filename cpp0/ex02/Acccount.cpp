/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Acccount.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:29:04 by feberman          #+#    #+#             */
/*   Updated: 2024/02/25 15:48:11 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

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