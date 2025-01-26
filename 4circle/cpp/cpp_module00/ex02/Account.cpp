#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;	// 총 계좌 수
int Account::_totalAmount = 0;	//	모든 계좌의 총 금액
int Account::_totalNbDeposits = 0;	// 전체 입금 횟수
int Account::_totalNbWithdrawals = 0;	// 전체 출금 횟수

int	Account::getNbAccounts()	// 총 계좌 수 반환
{
	return (_nbAccounts);
}

int Account::getTotalAmount()	// 총 금액 반환
{
	return (_totalAmount);
}

int	Account::getNbDeposits()	// 총 입금 횟수 반환
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()	// 총 출금 횟수 반환
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount() const	// 현재 계좌 잔액 확인
{
	return (_amount);
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;	// 새 계좌에 순차적 번호 부여
	_amount = initial_deposit;	// 초기 입금액 설정
	_nbAccounts++;	// 총 계좌 수 증가
	_totalAmount += initial_deposit;	// 총 금액에 추가
	_nbDeposits = 0;	// 입금 횟수 초기화
	_nbWithdrawals = 0;	// 출금 횟수 초기화
	//	로그 출력
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount " << _amount << ";";
	std::cout << "created" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	//	입금 전 상태 출력
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";

	_amount += deposit;	// 계좌 잔액 증가
	_totalAmount +=deposit;	//	총 금액 증가
	_nbDeposits++;	//	계좌의 입금 횟수 증가
	_totalNbDeposits++;	// 전체 입금 횟수 증가
	//	입금 후 상태 출력
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	//	잔액 부족 체크
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}

	_amount -= withdrawal;	//	계좌 잔액 감소
	_totalAmount -= withdrawal;	// 총 금액 감소
	_nbWithdrawals++;	// 계좌의 출금 횟수 증가
	_totalNbWithdrawals++;	// 전체 출금 횟수 증가

	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals" << _nbWithdrawals << std::endl;
	return (true);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

//	시간 표시 기능
void	Account::_displayTimestamp()
{
	time_t	now;
	struct tm *ltm;
	char	buffer[18];

	time(&now);
	ltm = localtime(&now);
	strftime(buffer, 18, "[%Y%m%d_%H%M%S]", ltm);
	std::cout << buffer;
}
