#include "BetaCorona.h"

BetaCorona() {
	BetaCorona::doBorn();
	BetaCorona::initResistance();
};
~BetaCorona() {
	BetaCorona::doDie();
};
BetaCorona(string dna, int resistance, string protein) {
	_dna = dna;
	_resistance = resistance;
	_protein = protein;
}

void BetaCorona::doBorn() {
	Coronavirus::loadADNInformation();
	if (_mProtein(rand() % 2) == 0) _protein = "NS3";
	if (_mProtein(rand() % 2) == 1) _protein = "NS5";
	if (_mProtein(rand() % 2) == 2) _protein = "E";
}
void BetaCorona::initResistance() {
	if (_protein == "NS3") _resistance=rand() % 10 + 1;
	if (_protein == "NS5") _resistance = rand() % 20 + 11;
	if (_protein == "NS5") _resistance = rand() % 30 + 21;
}
void BetaCorona::doDie() {
	delete this;
}
list<Coronavirus*> BetaCorona::doClone(BetaCorona* Beta) {
	_listBetaCrn.push_back(Beta);
	_listBetaCrn.push_back(Beta);
	return _listBetaCrn;
}
