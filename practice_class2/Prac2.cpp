#include "Prac2.h"
using namespace std;

void Printer::SetString(const char *str) {
	strcpy_s(name, str);
}

void Printer::ShowString() {
	cout << name << endl;
}