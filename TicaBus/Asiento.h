#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Asiento {
private:
	string cedula;
public:
	Asiento();
	Asiento(string cedula);
	virtual ~Asiento();
	string getCedula();
	void setCedula(string cedula);
	string toString();
};
};