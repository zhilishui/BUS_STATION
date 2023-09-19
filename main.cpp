#include"head.h"
#include"function.h"
 
int main()
{
 
	char filename[20];
	
	strcpy(filename, "bus.txt");
	
	int UserChoice;// * �û���ѡ��
 
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
 
 
void AdminMode(Timetable* timetables, char* filename)// * �������Ҫ��
{
	Signin();// * ��¼����ʱ��Ҫ�ӻ���
 
	int n = ReadFromFile(timetables, 0, filename);
 
	while (1)
	{
		system("cls");
		int AdminChoice = AdminWindowSelect();
 
		
		switch (AdminChoice)
		{
		case 1: n = AddBus(timetables, n);						// * ��ӳ�����Ϣ
			WritetoFile(timetables, n, filename);
			system("pause");
			break;
 
		case 2: ShowTimeTable(timetables, n);					// * ���ʱ�̱�
			system("pause");
			break;
 
		case 3: Query(timetables, n);							// * ������Ϣ��ѯ
			system("pause");
			break;  
 
		case 4: n = DelBus(timetables, n);						// * ɾ��������Ϣ
			system("pause");
			WritetoFile(timetables, n, filename);
			break;
 
		case 5: WritetoFile(timetables, n, filename);			// * �����ϼ��˵�
			return;
 
		}
	}
 
}
 
 
void PassagerMode(Timetable* timetables, char* filename)
{
	char LogFileName[200];
 
	GenerateLogFileName(LogFileName);// * ���ݵ��������������־����
 
	int n = InitializationPassagerMode(timetables, LogFileName, filename);
 
	int PassagerChoice;
 
	while (1)
	{
 
		system("cls");
 
		switch (PassagerChoice = PassagerWindowSelect())
		{
		case 1: Query(timetables, n);					// * ���ҳ�����Ϣ
			system("pause");
			break;
 
		case 2: TicketOrder(timetables, n);				// * ����Ʊ
			WritetoFile(timetables, n, LogFileName);
			system("pause");
			break;
 
		case 3: TicketDelete(timetables, n);				// * �˻س�Ʊ
			WritetoFile(timetables, n, LogFileName);
			system("pause");
			break;
 
		case 4: WritetoFile(timetables, n, LogFileName);
			return;
		}
	}
}