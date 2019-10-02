#include <iostream>
#include "Header.h"
#define profit 0.03
using namespace std;


void menu()
{
	cout << "1)Input news" << endl;
	cout << "2)Show all news" << endl;
	cout << "3)Show concretic news" << endl;
	cout << "4)Edit news" << endl;
	cout << "5)Delete news" << endl;
	cout << "6)Short news" << endl;
	cout << "7)Show income" << endl;
	cout << "8)Show main information about news" << endl;
	cout << "9)Exit" << endl;
}
template <typename T1, typename T2>
void show_n(T1 date, T1 name, T2 views)
{
	cout << "Date: " << date;
	cout << "; Name: " << name;
	cout << "; Income: " << (views * profit) << endl;
}
void show_main_information(my_stack<news > Container)
{
	for (int i = 0; i < Container.stack_size(); i++)
	{
		cout << i + 1 << ") ";
		show_n(Container[i].get_date(), Container[i].get_name(), Container[i].get_views());
	}
}
void add_news(my_stack<news> *Container)
{
	cout << "1)Politics news" << endl;
	cout << "2)Entertainment news" << endl;
	cout << "3)Celebrity news" << endl;
	cout << "4)Events news" << endl;
	int choice = 0;
	while (choice > 4 || choice < 1)
	{
		cin >> choice;
		while (!cin.good())
		{
			cin.clear();
			cin.ignore();
			cout << "Input 1-4" << endl;
			cin >> choice;
		}
			switch (choice)
			{
			case 1:
			{
				politics * new_news = new politics;
				cin >> *new_news;
				//(*(Container_ptr)).Push(new_news);
				Container->Push(*new_news);
			}
			break;
			case 2:
			{
				entertainment * new_news = new entertainment;
				cin >> *new_news;
				//(*(Container_ptr)).Push(new_news);
				Container->Push(*new_news);
			}
			break;
			case 3:
			{
				celebrity * new_news = new celebrity;
				cin >> *new_news;
				//(*(Container_ptr)).Push(new_news);
				Container->Push(*new_news);
			}
			break;
			case 4:
			{
				events * new_news = new events;
				cin >> *new_news;
				//(*(Container_ptr)).Push(new_news);
				Container->Push(*new_news);
			}
			break;
			default: cout << "Input 1-4" << endl;
				break;
			}
	}

}
void show_news(my_stack<news > Container )
{
	
	for(int i = 0; i < Container.stack_size(); i++)
	{
		cout << Container[i];
		int choice;
		politics new_politics;
		entertainment new_entertainment;
		celebrity new_celebrity;
		events new_events;
		if (typeid(Container[i]) == typeid(new_politics))
			choice = 1;
		if (typeid(Container[i]) == typeid(new_entertainment))
			choice = 2;
		if (typeid(Container[i]) == typeid(new_celebrity))
			choice = 3;
		if (typeid(Container[i]) == typeid(new_events))
			choice = 4;
		cout << i + 1 << ") ";
		switch (choice)
		{
		case 1:
		{
			cout << *(dynamic_cast<politics *> (&Container[i]));
			cout << endl;
		}
		break;
		case 2:
		{
			cout << *(dynamic_cast<entertainment *> (&Container[i]));
			cout << endl;
		}
		break;
		case 3:
		{
			cout << *(dynamic_cast<celebrity *> (&Container[i]));
			cout << endl;
		}
		break;
		case 4:
		{
			cout << *(dynamic_cast<events*> (&Container[i]));
			cout << endl;
		}
		break;
		cout << endl;
		}
	}

}
void show_concretic_type_news(my_stack<news > Container)
{
	cout << "1)Politics news" << endl;
	cout << "2)Entertainment news" << endl;
	cout << "3)Celebrity news" << endl;
	cout << "4)Events news" << endl;
	int choice = 0;
	while (choice > 4 || choice < 1)
	{
		cin >> choice;
		while (!cin.good())
		{
			cin.clear();
			cin.ignore();
			cout << "Input 1-4" << endl;
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			politics new_news;
			int i = 0;
			while (i < Container.stack_size())
			{
				if (typeid(Container[i]) == typeid(new_news))
				{

					cout << *(dynamic_cast<politics *> (&Container[i]));
					cout << endl;
				}
				i++;
			}
			break;
		}
		case 2:
		{
			int i = 0;
			entertainment new_news;
			while(i < Container.stack_size())
			{
				if (typeid(Container[i]) == typeid(new_news))
				{

					cout << *(dynamic_cast<entertainment *> (&Container[i]));
					cout << endl;
				}
				i++;
			}
			break;
		}
		case 3:
		{
			int i = 0;
			celebrity new_news;
			while (i < Container.stack_size())
			{
				if (typeid(Container[i]) == typeid(new_news))
				{
					cout << *(dynamic_cast<celebrity *> (&Container[i]));
					cout << endl;
				}
				i++;
			}
			break;
		}
		case 4:
		{
			int i = 0;
			events new_news;
			while (i < Container.stack_size())
			{
				if (typeid(Container[i]) == typeid(new_news))
				{
					cout << *(dynamic_cast<events*> (&Container[i]));
					cout << endl;
				}
				i++;
			}
			break;
		}
		default: cout << "Input 1-4" << endl;
			break;
		}
	}
}
void delete_news(my_stack<news > *Container)
{
	show_news(*Container);
	cout << "Input the number of the news to be deleted: ";
	int choice;
	cin >> choice;
	while (choice  < 1 || choice > Container->stack_size() || !cin.good())
	{
		cin.clear();
		cin.ignore();
		show_news(*Container);
		cout << "Input correct choice" << endl;
		cin >> choice;
	}
	Container->del_el((*(Container))[choice - 1]);
}
void short_news(my_stack<news > *Container)
{
	my_stack<news> copy = *Container;
	copy.short_name();
	show_news(copy);
	int choice;
	cout << "Save it? 1 - yes, 2 - no: ";
	cin >> choice;
	while (choice < 1 || choice >2 || !cin.good())
	{
		cin.clear();
		cin.ignore();
		show_news(copy);
		cout << "Input correct choice" << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		Container->short_name();
	}
	//delete copy;
}
void income(my_stack<news > Container)
{

	double summ = 0;

	while (!Container.isEmpty())
	{
		//(*(Container.Pop()))
		summ += Container.Pop().get_views();
	}
	summ *= profit;
	cout << "Profit: " << summ << '$';
	cout << endl;

}
void edit_news(my_stack<news> *Container)
{
	show_news(*Container);
	cout << "Input the number of the news to be edit: ";
	int choice;
	cin >> choice;
	while (choice  < 1 || choice > Container->stack_size() || !cin.good())
	{
		cin.clear();
		cin.ignore();
		show_news(*Container);
		cout << "Input correct choice" << endl;
		cin >> choice;
	}
	//Container->edit_el(Container[choice-1])
	Container->edit_el((*(Container))[choice - 1]);
}

void test_fun()
{
	my_pointer<int > ptr1 = new int(10);
	my_pointer<politics> ptr2 = new politics("adf", "dfsd", 123, "124");
	cout << *ptr1;
	cout << *ptr2;
}
int main()
{
	//test_fun();
	/*celebrity a;
	celebrity b;
	a = b;*/
	my_stack<news> *Container = new my_stack<news>;
	while (true)
	{

		int choice;
		menu();
		cin >> choice;
		while (!cin.good())
		{
			cin.clear();
			cin.ignore();
			cout << "Input 1-9" << endl;
			cin >> choice;
		}
		switch (choice)
		{
		case 1: 
			add_news(Container);
			break;
		case 2: 
			show_news(*Container);
			break; 
		case 3: 
			show_concretic_type_news(*Container);
			break;
		case 4: 
			edit_news(Container);
			break;
		case 5:
			delete_news(Container);
			break;
		case 6:
			short_news(Container);
			break;
		case 7:
			income(*Container);
			break;
		case 8:
			show_main_information(*Container);
			break;
		case 9:
			return EXIT_SUCCESS;
			break;
		default: cout << "Input 1-5" << endl;
		}
	}
}
