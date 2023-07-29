#pragma once//防止头文件重复包含
#include <iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include<string>
#include<fstream>
#include"Worker.h"
#include"Boss.h"
#include"Manger.h"
#include"OrdinaryEmployee.h"
class WorkerManager {
public:
	//构造函数
	WorkerManager();
	//展示菜单
	void Show_Menu();
	//退出系统
	void ExitSystem();
	//析构函数
	~WorkerManager();
	//职工总数
	int m_WorkerNum;
	//职工数组指针
	Worker** m_WorkerArray;
	//添加职工
	void Add_Worker();
};


