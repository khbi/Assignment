#define __PRAC2_H__

#include<iostream>
using namespace std;


class Printer {
private:
	char name[50];

public:
	void SetString(const char *str);
	void ShowString();
};