//5.House: Адрес, Этаж, Количество комнат, Площадь.
//Создать массив объектов.Вывести :
//	a) список квартир, имеющих заданное число комнат;
//	b) список квартир, имеющих заданное число комнат, и расположенных на этаже, который находится в заданном промежутке;
//	c) список квартир, имеющих площадь, превосходящую заданную.

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
		cout << "\nКакое задание? 1-House, 2-Person:";
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
				cout << "Файл открыт!" << endl;
				while (!in.eof())
				{
					in >> reg_no >> street >> flat_number >> floor >> room_number >> area;
					House R(reg_no, street, flat_number, floor, room_number, area);
					f[i] = R;
					i++;
				}
				in.close();
				int bufRoom, buffloor1, buffloor2, bufArea;
				cout << "a) список квартир, имеющих заданное число комнат;\n";
				cout << "Введите необходимое число комнат: ";
				cin >> bufRoom;
				cout << "кол к| рег ном| улица |ном кв| этаж | плoщ \n";
				for (int k = 0; k < i; k++)
				{
					f[k].showRoom(bufRoom);
				}
				cout << "========================================================================\n\n";
				cout << "список квартир, имеющих заданное число комнат, и расположенных на этаже, который находится в заданном промежутке;\n";
				cout << "Введите необходимое число комнат: ";
				cin >> bufRoom;
				cout << "введите через пробел необходимый промежуток этажей";
				cin >> buffloor1 >> buffloor2;
				cout << "кол к| рег ном| улица |ном кв| этаж | плoщ \n";
				for (int k = 0; k < i; k++)
				{
					f[k].showFloor(bufRoom, buffloor1, buffloor2);
				}
				cout << "========================================================================\n\n";
				cout << "c) список квартир, имеющих площадь, превосходящую заданную.\n";
				cout << "Введите площадь: ";
				cin >> bufArea;
				cout << "кол к| рег ном| улица |ном кв| этаж | плoщ \n";
				for (int k = 0; k < i; k++)
				{
					f[k].showArea(bufArea);
				}

			}
			delete[]f;

		}
		else if (z == 2)
		{
			/*7.Person: Фамилия, Имя, Отчество, Адрес, Пол, Образование, Год рождения.
				Создать массив объектов.Вывести :
				a) список граждан, возраст которых превышает заданный;
				b) список граждан с высшим образованием;
				c) список граждан мужского пола.*/
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
				cout << "a) список граждан, возраст которых превышает заданный;\n";
				cout << "Введите возраст: ";
				cin >> syear;
				for (int k = 0; k < i; k++)
				{
					p[k].show1(syear);		
				}
				cout << "========================================================================\n\n";
				cout << "b) список граждан с высшим образованием;\n";
				for (int k = 0; k < i; k++)
				{
					p[k].show2();
				}
				cout << "========================================================================\n\n";
				cout << "c) список граждан мужского пола.\n";
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