#include <iostream>
#include "Header.h"
using namespace std;

void news::change_string()
{
	char * tmp = name;
	int index1, index2;
	index1 = 0;

	// ищем первый пробел
	while (tmp[index1] != '\0')
	{
		if (tmp[index1] == ' ')
			break;
		index1++;
	}
	index2 = strlen(tmp);
	if (index1 == index2)
		return;
	while (tmp[index2] != ' ')
	{
		index2--;
	}
	int size;
	size = index1 + strlen(tmp) - index2 + 5;
	name = new char[size + 1];
	index1 = 0;
	while (tmp[index1] != ' ')
	{
		name[index1] = tmp[index1];
		index1++;
	}
	name[index1] = ' ';
	name[index1 + 1] = '.';
	name[index1 + 2] = '.';
	name[index1 + 3] = '.';
	name[index1 + 4] = ' ';
	index2 = strlen(tmp);
	name[size] = '\0';
	size--;
	while (tmp[index2] != ' ')
	{
		name[size--] = tmp[index2];
		index2--;
	}
	delete[] tmp;

}
news::news(news const & n) : news(n.date, n.name, n.views)
{

}
news news::operator =(const news & n)
{
	news(n.date,n.name,n.views);
	return *this;
}
news::news()
{
	date = NULL;
	name = NULL;
	views = 0;
}
news::news(char const * Date, char const * Name, int Views)
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
	views = Views;
}
//news::news(news const & n) : news(n.date, n.name, n.views)
//{
//
//}
news::~news()
{
	delete[] date;
	delete[] name;
}
//void news::print()
//{
//	cout << "Date: " << date << "; "
//		 << "Name: " << name << "; "
//		 << "Views: " << views;
//}
void news::set_name(char const * Name)
{
	if (name)
		delete[]name;
	if (Name)
	{
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
	}
	else name = NULL;
}
void news::set_date(char const * Date)
{
	if (date)
		delete[]date;
	if (Date)
	{
		date = new char[strlen(Date) + 1];
		strcpy_s(date, strlen(Date) + 1, Date);
	}
	else date = NULL;
}
void news::set_views(int Views)
{
	views = Views;
}
int news::get_views()
{
	return views;
}
char const *news::get_date()
{
	return date;
}
char const *news::get_name()
{
	return name;
}
ostream& operator<<(ostream& out, const news& news)
{
	return 	out << "Date: " << news.date <<"; "
		<< "Name: " <<news.name << "; "
		<< "Views: " << news.views;
}
//ostream& news::operator<<(ostream& out)
//{
//	return out << "Date: " << *this->date << "; "
//		<< "Name: " << *this->name << "; "
//		<< "Views: " << this->views;
//}
ostream& operator <<(ostream &s,  news&news)
{
	news.print(s);
	return s;
}
//istream& operator >>(istream&in, news & news)
//{
//	
//}
void news::print(ostream & s)
{
	s << "Date: " << date << "; "
		 << "Name: " << name << "; "
		 << "Views: " << views;
}
istream&operator>>(istream&in, news & news)
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
	news.set_date(date);
	news.set_name(name);
	news.set_views(views);
	return in;
}