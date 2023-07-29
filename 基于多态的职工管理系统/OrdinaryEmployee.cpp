#define _CRT_SECURE_NO_WARNINGS 1
#include "OrdinaryEmployee.h"




void OrdinaryEmployee::ShowInfo() {
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->GetDepartName()
		<< "\t职责：完成经理交给的任务" << endl;
}

string OrdinaryEmployee::GetDepartName() {
	return string("普通职工");
}

OrdinaryEmployee::OrdinaryEmployee(int ID, string Name, int Post)
{
	m_ID = ID;
	m_Name = Name;
	m_Post = Post;
}

OrdinaryEmployee::~OrdinaryEmployee() {

}