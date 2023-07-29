#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"


class OrdinaryEmployee :public Worker {
public:
	OrdinaryEmployee(int ID, string Name, int Post);
	~OrdinaryEmployee();
	void ShowInfo();
	string GetDepartName();


};
