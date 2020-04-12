#define __PRACINLINE_H__

#include <iostream>
using namespace std;


class Calculator {
private:
	int AddCount;
	int MinusCount;
	int MultiplyCount;
	int DivideCount;

public:
	void Init();
	double Add(double, double);
	double Min(double, double);
	double Mul(double, double);
	double Div(double, double);
	void ShowOpCount();

};



