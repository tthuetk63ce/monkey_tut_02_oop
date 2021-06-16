
#include "AlphaCorona.h"

AlphaCorona::AlphaCorona() {
	AlphaCorona::doBorn();
	AlphaCorona::initResistance();
}
AlphaCorona::AlphaCorona(string dna, int resistance, string color) {
	_dna = dna;
	_resistance = resistance;
	_color = color;
}
AlphaCorona::~AlphaCorona() {
	doDie();
}
void AlphaCorona::doBorn() {
	loadADNInformation();
	if (m_color(rand() % 2) == 0) { _color = "blue"; }
	if (m_color(rand() % 2) == 1) { _color = "red"; }
}
void AlphaCorona::initResistance() {
	if (_color == "blue") _resistance = rand() % 20 + 10;
	if (_color == "red") _resistance = rand() % 15 + 10;
};
void AlphaCorona::doDie() {
	_dna = "";
	_resistance = 0;
	_color = "";
}
list <Coronavirus*> AlphaCorona::doClone(AlphaCorona* Al) {
	_listAlphaCrn.push_back(Al);
	return _listAlphaCrn;
}

