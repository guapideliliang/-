#include "Manger.h"
Manger::Manger(int ID,string Name,int Post)
{
	m_ID = ID;
	m_Name = Name;
	m_Post = Post;
}

Manger::~Manger()
{
}

void Manger::ShowInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->GetDepartName()
		<< "\t职责：完成老板的任务，给普通职工发布任务" << endl;
}

string Manger::GetDepartName()
{
	return string("经理");
}
