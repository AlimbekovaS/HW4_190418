#pragma once
#include<string>
class Address
{
private:
	string street;
	int home_num;
public:
	Address()
	{
		street = "";
		home_num = 0;
	}
	Address(string name, int home_num)
	{
		this->street = street;
		this->home_num = home_num;
	}
	string getStreet() { return street; }
	int getHome_num() { return home_num; }

	void setStreet(string street) { this->street = street; }
	void setHome_num(int home_num) { this->home_num = home_num; }
};
class Person
{
private:
	string fam;
	string name;
	string otch;
	Address house_addr;
	char gender;
	string study;
	int birth_year;
public:
	Person() :house_addr()
	{
		fam = "";
		name = "";
		otch = "";
		gender = ' ';
		study = "";
		birth_year = 0;

	}
	Person(string fam, string name, string otch, string street, int home_num,char gender,string study, int birth_year) :house_addr(street, home_num)
	{
		this->fam = fam;
		this->name = name;
		this->otch = otch;
		this->gender = gender;
		this->study = study;
		this->birth_year = birth_year;
	}

	string getFam() { return fam; }
	string getName() { return name; }
	string getOtch() { return otch; }
	char getGender() { return gender; }
	string getStudy() { return study; }
	int getBirth_year() { return birth_year; }

	void setFam() { this->fam= fam; }
	void setName() { this->name= name; }
	void setOtch() { this->otch= otch; }
	void setGender() { this->gender = gender; }
	void setStudy() { this->study = study; }
	void setBirth_year() {this->birth_year= birth_year; }

	void show1(int bufyear)
	{
		int b= 2018 - birth_year;
		if (b > bufyear)
			cout << birth_year <<"\t"<< fam << "\t" << name << "\t" << otch << "\t" << house_addr.getStreet() << "\t" << house_addr.getHome_num() << endl;
	}
	void show2()
	{
		if (study == "vysh")
		{
			cout <<study<<"\t"<< birth_year << "\t" << fam << "\t" << name << "\t" << otch << "\t" << house_addr.getStreet() << "\t" << house_addr.getHome_num() << endl;
		}
	}
	void show3()
	{
		if(gender=='m')
			cout << study << "\t" << birth_year << "\t" << fam << "\t" << name << "\t" << otch << "\t" << house_addr.getStreet() << "\t" << house_addr.getHome_num() << endl;
	}
};
