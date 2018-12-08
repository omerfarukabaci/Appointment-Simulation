#include "CivilRegistry.h"
#include <iostream>

CivilRegistry::CivilRegistry() {
	//there's no need to do anything in here.
}

void CivilRegistry::insertCitizen(Citizen *givenCitizen) {
	if (givenCitizen->getHasApp())
		wApp.push_back(givenCitizen);
	else
		wOutApp.push_back(givenCitizen);
}

void CivilRegistry::removeCitizen(int listSel) {
	if (listSel == 0) {
		std::cout << wApp.front()->getName() << std::endl;
		wApp.pop_front();
	}

	else if (listSel == 1) {
		std::cout << wOutApp.front()->getName() << std::endl;
		wOutApp.pop_front();
	}

	else
		return;
}