#include <iostream>
#include "Header.h"
using namespace std;


entertainment::entertainment() : entertainment(NULL, NULL, 0, NULL) {}
entertainment::entertainment(char const * Date, char const * Name, int Views, char const * Sphere)
{
	if (Date)
	{
		int lenBuf = strlen(Date);
		if (lenBuf < 200)
			name = new char[lenBuf + 1];
		else
		{
			date = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(date, lenBuf + 1, Name);
	}
	else
		date = nullptr;
	if (Name)
	{
		int lenBuf = strlen(Name);
		if (lenBuf < 200)
			name = new char[lenBuf + 1];
		else
		{
			name = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(name, lenBuf + 1, Name);
	}
	else
		name = nullptr;
	if (Sphere)
	{
		int lenBuf = strlen(Sphere);
		if (lenBuf < 200)
			sphere = new char[lenBuf + 1];
		else
		{
			sphere = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(sphere, lenBuf + 1, Sphere);
	}
	else
		sphere = nullptr;
	views = Views;

}

entertainment::entertainment(entertainment const & n) : entertainment(n.date, n.name, n.views, n.sphere)
{

}
entertainment entertainment::operator = (entertainment const & n)
{
	//celebrity(n.date, n.name, n.views, n.sphere, n.country, n.person, n.subscribers);
	if (n.date)
	{
		int lenBuf = strlen(n.date);
		if (lenBuf < 200)
			name = new char[lenBuf + 1];
		else
		{
			date = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(date, lenBuf + 1, n.date);
	}
	else
		date = nullptr;
	if (n.name)
	{
		int lenBuf = strlen(n.name);
		if (lenBuf < 200)
			name = new char[lenBuf + 1];
		else
		{
			name = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(name, lenBuf + 1, n.name);
	}
	else
		name = nullptr;
	if (n.sphere)
	{
		int lenBuf = strlen(n.sphere);
		if (lenBuf < 200)
			sphere = new char[lenBuf + 1];
		else
		{
			sphere = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(sphere, lenBuf + 1, n.sphere);
	}
	else
		sphere = nullptr;

	views = n.views;
	return *this;
}
entertainment::~entertainment()
{
	delete[] sphere;
}
void entertainment::set_sphere(char const * Sphere)
{
	if (sphere)
		delete[]sphere;
	if (Sphere)
	{
		sphere = new char[strlen(Sphere) + 1];
		strcpy_s(sphere, strlen(Sphere) + 1, Sphere);
	}
	else sphere = NULL;
}
char const *entertainment::get_sphere()
{
	return sphere;
}
istream&operator>>(istream&in, entertainment & entertainment)
{
	char date[255];
	char name[255];
	int views;
	cout << "Date: ";
	cin.ignore();
	cin.getline(date, 255, '\n');
	cout << "Name: ";
	//cin.ignore();
	cin.getline(name, 255, '\n');
	cout << "Views: ";
	cin >> views;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore();
		cout << "Views: " << endl;

		cin >> views;
	}
	char sphere[255];
	cout << "Sphere: ";
	cin.ignore();
	cin.getline(sphere, 255, '\n');
	entertainment.set_date(date);
	entertainment.set_name(name);
	entertainment.set_views(views);
	entertainment.set_sphere(sphere);
	return in;
}
ostream& operator<<(ostream& cout, const entertainment& entertainment)
{
	return 	cout << "Date: " << entertainment.date << "; "
		<< "Name: " << entertainment.name << "; "
		<< "Views: " << entertainment.views << "; "
		<< "Sphere: " << entertainment.sphere;
}
void entertainment::print(ostream &s)
{
	s << "Date: " << date << "; "
		 << "Name: " << name << "; "
		 << "Views: " << views << "; "
		 << "Sphere: " << sphere;
}
//ostream& entertainment::operator<<(ostream& cout)
//{
//	return 	cout << "Date: " << *this->date << "; "
//		<< "Name: " <<*this->name << "; "
//		<< "Views: " << this->views << "; "
//		<< "Sphere: " <<*this->sphere;
//}
//ostream& operator<<(ostream& cout, entertainment& entertainment)
//{
//	return 	cout << "Date: " << entertainment.get_date() << "; "
//		<< "Name: " << entertainment.get_name() << "; "
//		<< "Views: " << entertainment.get_views() << "; "
//		<< "Sphere: " << entertainment.get_sphere();
//}