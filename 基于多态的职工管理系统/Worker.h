#pragma once
#include <iostream>
using namespace std; 
#include <string>

class Worker {

public:

	virtual void ShowInfo() = 0;//��ʾ������Ϣ
	virtual string GetDepartName() = 0;//��ȡ��������
	int m_ID;//ְ�����
	string m_Name;//ְ������
	int m_Post;//���ű��


};
