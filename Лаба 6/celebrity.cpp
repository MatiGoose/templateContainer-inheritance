#include <iostream>
#include "Header.h"
using namespace std;


celebrity::celebrity() : celebrity(NULL, NULL, 0, NULL, NULL, NULL, 0) {}
celebrity::celebrity(char const * Date, char const * Name, int Views, char const * Sphere, char const * Person, char const * Country, int Subscribers)
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
	if (Person)
	{
		int lenBuf = strlen(Person);
		if (lenBuf < 200)
			person = new char[lenBuf + 1];
		else
		{
			person = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(person, lenBuf + 1, Person);
	}
	else
		person = nullptr;
	views = Views;
	subscribers = Subscribers;
}
celebrity::celebrity(celebrity const & n) : celebrity(n.date, n.name, n.views, n.sphere, n.country, n.person, n.subscribers)
{

}
celebrity celebrity::operator = (celebrity const & n)
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
	if (n.person)
	{
		int lenBuf = strlen(n.person);
		if (lenBuf < 200)
			person = new char[lenBuf + 1];
		else
		{
			person = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(person, lenBuf + 1, n.person);
	}
	else
		person = nullptr;
	views = n.views;
	subscribers = n.subscribers;

	return *this;
}

void celebrity::set_person(char const * Person)
{
	if (person)
		delete[]person;
	if (Person)
	{
		person = new char[strlen(Person) + 1];
		strcpy_s(person, strlen(Person) + 1, Person);
	}
	else person = NULL;
}
char const *celebrity::get_person()
{
	return person;
}
void celebrity::set_subscribers(int Subscribers)
{
	subscribers = Subscribers;
}
int celebrity::get_subscribers()
{
	return subscribers;
}
celebrity::~celebrity()
{
	delete[] person;
}
istream&operator>>(istream&in, celebrity & celebrity)
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
	char sphere[255];
	cout << "Sphere: ";
	//cin.ignore();
	cin.getline(sphere, 255, '\n');
	char person[255];
	cout << "Person: ";
	//cin.ignore();
	cin.getline(person, 255, '\n');
	int subscribers;
	cout << "Subscribers: ";
	cin >> subscribers;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore();
		cout << "Subscribers: " << endl;
		cin >> subscribers;
	}
	celebrity.set_date(date);
	celebrity.set_name(name);
	celebrity.set_views(views);
	celebrity.set_country(country);
	celebrity.set_sphere(sphere);
	celebrity.set_person(person);
	celebrity.set_subscribers(subscribers);
	return in;
}
ostream& operator<<(ostream& cout, const celebrity& celebrity)
{
	return 	cout << "Date: " << celebrity.date << "; "
		<< "Name: " << celebrity.name << "; "
		<< "Views: " << celebrity.views << "; "
		<< "Person: " << celebrity.person << "; "
		<< "Country: " << celebrity.country<< "; "
		<< "Subscribers: " << celebrity.subscribers << "; "
		<< "Sphere: " << celebrity.sphere;
}
//
void celebrity::print(ostream& s)
{
	s << "Date: " << date << "; "
		 << "Name: " << name << "; "
		 << "Views: " << views << "; "
		 << "Country: " << country << "; "
		 << "Sphere: " << sphere << "; "
		 << "Person: " << person << "; "
		 << "Subscribers: " << subscribers;
}
//ostream& operator<<(ostream& cout, celebrity& celebrity)
//{
//	return 	cout << "Date: " << *celebrity.get_date() << "; "
//		<< "Name: " << *celebrity.get_name() << "; "
//		<< "Views: " << celebrity.get_views() << "; "
//		<< "Sphere: " <<* celebrity.get_sphere() << "; "
//		<< "Country: " << *celebrity.get_country() << "; "
//		<< "Person: " << *celebrity.get_person() << "; "
//		<< "Subscribers: " << celebrity.get_subscribers();
//}
//ostream& celebrity::operator<<(ostream& out)
//{
//	return out << "Date: " << *this->date << "; "
//		<< "Name: " << *this->name << "; "
//		<< "Views: " << this->views << "; "
//		<< "Country: " << *this->country <<"; "
//		<< "Sphere: " << *this->sphere << "; "
//		<< "Person: " << *this->person << "; "
//		<< "Subscribers: " << this->subscribers;
//}