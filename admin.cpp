#include"head.h"
#include"function.h"
 
// * ��ӳ���
 
int AddBus(Timetable* timetables, int n)
{
	int i;// * ѭ������
	// * ���������ʽ
	cout << "\n\n\n";
	Space();
	Space();
 
	cout << "�����복�κ�:";
	cin >> timetables[n].no;
	cout << endl;
	for ( i = 0; i < n; i++)
	{
		if (!strcmp(timetables[i].no, timetables[n].no))
		{
			cout << "�Ѵ�����ͬ����";
			return n;
		}
	}
	Space();
	Space();
	cout << "���������ʱ�䣨Сʱ����";
	cin >> timetables[n].hour;
	cout << endl;
	Space();
	Space();
	cout << "���������ʱ�䣨���ӣ���";
	cin >> timetables[n].minute;
	cout << endl;
	Space();
	Space();
	cout << "������ʼ��վ��";
	cin >> timetables[n].Starting_station;
	cout << endl;
	Space();
	Space();
	cout << "�������յ�վ��";
	cin >> timetables[n].Last_station;
	cout << endl;
	Space();
	Space();
	cout << "�������Լʱ����";
	cin >> timetables[n].time;
	cout << endl;
	Space();
	Space();
	cout << "������Ʊ�ۣ�";
	cin >> timetables[n].fare;
	cout << endl;
	Space();
	Space();
	cout << "����������ؿ�����";
	cin >> timetables[n].max_number;
 
	
	timetables[n].sold_number = 0;
 
	
	return n + 1;
}
 
 
// * �г����г���
void ShowTimeTable(Timetable* timetables, int n)
{
	int i;
	BeforeOutPutBus_2();
	for ( i = 0; i < n; i++)
	{
		OutPutBus_2(timetables, i);
 
		// * �շ�������
	}
	
}
 
 
// * ������Ϣ��ѯ
void Query(Timetable* timetables, int n)
{
	char find_both[20];// * �����ѯ�õı���
	int low[100];
 
	int choice = QueryChioce(); // * ����ѡ��
	int i; // * ѭ������
	if (choice == 1)// * �����β�ѯ
	{
		Star();
		Space();
		Space();
		cout << "������Ҫ��ѯ�ĳ��Σ�";
		cin >> find_both;
 
		// * �ж�find�ķ���ֵ�Ƿ���-1������ǣ�������β����ڲ�����
		if (find(timetables, n, find_both) == -1)
		{
			cout << "����ѯ�ĳ��β����ڣ�" << endl;
			return;
		}
		BeforeOutPutBus();
		OutPutBus(timetables, find(timetables, n, find_both));
	}
 
	else
	{
		Star();
		Space();
		Space();
		cout << "������Ҫ��ѯ���յ�վ��";
		cin >> find_both;
 
		// * �ж�find�ķ���ֵ�Ƿ���-1������ǣ�������β����ڲ�����
		if (find(timetables, n, find_both, low) == -1)
		{
			cout << "����ѯ���յ�վ�����ڣ�" << endl;
			return;
		}
 
		BeforeOutPutBus();
		for ( i = 0; i < find(timetables, n, find_both, low); i++)
		{
			OutPutBus(timetables, low[i]);
		}
 
	}
 
 
	
 
}
 
// * ɾ��������Ϣ
int DelBus(Timetable* timetables, int n)
{
	char find_no[20];
	int i;
	
	Star();
	Space();
	Space();
	cout << "������Ҫɾ���ĳ���:";
	cin >> find_no;
 
	// * �ж��Ƿ����
	if (find(timetables, n, find_no) == -1)
	{
		Space();
		Space();
		cout << "��ɾ���ĳ��β����ڣ�\n";
 
		return n;
	}
 
	// * ɾ������
	for (i = find(timetables, n, find_no); i < n; i++)
	{
		timetables[i] = timetables[i + 1];
	}
 
	return n - 1;
 
}