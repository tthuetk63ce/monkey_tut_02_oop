#ifndef __PATIENT_H__
#define __PATIENT_H__
#include "Coronavirus.h"
class Patient
{
public:
	Patient();
	~Patient();
	void initResistance() {};
	void doStart();
	void takeMedicine();
	void doDie();
	string getState();
protected:
	int _presistance;
	list <Coronavirus*> _virusList;
	enum _mState { DIE, LIVE };
	string _state;
};


#endif //__PATIENT_H__
