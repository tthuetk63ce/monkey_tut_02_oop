#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class Coronavirus {
private:
	string m_dna;
	int m_resistance;
public:

	Coronavirus(string dna, int resistance) {
		m_dna = dna;
		m_resistance = resistance;
	}
	Coronavirus() {
		m_dna = "";
		m_resistance = 0;
	};
	~Coronavirus() { m_dna = ""; m_resistance = 0; };
	Coronavirus(const Coronavirus& Crn) { m_dna = Crn.m_dna; m_resistance = Crn.m_resistance; }
	void setDna(string newDna) { m_dna = newDna; }
	string getDna() { return m_dna; }
	void setResistance(int newResistance) { m_resistance = newResistance; }
	int getResistance() { return m_resistance; }
	
	void loadADNInformation() {
		string newDna;
		ifstream input("E:/ATGX.bin");
		while (!input.eof()) {
			string s;
			input >> s;
			newDna += s;
		}
		input.close();
		setDna(newDna);
	}
	int reduceResistance(int i_medicineResistance) {
		m_resistance = m_resistance - i_medicineResistance;
		return m_resistance;
	}
	virtual void doBorn() = 0;
	virtual list<Coronavirus*> doClone() = 0;
	virtual void doDie() = 0;
	virtual void initResistance() = 0;
};
class AlphaCoronavirus : public Coronavirus {
protected:
	enum m_color { blue, red };
	string color;
public:
	void setColor(string newcolor) {
		color = newcolor;
	}
	string getColor() {
		return color;
	}
	AlphaCoronavirus() { doBorn(); };
	~AlphaCoronavirus() {
		doDie();
	};
	//AlphaCoronavirus(AlphaCoronavirus &alpha) { m_dna = alpha.m_dna; m_resistance = alpha.m_resistance; color = alpha.color; }
	void  doBorn() {
		loadADNInformation();
		if (m_color(rand() % 2) == 0) { setColor("blue");}
		if (m_color(rand() % 2) == 1) { setColor("red"); }
		initResistance();
	}

	list<Coronavirus*> doClone() {
		list<Coronavirus*> result;
		result.push_back(new AlphaCoronavirus());
		return result;
	}
	void doDie() {
		color = "";
	}
	void initResistance() {
		if (color == "blue") setResistance(rand() % 20 + 10);
		if (color == "red") setResistance(rand() % 15 + 10);
	}
};
class BetaCoronavirus : public Coronavirus {
private:
	enum m_protein { NS3, NS5, E };
	string protein;
public:

	void setProtein(string newProtein) {
		protein = newProtein;
	}
	string getProtein() {
		return protein;
	}
	BetaCoronavirus() { doBorn(); };
	~BetaCoronavirus() {
		doDie();
	};
	void doBorn() {
		loadADNInformation();
		if (m_protein(rand() % 2) == 0) setProtein("NS3");
		if (m_protein(rand() % 2) == 1) setProtein("NS5");
		if (m_protein(rand() % 2) == 2) setProtein("E");
		initResistance();
	}
	list <Coronavirus*> doClone() {
		list<Coronavirus*> result;
		result.push_back(new BetaCoronavirus());
		return result;
	};
	void doDie() {
		protein = "";
	};
	void initResistance() {
		if (protein == "NS3") setResistance(rand() % 10 + 1);
		if (protein == "NS5") setResistance(rand() % 20 + 11);
		if (protein == "NS5") setResistance(rand() % 30 + 21);
	}
};
class Patient {
private:
	int m_resistance;
	list <Coronavirus*> m_virusList;
	enum state { DIE, LIVE };
	string m_state;
public:
	void setM_resistance(int newResistance) {
		m_resistance = newResistance;
	}
	int getM_resistance() {
		return m_resistance;
	}
	void setState(string newState) {
		m_state = newState;
	}
	string getState() { return m_state; }
	void initResistance(int m_resistance) {
		m_resistance = rand() % 9000 + 1000;
	}
	Patient(int newResistance, string newState) {
		m_resistance = newResistance;
		m_state = newState;
	}
	~Patient() { doDie(); };

	void doStart() {
		for (int i = 0;i < rand() % 20 + 10;++i) {
			if ((rand() % 2 + 1) == 1) 
			{ 
				m_virusList.push_back(new AlphaCoronavirus());
			};
			if ((rand() % 2 + 1) == 2)
			{
				m_virusList.push_back(new BetaCoronavirus());
			};
		}
	}
	void takeMedicine() {
		list <Coronavirus*>::iterator it = m_virusList.begin();
		list <Coronavirus*> list;
		while (it != m_virusList.end()) {
			int i_medicineResistance = rand() % 60 + 1;
			(*it)->reduceResistance(i_medicineResistance);
			if ((*it)->getResistance() <= 0) {
				m_virusList.erase(it++);
			}
			else {
				list.merge((*it)->doClone());
			}
		}
		m_virusList.merge(list);
		for (it = m_virusList.begin(); it != m_virusList.end(); ++it) {
			m_resistance -= (*it)->getResistance();
			if (m_resistance <= 0) {
				doDie();
				break;
			}
		}
	}

	void doDie() {
		list <Coronavirus*>::iterator it;
		for (it = m_virusList.begin(); it != m_virusList.end(); ++it) {
			delete* it;
			*it = NULL;
		}
		m_virusList.clear();
		m_state = DIE;
	}
};
int main() {
	cout << "1";
}
