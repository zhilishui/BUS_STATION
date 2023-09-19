#include"head.h"
#include"function.h"
 
 
//  * ��ʼ���˿�ģʽ���������־���Ͷ���־�����û�У��Ͷ�ȡ�����ļ�
int InitializationPassagerMode(Timetable* timetables, char* LogFileName, char* filename)
{
	int n;// * ͳ�Ƴ�������
 
	int i; // * �����ε���Ʊ����ʼ��Ϊ0��ѭ������
	
	fstream file_log;// * ������־�ļ�����
	fstream file;// * ����bus.txt�Ĳ���
 
	file_log.open(LogFileName, ios::in);
 
	if (file_log.fail())
	{
		// BuildLogFile(LogFileName);// * ��������е�û����
		
		n = ReadFromFile(timetables, 0, filename);
 
		for ( i = 0; i < n; i++)
		{
			timetables[i].sold_number = 0;
		}
 
		WritetoFile(timetables, n, LogFileName);
 
		return n;
	}
 
	file_log.close();
 
	n = ReadFromFile(timetables, 0, LogFileName);
 
	return n;
}
 
//  *  ��Ʊ
void TicketOrder(Timetable* timetables, int n)
{
	char find_no[20];// * Ҫ����ĳ���
 
	int num;
 
	cout << "\n\n\n";
	Space();
	Space();
	cout << "������Ҫ����ĳ��Σ�";
	cin >> find_no;// * ����Ҫ����ĳ���
 
 
	// * �жϳ����Ƿ����
	if (find(timetables, n, find_no) == -1)
	{
		Space();
		Space();
		cout << "���β�����" << endl;
		return;
	}
	
			   // * �ж��޷���Ʊ������
	if (StopSevice(timetables, n, find_no))
	{
		Space();
		Space();
		cout << "�޷���Ʊ��(�����������Ѿ�����)" << endl;
 
		return;
	}
 
	Space();
	Space();
	cout << "������Ҫ������Ŀ��";
 
	cin >> num;// * ����Ҫ������Ŀ
 
	if ((timetables[find(timetables, n, find_no)].max_number
		- timetables[find(timetables, n, find_no)].sold_number) < num)
	{
		Space();
		Space();
		cout << "��Ʊ���㣡" << endl;
 
		return;
	}
 
	timetables[find(timetables, n, find_no)].sold_number += num;
 
}
 
// * ��Ʊ
void TicketDelete(Timetable* timetables, int n)
{
	char find_no[20];// * Ҫ��Ʊ�ĳ���
 
	int num;// * ��Ʊ����
 
	cout << "\n\n\n";
	Space();
	Space();
	cout << "������Ҫ��Ʊ�ĳ��Σ�";
	cin >> find_no;// * ����Ҫ��Ʊ�ĳ���
 
 
	// * �жϳ����Ƿ����
	if (find(timetables, n, find_no) == -1)
	{
		Space();
		Space();
		cout << "���β�����" << endl;
		return;
	}
 
			   // * �ж��޷���Ʊ������
	if (StopSevice(timetables, n, find_no))
	{
		Space();
		Space();
		cout << "�޷���Ʊ��(�����������Ѿ�����)" << endl;
 
		return;
	}
 
 
	Space();
	Space();
	cout << "������Ҫ��Ʊ��Ŀ��";
	cin >> num;// * ����Ҫ��Ʊ��Ŀ
 
	if (timetables[find(timetables, n, find_no)].sold_number < num)
	{
 
		Space();
		Space();
		cout << "������Ʊ��Ŀ����" << endl;
 
		return;
	}
 
	timetables[find(timetables, n, find_no)].sold_number -= num;
 
}