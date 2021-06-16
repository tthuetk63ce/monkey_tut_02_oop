#include "Patient.h"
#include "AlphaCorona.h"
#include "BetaCorona.h"

Patient::Patient() {
	Patient::doStart();
}
Patient::~Patient() {
	Patient::doDie();
};

string Patient::getState() {
	return _state;
}

void Patient::doDie() {
	list <Coronavirus*>::iterator it;
	for (it = _virusList.begin(); it != _virusList.end(); ++it) {
		delete* it;
		*it = NULL;
	}
	_virusList.clear();
	_state = DIE;
}
void Patient::doStart(){
	for (int i = 0;i < rand() % 20 + 10;++i) {
		if ((rand() % 2 + 1) == 1)
		{	
			AlphaCorona* Alpha;
			_virusList.push_back(Alpha);
		};
		if ((rand() % 2 + 1) == 2)
		{
			BetaCorona* Beta;
			_virusList.push_back(Beta);
		};
	}
	_state = "ALIVE";
}

void Patient::initResistance() {
	_Presistance = rand() % 9000 + 1000;
}
void Patient::takeMedicine() {
	list <Coronavirus*>::iterator it = _virusList.begin();
	list <Coronavirus*> list;
	while (it != _virusList.end()) {
		(*it)->reduceResistance(_Presistance);
		if ((*it)->getResistance() <= 0) {
			_virusList.erase(it++);
		}
		else {
			list.merge((*it)->doClone((*it)));
		}
	}
	_virusList.merge(list);
	for (it = _virusList.begin(); it != _virusList.end(); ++it) {
		_Presistance -= (*it)->getResistance();
		if (_Presistance <= 0) {
			doDie();
			break;
		}
	}
}