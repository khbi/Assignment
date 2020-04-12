#include "PracInline.h"
using namespace std;

void Calculator::Init() {
	AddCount = 0;
	MinusCount = 0;
	MultiplyCount = 0;
	DivideCount = 0;
}

void Calculator::ShowOpCount() {
	cout << "덧셈: " << AddCount << " 뺄셈: " << MinusCount << " 곱셈: " << MultiplyCount << " 나눗셈: " << DivideCount << endl;
}

double Calculator::Add(double num1, double num2) {
	AddCount++;
	return num1 + num2;
}

double Calculator::Min(double num1, double num2) {
	MinusCount++;
	return num1 - num2;
}

double Calculator::Mul(double num1, double num2) {
	MultiplyCount++;
	return num1 * num2;
}

double Calculator::Div(double num1, double num2) {
	DivideCount++;
	return num1 / num2;
}