#define _CRT_SECURE_NO_WARNINGS 1
#include "OrdinaryEmployee.h"




void OrdinaryEmployee::ShowInfo() {
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->GetDepartName()
		<< "\tְ����ɾ�����������" << endl;
}

string OrdinaryEmployee::GetDepartName() {
	return string("��ְͨ��");
}

OrdinaryEmployee::OrdinaryEmployee(int ID, string Name, int Post)
{
	m_ID = ID;
	m_Name = Name;
	m_Post = Post;
}

OrdinaryEmployee::~OrdinaryEmployee() {

}