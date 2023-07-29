#include "Boss.h"

Boss::Boss(int ID, string Name, int Post)
{
	m_ID = ID;
	m_Name = Name;
	m_Post = Post;
}

void Boss::ShowInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->GetDepartName()
		<< "\t职责：管理公司所有事务" << endl;
}

string Boss::GetDepartName()
{
    return string("老板");
}
