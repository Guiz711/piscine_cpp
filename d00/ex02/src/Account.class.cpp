/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:15:18 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/07 18:52:39 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include "Account.class.hpp"

// int				_accountIndex;
// int				_amount;
// int				_nbDeposits;
// int				_nbWithdrawals;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _accountIndex(Account::_nbAccounts)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{

}

/*
** Non Members
*/

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
		<< ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now;
	struct tm	timestruct;
	char		buff[19];

	now = std::time(NULL);
	timestruct = *localtime(&now);
	std::strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S] ", &timestruct);
	std::cout << buff;
}

/*
** Members
*/

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void )
{
	return 0;
}

int	Account::getTotalAmount( void )
{
	return 0;
}

int	Account::getNbDeposits( void )
{
	return 0;
}

int	Account::getNbWithdrawals( void )
{
	return 0;
}



void	Account::makeDeposit( int deposit )
{

}

bool	Account::makeWithdrawal( int withdrawal )
{
	return true;
}

int		Account::checkAmount( void ) const
{
	return 0;
}
