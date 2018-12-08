#include <string>

class Time {
	int day, month, year, hour, minute;
public:
	Time(const int givenDay, const int givenMonth, const int givenYear, const int givenHour, const int givenMinute);
	std::string getTime() const;
	bool operator<(const Time &);
	bool operator>(const Time &);
	bool operator==(const Time &);
};