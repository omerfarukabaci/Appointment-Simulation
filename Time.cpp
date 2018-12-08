#include "Time.h"
#include <iostream>
#include <string>

Time::Time(const int givenDay, const int givenMonth, const int givenYear, const int givenHour, const int givenMinute) {
	day = givenDay;
	month = givenMonth;
	year = givenYear;
	hour = givenHour;
	minute = givenMinute;
}

std::string Time::getTime() const {
	return std::to_string(hour) + "." + std::to_string(minute) + std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);;
}

bool Time::operator<(const Time &operand) {
	if (year < operand.year)
		return true;
	else if (year > operand.year)
		return false;

	if (month < operand.month)
		return true;
	else if (month > operand.month)
		return false;

	if (day < operand.day)
		return true;
	else if (day > operand.day)
		return false;

	if (hour < operand.hour)
		return true;
	else if (hour > operand.hour)
		return false;

	if (minute < operand.minute)
		return true;
	else if (minute > operand.minute)
		return false;

	return true;
}

bool Time::operator>(const Time &operand) {
	if (year > operand.year)
		return true;
	else if (year < operand.year)
		return false;

	if (month > operand.month)
		return true;
	else if (month < operand.month)
		return false;

	if (day > operand.day)
		return true;
	else if (day < operand.day)
		return false;

	if (hour > operand.hour)
		return true;
	else if (hour < operand.hour)
		return false;

	if (minute > operand.minute)
		return true;
	else if (minute < operand.minute)
		return false;

	return true;
}

bool Time::operator==(const Time &operand) {
	return (year == operand.year && month == operand.month && day == operand.day && hour == operand.hour && minute == operand.minute);
}