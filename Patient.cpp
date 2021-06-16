#include "Patient.h"
#include "AlphaCorona.h"
#include "BetaCorona.h"

Patient() {
	doStart();
	initResistance();
}
~Patient() {
	doDie();
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
			AlphaCorona* alpha;
			_virusList.push_back(alpha);
		};
		if ((rand() % 2 + 1) == 2)
		{
			BetaCorona* beta;
			_virusList.push_back(beta);
		};
	}
	_state = "ALIVE";
}

void Patient::initResistance() {
	_presistance = rand() % 9000 + 1000;
}
void Patient::takeMedicine() {
	list <Coronavirus*>::iterator it = _virusList.begin();
	list <Coronavirus*> list;
	while (it != _virusList.end()) {
		(*it)->reduceResistance(_presistance);
		if ((*it)->getResistance() <= 0) {
			_virusList.erase(it++);
		}
		else {
			list.merge((*it)->doClone((*it)));
		}
	}
	_virusList.merge(list);
	for (it = _virusList.begin(); it != _virusList.end(); ++it) {
		_presistance -= (*it)->getResistance();
		if (_presistance <= 0) {
			doDie();
			break;
		}
	}
}
