#include"head.h"
#include"function.h"
 
// * ����Ա��¼
void Signin()
{
	int i;// * ����ѭ�����������������
	int j = 0;
	char account[40];
	
 
	while (1)
	{
		char password[50] = { '\0' };// * ��ʼ����������
 
		Star();
		Space();
		Space();
		cout << "��ӭʹ������վ��Ʊ����ϵͳ\n\n";
		Star();
		Space();
		Space();
		cout << "�˺ţ�";
		cin >> account;
		cin.ignore();// * ���������з�
		Space();
		Space();
		cout << "\n���룺";
		system("cls");
 
		i = 0;// * ��������
		while (1)
		{
			Star();
			Space();
			Space();
			cout << "��ӭʹ������վ��Ʊ����ϵͳ\n\n";
			Star();
			Space();
			Space();
			cout << "�˺ţ�";
			cout << account << endl;
			cout << endl;
			Space();
			Space();
			cout << "���룺";
			
			for (j = 0; j < i; j++)
				cout << "*";
 
			password[i] = getch();
 
		//	cout << endl << password;// * �����ʱ��Ҫɾ����
			
			if (password[i] == '\r')
				break;
 
 
			// * ����backspace��ʱ��ɾ���ַ����е��ַ�
			if (password[i] == '\b')
			{
					password[i] = '\0';
					i--;
 
					// * ��ֹ������
					if (i != -1)
						i--;
			}
			system("cls");
			i++;
 
			if (i > 20)
			{
				break;
			}
		}
		
		
		
		// * �Ƚ��Ƿ�һ��
		if (!strcmp(account, "admin") && !strcmp(password, "123456\r") )
		{
			system("cls");
			return;
		}
		
		cout << "\n\n\n";
		Space();
		Space();
		cout << "������˺Ż���������\n";
		Space();
		Space();
 
 
		
		system("pause");
		system("cls");
 
	}
 
 
}
 
// * ���ļ��ж�ȡ����,�������ݵ�����
int ReadFromFile(Timetable* timetables, int n, char* filename)
{
	fstream file;
	file.open(filename, ios::in);
 
	// * ����Ҳ����ļ��ͽ���һ���µ��ļ�
	if (file.fail())
	{
		file.close();
 
		file.open(filename, ios::out);
 
		file.close();
 
		file.open(filename, ios::in);
	}
 
	
	while (!file.eof())
	{
		file >> timetables[n].no;
 
		// * ��ֹ��һ���ǿյı���ȡ��ȥ
		if (file.eof())
		{
			file.close();
			break;
		}
		file >> timetables[n].hour;
		file >> timetables[n].minute;
		file >> timetables[n].Starting_station;
		file >> timetables[n].Last_station;
		file >> timetables[n].time;
		file >> timetables[n].fare;
		file >> timetables[n].max_number;
		file >> timetables[n].sold_number;
		n++;
	}
 
	return n;
}
 
// * �����ݱ��浽�ļ���
int WritetoFile(Timetable* timetables, int n, char* filename)
{
	SortbyTime(timetables, n);
 
	fstream file;
	file.open(filename, ios::out);
 
	int i; // * ѭ������
	
	// * ���nΪ0�Ļ��Ͳ�д���ļ���
	if (n == 0)
	{
		file.close();
		return 0;
	}
	//====================================================
	file << setw(10) << timetables[0].no;
	file << setw(10) << timetables[0].hour;
	file << setw(10) << timetables[0].minute;
	file << setw(10) << timetables[0].Starting_station;
	file << setw(10) << timetables[0].Last_station;
	file << setw(10) << timetables[0].time;
	file << setw(10) << timetables[0].fare;
	file << setw(10) << timetables[0].max_number;
	file << setw(10) << timetables[0].sold_number;
	
	
	for (i = 1; i < n; i++)
	{
		cout.setf(ios::left);
		file << endl;
		file << setw(10) << timetables[i].no;
		file << setw(10) << timetables[i].hour;
		file << setw(10) << timetables[i].minute;
		file << setw(10) << timetables[i].Starting_station;
		file << setw(10) << timetables[i].Last_station;
		file << setw(10) << timetables[i].time;
		file << setw(10) << timetables[i].fare;
		file << setw(10) << timetables[i].max_number;
		file << setw(10) << timetables[i].sold_number;
 
	}
 
	// * �ֿ�д���ļ�����Ϊ������ֿ����һ��endl��������һ�е���һ�пյı���ȡ
	// =============================================================
	return 0;
}
 
 
// * ���ݵ�������������־��
void GenerateLogFileName(char* LogFileName)
{
	time_t t = time(0);
 
	struct tm* time;
 
	time = localtime(&t);
	
	char year[5], month[2], day[3];// * ��������������ַ������ַ�������
 
	// * ʱ����int�ͣ�����ת��Ϊchar��
	itoa(time->tm_mday, day, 10);
	itoa(time->tm_year + 1900, year, 10);
	itoa(time->tm_mon + 1, month, 10);
	
 
	strcpy(LogFileName, year);
	strcat(LogFileName, "-");
	strcat(LogFileName, month);
	strcat(LogFileName, "-");
	strcat(LogFileName, day);
	strcat(LogFileName, ".log");
 
}
 
 
 
// *  ��timetable�����Ԫ�ذ��շ�����ʱ���������
void SortbyTime(Timetable* timetables, int n)
{
	// * ����ð������
	int i, j;
 
	Timetable t;// * ������������
 
	// * ð������
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (timetables[j].hour * 60 + timetables[j].minute > timetables[j + 1].hour * 60 + timetables[j + 1].minute)
			{
				t = timetables[j + 1];
				timetables[j + 1] = timetables[j];
				timetables[j] = t;
			}
		}
	}
 
 
}
 
// * ������Ӧ�ĳ��κţ��ж��Ƿ�ֹͣ��Ʊ����Ʊ
int StopSevice(Timetable* timetables, int n, char* no)
{
	struct tm* local;// * ʱ��ṹ��
 
	time_t t = time(0);// * �ѵ�ǰ��ʱ���t
 
	local = localtime(&t);// * ��ȡ��ǰϵͳʱ��
 
	int i = find(timetables, n, no);
 
	if ((local -> tm_hour * 60 + local -> tm_min) + 10 < timetables[i].hour * 60 + timetables[i].minute)
	{
		return 0;
	}
 
	return 1;
 
 
}
 
 
 
 
// **    ��������
// 
// 
// * ��ѯ����ʱѡ����Ҫ�����β�ѯ�����յ�վ��ѯ
int QueryChioce()
{
 
	int choice;
 
	Star();
	Space();
	Space();
	cout << "��ѡ���ѯ��ʽ\n\n";
	Star();
	Space();
	Space();
	cout << "1.���ճ��β�ѯ\n\n";
	Space();
	Space();
	cout << "2.�����յ�վ��ѯ\n\n";
	Star();
 
	Space();
	Space();
	cout << "�������ѯ��ʽ��";
	cin >> choice;
	// * ����û�����������1��2��������Ĵ������
	// * ֮�����ѡ�񲹼�
 
	system("cls");
	return choice;
}
 
// * ����±�Ϊi��timetables�ṹ�����������ֵ
 
void BeforeOutPutBus()
{
	cout.setf(ios::left);
	cout << setw(10) << "���κ�";
	cout << setw(10) << "����ʱ��";
	cout << "  ";
	cout << setw(10) << "ʼ��վ";
	cout << setw(10) << "�յ�վ";
	cout << setw(10) << "Ԥ����ʱ";
	cout << setw(10) << "Ʊ��";
	cout << setw(15) << "����ؿ���";
	cout << setw(10) << "����Ʊ��" << endl;
}
 
void OutPutBus(Timetable* timetables, int i)
{
	cout.setf(ios::left);
	cout << setw(10) << timetables[i].no;
	cout << timetables[i].hour << ":";
	cout << setw(10) << timetables[i].minute;
	cout << setw(10) << timetables[i].Starting_station;
	cout << setw(10) << timetables[i].Last_station;
	cout << setw(10) << timetables[i].time;
	cout << setw(10) << timetables[i].fare;
	cout << setw(15) << timetables[i].max_number;
	cout << setw(10) << timetables[i].sold_number << endl;
 
}
 
 
// * ���복�κţ������±�
int find(Timetable* timetables, int n, char* no)
{
	int i; // * ѭ������
	
	for ( i = 0; i < n; i++)
	{
		if (!strcmp(no, timetables[i].no))
		{
			return i;
		}
	}
	
	return -1;
}
 
// * ���յ�վ���в�ѯ�������յ�վ����Ŀ������b[]�����յ�վ���±�
int find(Timetable* timetables, int n, char* Last_station, int* b)
{
	int i; // * ѭ������
 
	int num = 0; // * ��¼���ε���Ŀ
 
	for (i = 0; i < n; i++)
	{
		if (!strcmp(Last_station, timetables[i].Last_station))
		{
			b[num] = i;
			num++;
		}
	}
 
	if (num != 0)
	{
		return num;
	}
	else
		return -1;
}
 
 
// * �����Ǹ��ǳ˿͵����������ǹ���Ա�������doge��
 
void BeforeOutPutBus_2()
{
	cout.setf(ios::left);
	cout << setw(10) << "���κ�";
	cout << setw(10) << "����ʱ��";
	cout << "  ";
	cout << setw(10) << "ʼ��վ";
	cout << setw(10) << "�յ�վ";
	cout << setw(10) << "Ԥ����ʱ";
	cout << setw(10) << "Ʊ��";
	cout << setw(15) << "����ؿ���" << endl;
}
 
void OutPutBus_2(Timetable* timetables, int i)
{
	cout.setf(ios::left);
	cout << setw(10) << timetables[i].no;
	cout << timetables[i].hour << ":";
	cout << setw(10) << timetables[i].minute;
	cout << setw(10) << timetables[i].Starting_station;
	cout << setw(10) << timetables[i].Last_station;
	cout << setw(10) << timetables[i].time;
	cout << setw(10) << timetables[i].fare;
	cout << setw(15) << timetables[i].max_number << endl;
 
}