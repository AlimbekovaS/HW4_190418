//5.House: �����, ����, ���������� ������, �������.
//������� ������ ��������.������� :
//	a) ������ �������, ������� �������� ����� ������;
//	b) ������ �������, ������� �������� ����� ������, � ������������� �� �����, ������� ��������� � �������� ����������;
//	c) ������ �������, ������� �������, ������������� ��������.

#include<iostream>
#include "House.h"
#include<fstream>
#include "Person.h"
unsigned short int z;
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	while (true)
	{
		cout << "\n����� �������? 1-House, 2-Person:";
		cin >> z;
		if (z == 0)
		{
			break;
		}
		else if (z == 1)
		{
			House *f;
			f = new House[10];
			int i = 0;
			ifstream in;
			in.open("house.txt");
			string street;
			int reg_no, flat_number, floor, room_number, area;
			if (!in.is_open())
			{
				cout << "Error" << endl;
			}
			else
			{
				cout << "���� ������!" << endl;
				while (!in.eof())
				{
					in >> reg_no >> street >> flat_number >> floor >> room_number >> area;
					House R(reg_no, street, flat_number, floor, room_number, area);
					f[i] = R;
					i++;
				}
				in.close();
				int bufRoom, buffloor1, buffloor2, bufArea;
				cout << "a) ������ �������, ������� �������� ����� ������;\n";
				cout << "������� ����������� ����� ������: ";
				cin >> bufRoom;
				cout << "��� �| ��� ���| ����� |��� ��| ���� | ��o� \n";
				for (int k = 0; k < i; k++)
				{
					f[k].showRoom(bufRoom);
				}
				cout << "========================================================================\n\n";
				cout << "������ �������, ������� �������� ����� ������, � ������������� �� �����, ������� ��������� � �������� ����������;\n";
				cout << "������� ����������� ����� ������: ";
				cin >> bufRoom;
				cout << "������� ����� ������ ����������� ���������� ������";
				cin >> buffloor1 >> buffloor2;
				cout << "��� �| ��� ���| ����� |��� ��| ���� | ��o� \n";
				for (int k = 0; k < i; k++)
				{
					f[k].showFloor(bufRoom, buffloor1, buffloor2);
				}
				cout << "========================================================================\n\n";
				cout << "c) ������ �������, ������� �������, ������������� ��������.\n";
				cout << "������� �������: ";
				cin >> bufArea;
				cout << "��� �| ��� ���| ����� |��� ��| ���� | ��o� \n";
				for (int k = 0; k < i; k++)
				{
					f[k].showArea(bufArea);
				}

			}
			delete[]f;

		}
		else if (z == 2)
		{
			/*7.Person: �������, ���, ��������, �����, ���, �����������, ��� ��������.
				������� ������ ��������.������� :
				a) ������ �������, ������� ������� ��������� ��������;
				b) ������ ������� � ������ ������������;
				c) ������ ������� �������� ����.*/
			Person *p=new Person[10];
			int i = 0;
			ifstream in;
			in.open("Person.txt");
			if (in.is_open())
			{
				string fam, name, otch, street,study ;
				int home_num, birth_year, syear;
				char gender;
				while (!in.eof())
				{
					in >> fam >> name >> otch >> street >> home_num>> gender>> study >> birth_year;
					Person d(fam, name, otch, street, home_num,gender,study, birth_year);
					p[i++] = d;
				}
				cout << "a) ������ �������, ������� ������� ��������� ��������;\n";
				cout << "������� �������: ";
				cin >> syear;
				for (int k = 0; k < i; k++)
				{
					p[k].show1(syear);		
				}
				cout << "========================================================================\n\n";
				cout << "b) ������ ������� � ������ ������������;\n";
				for (int k = 0; k < i; k++)
				{
					p[k].show2();
				}
				cout << "========================================================================\n\n";
				cout << "c) ������ ������� �������� ����.\n";
				for (int k = 0; k < i; k++)
				{
					p[k].show3();
				}
			}
			else
			{
				cout << "error";
			}
			in.close();
			delete[]p;
		}
	}
	system("pause");
	return 0;
}