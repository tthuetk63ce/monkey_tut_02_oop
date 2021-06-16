#ifndef __CORONAVIRUS_H__
#define __CORONAVIRUS_H__
#include <iostream>
#include <fstream>
#include <list>
using namespace std;
class Coronavirus {
protected:
	string _dna;
	int _resistance;
public:
	Coronavirus(string dna, int resistance) {};
	Coronavirus() {};
	~Coronavirus() {};
	Coronavirus(const Coronavirus& Crn) { };

	void loadADNInformation() {};
	void reduceResistance(int i_medicineResistance) {};
	int getResistance();
	virtual void doBorn() = 0;
	virtual list<Coronavirus*> doClone(Coronavirus* Crn) = 0;
	virtual void doDie() = 0;
	virtual void initResistance() = 0;

};

#endif // __CORONAVIRUS_H__

