
#include <iostream>
using namespace std;
#include"WorkerManager.h"
#include"Worker.h"
#include"OrdinaryEmployee.h"
#include"Manger.h"
#include"Boss.h"


int main() {

	//Worker* a = NULL;//不声明NULL，如果new失败，a会变成野指针，访问野指针有程序崩溃的风险
	//a=	new Boss(1, "张三",2);
	//a->ShowInfo();
	//delete a;
	WorkerManager a;
	int select = 0;
	while (true)
	{
		a.Show_Menu();//展示菜单
		cout<<"请输入你的选择" << endl;
		cin >> select;
		switch (select) {
		case 0: a.ExitSystem(); break;//退出系统
		case 1: a.Add_Worker(); break;//添加职工
		case 2: a.ShowWorker(); break;//显示职工
		case 3: a.DeleWorker(); break;//删除职工
		case 4:  a.Mod_Worker(); break;//修改职工
		case 5:  a.Find_Worker(); break;//查找职工
		case 6:  a.Sort(); break;//按照编号排序
		case 7:  a.Clean_File(); break;//清空所有文档
		default: 
			system("cls");
			break;//清屏

		}

	}system("pause");
	return 0;
}

