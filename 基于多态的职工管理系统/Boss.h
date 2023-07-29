#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

class Boss:public Worker
{
public:
	Boss(int ID, string Name, int Post);
	void ShowInfo();
	string GetDepartName();

};


