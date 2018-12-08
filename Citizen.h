#include "Time.h"

class Citizen {
	char *idNo, *name, *surname, *appSlot;
	bool hasApp;
	Time *appTime;

public:
	Citizen(char* givenId, char* givenName, char* givenSurname, char* givenAppSlot, Time* givenAppTime, bool givenHasApp);
	~Citizen();
	bool getHasApp() const;
	int getAppSlot() const;
	std::string getName() const;
	Time getAppTime() const;
};