/*
Student Name: Ömer Faruk ABACI
Student Number: 150150037

Homework #1 of Object Oriented Programming Class
*/

#include <iostream>
#include <string>
#include <fstream>
#include "CivilRegistry.h"
#include <vector>

using namespace std;

void readFile(vector<Citizen*> &, vector<Citizen*> &);
void sortLists(vector<Citizen*> &, vector<Citizen*> &);

int main() {
	vector <Citizen*> wApp, wOutApp;
	int wAppCounter = 0, wOutAppCounter = 0;
	CivilRegistry civilRegistry;

	readFile(wApp, wOutApp);
	sortLists(wApp, wOutApp);

	wAppCounter = wApp.size();
	wOutAppCounter = wOutApp.size();

	for (int i = 0; !wApp.empty(); i++) {//put all citizens back into wApp list in civilRegistry object, in order
		civilRegistry.insertCitizen(wApp[0]);
		wApp.erase(wApp.begin());//erase handles the deallocation, uses objects destructor
	}
	wApp.clear();

	for (int i = 0; !wOutApp.empty(); i++) {//put all citizens back into wOutApp list in civilRegistry object, in order
		civilRegistry.insertCitizen(wOutApp[0]);
		wOutApp.erase(wOutApp.begin());;//erase handles the deallocation, uses objects destructor
	}
	wOutApp.clear();

	cout << "Citizens with an appointment:" << endl;
	for(int i = 0; i < wAppCounter; i++)
		civilRegistry.removeCitizen(0);

	cout << endl << "Citizens without an appointment:" << endl;
	for (int i = 0; i < wOutAppCounter; i++)
		civilRegistry.removeCitizen(1);

	getchar();
	return 0;
}

void readFile(vector<Citizen*> & wApp, vector<Citizen*> & wOutApp) {
	ifstream infile;
	string dataFromFile, appTimeDate, appTimeClock;
	Citizen *takenCitizen;
	char *id, *name, *surname, *appSlot;
	int day, month, year, hour, minute;
	bool hasApp;
	Time *appTime;

	infile.open("input.txt");

	for (int i = 0; i < 7; i++)
		infile >> dataFromFile;//skipping garbage values

	while (!infile.eof()) {
		infile >> dataFromFile;
		id = new char[dataFromFile.length()];
		strcpy(id, dataFromFile.c_str());

		infile >> dataFromFile;
		name = new char[dataFromFile.length()];
		strcpy(name, dataFromFile.c_str());

		infile >> dataFromFile;
		surname = new char[dataFromFile.length()];
		strcpy(surname, dataFromFile.c_str());

		infile >> dataFromFile;
		if (dataFromFile == "TRUE")
			hasApp = true;
		else
			hasApp = false;

		infile >> appTimeDate;//reading appDate
		int pos;//position number that we will need while parsing
		pos = appTimeDate.find("-");//returns position of the first occurence of "-"
		day = stoi(appTimeDate.substr(0, pos));//take the substring before "-"
		appTimeDate.erase(0, pos + 1);//delete the substring and "-"
		pos = appTimeDate.find("-");//do the things above again
		month = stoi(appTimeDate.substr(0, pos));
		appTimeDate.erase(0, pos + 1);
		year = stoi(appTimeDate);//only year left at the end

		infile >> dataFromFile;
		if (dataFromFile != "-") {
			appSlot = new char[dataFromFile.length()];
			strcpy(appSlot, dataFromFile.c_str());
		}
		else
			appSlot = NULL;


		infile >> appTimeClock;
		pos = appTimeClock.find(".");
		hour = stoi(appTimeClock.substr(0, pos));
		appTimeClock.erase(0, pos + 1);
		minute = stoi(appTimeClock);

		appTime = new Time(day, month, year, hour, minute);
		takenCitizen = new Citizen(id, name, surname, appSlot, appTime, hasApp);

		if (takenCitizen->getHasApp())//if has application
			wApp.push_back(takenCitizen);
		else
			wOutApp.push_back(takenCitizen);
	}


	infile.close();

}

void sortLists(vector<Citizen*> & wApp, vector<Citizen*> & wOutApp) {
	Citizen *temp;
	vector<Citizen*> tempSorted;
	int min_index;

	for (unsigned int i = 0; i < wApp.size() - 1; i++) {//selection sort of wApp list by appTime
		min_index = i;
		for (unsigned int j = i + 1; j < wApp.size(); j++) {
			if (wApp[j]->getAppTime() < wApp[min_index]->getAppTime())
				min_index = j;
		}
		temp = wApp[i];
		wApp[i] = wApp[min_index];
		wApp[min_index] = temp;
	}


	while (!wApp.empty()) {//find minimum AppSlot, put it into sorted list, delete it from wApp list
		min_index = 0;
		for (unsigned int i = 0; i < wApp.size(); i++) {
			if (wApp[i]->getAppSlot() < wApp[min_index]->getAppSlot())
				min_index = i;
		}
		tempSorted.push_back(wApp[min_index]);
		wApp.erase(wApp.begin() + min_index);
	}

	for (int i = 0; !tempSorted.empty(); i++) {//put all citizens back into wApp list in order
		wApp.push_back(tempSorted[0]);
		tempSorted.erase(tempSorted.begin());
	}


	for (unsigned int i = 0; i < wOutApp.size() - 1; i++) {//selection sort of wOutApp list by appTime
		min_index = i;
		for (unsigned int j = i + 1; j < wOutApp.size(); j++) {
			if (wOutApp[j]->getAppTime() < wOutApp[min_index]->getAppTime())
				min_index = j;
		}
		temp = wOutApp[i];
		wOutApp[i] = wOutApp[min_index];
		wOutApp[min_index] = temp;
	}
}