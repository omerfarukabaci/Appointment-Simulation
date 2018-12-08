#include "Citizen.h"
#include <string>

Citizen::Citizen(char* givenId, char* givenName, char* givenSurname, char* givenAppSlot, Time* givenAppTime, bool givenHasApp) {
	idNo = givenId;
	name = givenName;
	surname = givenSurname;
	appSlot = givenAppSlot;
	appTime = givenAppTime;
	hasApp = givenHasApp;
}

Time Citizen::getAppTime() const{
	return *appTime;
}

bool Citizen::getHasApp() const{
	return hasApp;
}

int Citizen::getAppSlot() const {
	std::string myString = appSlot;
	int pos;
	pos = myString.find(".");
	myString.erase(pos, 1);
	pos = myString.find("-");
	myString.erase(pos, 1);
	pos = myString.find(".");
	myString.erase(pos, 1);

	return stoi(myString);//it returns a number, like 800830 for 8.00-8.30, and it is enough to compare two time slots
}

std::string Citizen::getName() const {
	return name;
}

Citizen::~Citizen() {
	delete []idNo;
	delete []name;
	delete []surname;
	delete []appSlot;
	delete appTime;
}