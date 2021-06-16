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
Coronavirus::Coronavirus(const Coronavirus& crn) {
	_dna = crn._dna; _resistance = crn._resistance;
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
void Coronavirus::reduceResistance(int _iMedicineResistance) {
	_resistance -= _iMedicineResistance;
}
