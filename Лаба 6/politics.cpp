#include <iostream>
#include "Header.h"
using namespace std;


politics::politics() : politics(NULL, NULL, 0, NULL) {}
politics::politics(char const * Date, char const * Name, int Views, char const * Country)
{
	if (Date)
	{
		int lenBuf = strlen(Date);
		if (lenBuf < 200)
			date = new char[lenBuf + 1];
		else
		{
			date = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(date, lenBuf + 1, Date);
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
	if (Country)
	{
		int lenBuf = strlen(Country);
		if (lenBuf < 200)
			country = new char[lenBuf + 1];
		else
		{
			country = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(country, lenBuf + 1, Country);
	}
	else
		country = nullptr;
	views = Views;

}
politics::politics(politics const & n) : politics(n.date, n.name, n.views, n.country)
{

}
politics politics::operator = (politics const & n)
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
	if (n.country)
	{
		int lenBuf = strlen(n.country);
		if (lenBuf < 200)
			country = new char[lenBuf + 1];
		else
		{
			country = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(country, lenBuf + 1, n.country);
	}
	else
		country = nullptr;
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
	views = n.views;

	return *this;
}
politics::~politics()
{
	delete[] country;
}
void politics::set_country(char const * Country)
{
	if (country)
		delete[]country;
	if (Country)
	{
		country = new char[strlen(Country) + 1];
		strcpy_s(country, strlen(Country) + 1, Country);
	}
	else country = NULL;
}
char const *politics::get_country()
{
	return country;
}
void politics::print(ostream&s)
{
	s << "Date: " << date << "; "
		 << "Name: " << name << "; "
		 << "Views: " << views << "; "
		 << "Country: " << country;
}
istream&operator>>(istream&in, politics & politics)
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
	char country[255];
	cout << "Country: ";
	cin.ignore();
	cin.getline(country, 255, '\n');
	politics.set_date(date);
	politics.set_name(name);
	politics.set_views(views);
	politics.set_country(country);
	return in;
}
//ostream& operator<<(ostream& cout, const politics& politics)
//{
//	return 	cout << "Date: " << *politics.date << "; "
//		<< "Name: " << *politics.name << "; "
//		<< "Views: " << politics.views << "; "
//		<< "Country: " << *politics.country;
//}
//ostream& politics::operator<<(ostream& out)
//{
//	return out << "Date: " << *this->date << "; "
//		<< "Name: " << *this->name << "; "
//		<< "Views: " << this->views << "; "
//		<< "Country: " << *this->country;
//}
ostream& operator<<(ostream& cout, const politics& politics)
{
	return 	cout << "Date: " << politics.date << "; "
		<< "Name: " << politics.name << "; "
		<< "Views: " << politics.views << "; "
		<< "Country: " << politics.country;
}