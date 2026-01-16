/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:53:11 by alermi            #+#    #+#             */
/*   Updated: 2025/10/16 20:08:06 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() 
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	if (deposit <= 0)
		return;
	
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal <= 0 || withdrawal > this->_amount)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << this->_amount
				  << ";withdrawal:refused" << std::endl;
		return false;
	}
	
	int p_amount = this->_amount;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << p_amount
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << this->_amount
			  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(0);
	std::tm		*ltm = std::localtime(&now);
	
	std::cout << "[" << (1900 + ltm->tm_year)
			  << std::setfill('0') << std::setw(2) << (1 + ltm->tm_mon)
			  << std::setfill('0') << std::setw(2) << ltm->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << ltm->tm_hour
			  << std::setfill('0') << std::setw(2) << ltm->tm_min
			  << std::setfill('0') << std::setw(2) << ltm->tm_sec
			  << "] ";
}

