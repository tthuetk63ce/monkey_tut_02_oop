#ifndef __BETA_CORONA_H__
#define __BETA_CORONA_H__

#include "Coronavirus.h"


class BetaCorona :public Coronavirus 
{
public:
	BetaCorona();
	~BetaCorona();
	BetaCorona(string dna, int resistance, string color);
	void doBorn();
	void doDie();
	void initResistance();
	list<Coronavirus*> doClone(BetaCorona *Beta);
protected:
	enum _mProtein { NS3, NS5, E };
	string _protein;
	list<Coronavirus*> _listBetaCrn;

};

#endif //__BETA_CORONA_H__