#include "Coronavirus.h"


Coronavirus::Coronavirus(string dna, int resistance) {
	_dna = dna;
	_resistance = resistance;
};
Coronavirus::Coronavirus() {
	_dna = "";
	_resistance = 0;
};
Coronavirus::~Coronavirus() {
	_dna = ""; _resistance = 0;
};
int Coronavirus::getResistance() {
	return _resistance;
}
Coronavirus::Coronavirus(const Coronavirus& Crn) {
	_dna = Crn._dna; _resistance = Crn._resistance;
};
void Coronavirus::loadADNInformation() {
	ifstream input("E:/ATGX.bin");
	while (!input.eof()) {
		string s;
		input >> s;
		_dna += s;
	}
	input.close();
};
void Coronavirus::reduceResistance(int i_medicineResistance) {
	_resistance -= i_medicineResistance;
}
