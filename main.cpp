#include"head.h"
#include"function.h"
 
int main()
{
 
	char filename[20];
	
	strcpy(filename, "bus.txt");
	
	int UserChoice;// * 用户的选择
 
	Timetable timetables[100];
 
	while (1)
	{
		switch (UserChoice = MainWindowSelect())
		{
		case 1: AdminMode(timetables, filename); break;
 
		case 2: PassagerMode(timetables, filename); break;
 
		case 3: if (Quit() != 1) 
					continue;
		}
 
 
		if (UserChoice == 3)
			break;
 
	}
 
	return 0;
}
 
 
void AdminMode(Timetable* timetables, char* filename)// * 这里可能要改
{
	Signin();// * 登录，到时候要加回来
 
	int n = ReadFromFile(timetables, 0, filename);
 
	while (1)
	{
		system("cls");
		int AdminChoice = AdminWindowSelect();
 
		
		switch (AdminChoice)
		{
		case 1: n = AddBus(timetables, n);						// * 添加车次信息
			WritetoFile(timetables, n, filename);
			system("pause");
			break;
 
		case 2: ShowTimeTable(timetables, n);					// * 浏览时刻表
			system("pause");
			break;
 
		case 3: Query(timetables, n);							// * 车辆信息查询
			system("pause");
			break;  
 
		case 4: n = DelBus(timetables, n);						// * 删除车辆信息
			system("pause");
			WritetoFile(timetables, n, filename);
			break;
 
		case 5: WritetoFile(timetables, n, filename);			// * 返回上级菜单
			return;
 
		}
	}
 
}
 
 
void PassagerMode(Timetable* timetables, char* filename)
{
	char LogFileName[200];
 
	GenerateLogFileName(LogFileName);// * 根据当天的日期生成日志名称
 
	int n = InitializationPassagerMode(timetables, LogFileName, filename);
 
	int PassagerChoice;
 
	while (1)
	{
 
		system("cls");
 
		switch (PassagerChoice = PassagerWindowSelect())
		{
		case 1: Query(timetables, n);					// * 查找车辆信息
			system("pause");
			break;
 
		case 2: TicketOrder(timetables, n);				// * 购买车票
			WritetoFile(timetables, n, LogFileName);
			system("pause");
			break;
 
		case 3: TicketDelete(timetables, n);				// * 退回车票
			WritetoFile(timetables, n, LogFileName);
			system("pause");
			break;
 
		case 4: WritetoFile(timetables, n, LogFileName);
			return;
		}
	}
}