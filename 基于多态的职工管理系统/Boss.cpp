#include "Boss.h"

Boss::Boss(int ID, string Name, int Post)
{
	m_ID = ID;
	m_Name = Name;
	m_Post = Post;
}

void Boss::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->GetDepartName()
		<< "\tְ�𣺹���˾��������" << endl;
}

string Boss::GetDepartName()
{
    return string("�ϰ�");
}
