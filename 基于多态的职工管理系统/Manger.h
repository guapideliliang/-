#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

class Manger :public Worker {
public:
	Manger(int ID,string Name,int Post);
	~Manger();
	void ShowInfo();
	string GetDepartName();


};
