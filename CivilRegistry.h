#include "Citizen.h"
#include <list>

class CivilRegistry {
	std::list <Citizen*> wApp;
	std::list <Citizen*> wOutApp;
public:
	CivilRegistry();
	void insertCitizen(Citizen*);
	void removeCitizen(int listSel);
};