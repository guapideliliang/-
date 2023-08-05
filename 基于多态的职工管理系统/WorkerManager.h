#pragma once//防止头文件重复包含
#include <iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include<string>
#include<fstream>
#include"Worker.h"
#include"Boss.h"
#include"Manger.h"
#include"OrdinaryEmployee.h"
#define FILENAME "worker.txt"//存储文件名
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
	//查看职工
	void ShowWorker();
	//职工总数
	int m_WorkerNum;
	//初始化职工
	void m_InitWorker();
	//该职工是否存在。返回在数组中的位置
	int IsExist(int id);
	//修改信息
	void Mod_Worker();
	//删除职工
	void DeleWorker();
	//查找职工
	void Find_Worker();
	//将职工按编号排序
	void Sort();
	//清空文件
	void Clean_File();
	//获取文件中的人数
	int m_GetNum();
	//表示文件的状态，ture为空
	bool m_WorkerFileEmpty;
	//将数据保存到文件中
	void Save();
	//职工数组指针
	Worker** m_WorkerArray;
	//添加职工
	void Add_Worker();
};


