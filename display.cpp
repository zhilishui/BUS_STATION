#include"head.h"
#include"function.h"
 
#define NUM1 20
#define NUM2 60
 
 
 
int MainWindowSelect()				// * 主菜单
{
	int choice;
 
	Star();
	Space();
	Space();
	cout << "欢迎使用汽车站车票管理系统\n\n";
	Star();
	Space();
	Space();
	cout << "1.管理员登录\n\n";
	Space();
	Space();
	cout << "2.用户登录\n\n";
	Space();
	Space();
	cout << "3.退出系统\n\n";
	Star();
 
	// * 进行选择
	while (1)
	{
		cout << "请输入你要选择进行的操作：";
		cin >> choice;
 
		system("cls");
		return choice;
	}
}
 
 
int AdminWindowSelect()				// * 管理员菜单
{
	int choice;
 
	Star();
	Space();
	Space();
	cout << "欢迎进入管理员系统\n\n";
	Star();
	Space();
	Space();
	cout << "1.添加车次信息\n\n";
	Space();
	Space();
	cout << "2.浏览时刻表\n\n";
	Space();
	Space();
	cout << "3.车辆信息查询\n\n";
	Space();
	Space();
	cout << "4.删除车辆信息\n\n";
	Space();
	Space();
	cout << "5.返回上级菜单\n\n";
	Star();
 
	// * 进行选择
	while (1)
	{
		cout << "请输入你要选择进行的操作：";
		cin >> choice;
 
		system("cls");
		return choice;
	}
	return 0;
}
 
 
int PassagerWindowSelect()				// * 乘客菜单
{
	int choice;
 
	Star();
	Space();
	Space();
	cout << "欢迎进入乘客系统\n\n";
	Star();
	Space();
	Space();
	cout << "1.车辆信息查询\n\n";
	Space();
	Space();
	cout << "2.购票\n\n";
	Space();
	Space();
	cout << "3.退票\n\n";
	Space();
	Space();
	cout << "4.返回上级菜单\n\n";
	Star();
 
	// * 进行选择
	while (1)
	{
		cout << "请输入你要选择进行的操作：";
		cin >> choice;
 
		system("cls");
		return choice;
	}
	
	return 0;
}
 
 
// * 退出程序
int Quit()
{
	char judge;
	
	while (1)
	{
		cout << "\n\n\n";
		Space();
		Space();
		cout << "是否退出系统（y/n）:";
		cin >> judge;
 
		if (judge == 'y' || judge == 'Y')
		{
			system("cls");
			return 1;
		}
		if (judge == 'n' || judge == 'N')
		{
			system("cls");
			return 0;
		}
		system("cls");
	}
}
 
 
 
 
// * 输入回车控制
void Enter()
{
	int i;
 
	for (i = 0; i < 3; i++)
	{
		cout << endl;
	}
 
 
 
}
//输入20个空格
void Space()
{
	for (size_t i = 0; i < NUM1; i++)
	{
		cout << " ";
	}
}
 
 
//输入星形
void Star()
{
	Space();
	for (size_t i = 0; i < NUM2; i++)
	{
		cout << "*";
	}
	cout << "\n\n";
 
}