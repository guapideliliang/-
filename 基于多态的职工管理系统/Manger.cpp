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
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->GetDepartName()
		<< "\tְ������ϰ�����񣬸���ְͨ����������" << endl;
}

string Manger::GetDepartName()
{
	return string("����");
}
