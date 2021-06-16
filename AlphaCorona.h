#ifndef __ALPHA_CORONA_H__
#define __ALPHA_CORONA_H__
#include "Coronavirus.h"

class AlphaCorona :public Coronavirus
{
public:
	AlphaCorona();
	~AlphaCorona();
	AlphaCorona(string dna, int resistance, string color) {};
	void doBorn();
	void doDie();
	void initResistance();
	list<Coronavirus*> doClone(AlphaCorona* Al);

protected:
	enum m_color { blue, red };
	string _color;
	list<Coronavirus*> _listAlphaCrn;
	AlphaCorona* Alpha;
};







#endif // __ALPHA_CORONA_H__





