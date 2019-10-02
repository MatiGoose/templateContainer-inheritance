#include <iostream>
#include "Header.h"
using namespace std;

events::events() : events(NULL, NULL, 0, NULL, NULL, 0) {}
events::events(char const * Date, char const * Name, int Views, char const * Sphere, char const * Concerts, double Price)
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
	if (Concerts)
	{
		int lenBuf = strlen(Concerts);
		if (lenBuf < 200)
			concerts = new char[lenBuf + 1];
		else
		{
			concerts = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(concerts, lenBuf + 1, Concerts);
	}
	else
		concerts = nullptr;
	views = Views;
	price = Price;

}
events::events(events const & n) : events(n.date, n.name, n.views, n.sphere, n.concerts, n.price)
{

}

events events::operator = (events const & n)
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
	if (n.concerts)
	{
		int lenBuf = strlen(n.concerts);
		if (lenBuf < 200)
			concerts = new char[lenBuf + 1];
		else
		{
			concerts = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(concerts, lenBuf + 1, n.concerts);
	}
	else
		concerts = nullptr;

	views = n.views;
	price = n.price;
	return *this;
}

void events::set_concerts(char const * Ñoncerts)
{
	if (concerts)
		delete[]concerts;
	if (Ñoncerts)
	{
		concerts = new char[strlen(Ñoncerts) + 1];
		strcpy_s(concerts, strlen(Ñoncerts) + 1, Ñoncerts);
	}
	else concerts = NULL;
}
char const *events::get_concerts()
{
	return concerts;
}
void events::set_price(double Price)
{
	price = Price;
}
double events::get_price()
{
	return price;
}
events::~events()
{
	delete[] concerts;
}
void events::print(ostream&s)
{
	s << "Date: " << date << "; "
		 << "Name: " << name << "; "
		 << "Views: " << views << "; "
		 << "Sphere: " << sphere << "; "
		 << "Concert: " << concerts << "; "
		 << "Price: " << price;
}
istream& operator >>(istream& in, events & events)
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
	char concerts[255];
	cout << "Concerts: ";
	//cin.ignore();
	cin.getline(concerts, 255, '\n');
	double price;
	cout << "Price: ";
	cin >> price;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore();
		cout << "Price: " << endl;
		cin >> price;
	}
	events.set_date(date);
	events.set_name(name);
	events.set_views(views);
	events.set_sphere(sphere);
	events.set_concerts(concerts);
	events.set_price(price);
	return in;
}
ostream& operator<<(ostream& cout, const events& events)
{
	return 	cout << "Date: " << events.date << "; "
		<< "Name: " << events.name << "; "
		<< "Views: " << events.views << "; "
		<< "Concert: " << events.concerts<< "; "
		<< "Price: " << events.price << "; "
		<< "Sphere: " << events.sphere;
}
//ostream& operator<<(ostream& cout,  events& events)
//{
//	events.get_date();
//	return 	cout << "Date: " <<* events.get_date() << "; "
//		<< "Name: " << *events.get_name() << "; "
//		<< "Views: " << events.get_views() << "; "
//		<< "Sphere: " <<* events.get_sphere() << "; "
//		<< "Concert: " <<* events.get_concerts() << "; "
//		<< "Price: " << events.get_price();
//}
//ostream& events::operator<<(ostream& out)
//{
//	return out << "Date: " << *this->date << "; "
//		<< "Name: " << *this->name << "; "
//		<< "Views: " << this->views << "; "
//		<< "Sphere: " << *this->sphere << "; "
//		<< "Concerts: " << *this->concerts << "; "
//		<< "Price: " << this->price;
//}