#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <iostream>

#include<fstream>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	
	char answer;
	char username[20];
	ifstream user ("LastUser.txt", ios::in);
	user>>username;
	printf("�����! ���� ����� %s?", username);
	cout<<" (y/n) ";
	cin>>answer;
	if (answer!=121)
	{
		cout<<"����� ��� ��'�: ";
	    scanf("%s", username);
		printf("������ ������, %s!\n����� ��������� �� �������� �����!", username);
	 }
	else		
	{
		
		printf("����� ���� ����� ������, %s!\n����� ��������� �� ����������� ��� ������!", username);
    }

	int numb1, numb2, res, otv, i;
	time_t t;
	time_t current_time;
	time_t current_timend;
    time(&current_time);
	ofstream logfile ("Multiply_Database.txt", ios::app | ios::ate);
	logfile<<"----------------------------------------------------------\n"<<username<<'\n'<<"       ������� ����������:        "<<ctime(&current_time);
	printf("\n           ***�������� �� ������ �������  ��������***\n");
begin: printf("ϳ��� ��������� ����� ��������� ������� � ������� <Enter>\n");
	int kol=0;
	srand((unsigned) time(&t));
	for (i=1; i<=10; i++)
	{
		numb1 = rand() % 7 + 2;
		numb2 = rand() % 7 + 2;
		res= numb1*numb2;
		printf("%ix%i=", numb1, numb2);
		scanf("%i", &otv);
		if (otv==res)
			kol++;
		else
			printf("%s! ����� �����! %ix%i=%i \n����������...\n\a", username, numb1, numb2, res);
	}
	printf("\n���������� ��������: %i\n\a\a\a", kol);
	printf("���� ������:  ");
	switch (kol)
	{
	case 10: puts("12"); break;
		case 9: puts("11"); break;
			case 8: puts("10"); break;
				case 7: puts("9"); break;
					case 6: puts("8"); break;
						case 5: puts("7"); break;
							case 4: puts("6"); break;
								case 3: puts("4"); break;
									case 2: puts("3"); break;
										default: puts("2"); break;
	}
	time(&current_timend);
	cout<<"��� ������� ����������:    "<<ctime(&current_time);
	cout<<"��� ��������� ����������: "<<ctime(&current_timend);
	logfile<<"       ��� ��������� ����������: "<<ctime(&current_timend);
	logfile<<"       ���������� ��������: "<<kol<<'\n';
	ofstream login ("LastUser.txt", ios::out | ios::trunc);
	login<<username;
	cout<<"\n��� ����������� ���������� ������� y, ��� ���������� ����-��� ������\n";
	cin>>answer;
	if (answer!=121)
		goto end;
		goto begin;
end: getchar();
	}