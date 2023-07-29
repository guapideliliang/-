#pragma once
#include <iostream>
using namespace std; 
#include <string>

class Worker {

public:

	virtual void ShowInfo() = 0;//显示个人信息
	virtual string GetDepartName() = 0;//获取部门名称
	int m_ID;//职工编号
	string m_Name;//职工姓名
	int m_Post;//部门编号


};
