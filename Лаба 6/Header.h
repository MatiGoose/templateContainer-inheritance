#include <iostream>

using namespace std;

class news
{
protected:
	char * date;
	char * name;
	int views;
public:
	friend ostream& operator<<(ostream& out, const news & news);
	news();
	news(char const *Date, char const* Name, int Views);
	news(news const & n);
	virtual~news(); // см пример
	news operator = (const news & n);
	void set_date(char const * Date);
	void set_name(char const * Name);
	void set_views(int Views);
	
	char const *get_date();
	char const *get_name();
	int	get_views();
	void change_string();
	virtual void print(ostream &s);
};


class politics : public virtual news
{
protected:
	char * country;
public:
	friend ostream& operator <<(ostream& out,const politics & news);

	politics(char const * Date, char const * Name, int Views, char const * Country);
	politics(politics const & n);
	politics();
	~politics();
	politics operator = (const politics & n);

	void print(ostream &s);
	void set_country(char const * Country);
	char const * get_country();

};

class entertainment : public virtual news
{
protected:
	char * sphere;
public:
	void print(ostream &s);
	entertainment operator = (const entertainment & n);

	friend ostream& operator <<(ostream& out, const entertainment & news);

	entertainment(char const * Date, char const * Name, int Views, char const * Sphere);
	entertainment(entertainment const & n);
	entertainment();
	~entertainment();

	void set_sphere(char const * Sphere);
	char const * get_sphere();


};

class celebrity : public   politics, public  entertainment
{
	char * person;	
	int subscribers;
public:
	celebrity();
	void print(ostream &s);
	friend ostream& operator <<(ostream& out, const celebrity & news);
	celebrity operator = (const celebrity & n);

	celebrity(char const * Date, char const * Name, int Views, char const * Sphere, char const * Person, char const * Country, int Subscribers);
	celebrity(celebrity const & n);
	void set_person(char const * Person);
	char const * get_person();
	void set_subscribers(int Subscribers);
	int get_subscribers();
	~celebrity();

};

class events : public entertainment
{
	char * concerts;
	double price;
public:
	events operator = (const events & n);

	events();
	void print(ostream &s);
	friend ostream& operator <<(ostream& out, const events & news);
	events(char const * Date, char const * Name, int Views, char const * Sphere, char const * Concerts, double Price);
	events(events const & n);
	void set_concerts(char const * Сoncerts);
	char const * get_concerts();
	void set_price(double Price);
	double get_price();
	~events();
};
istream& operator>>(istream& in, news& news);
istream& operator>>(istream& in,  politics& politics);
istream& operator>>(istream& in,  entertainment& entertainment);
istream& operator>>(istream& in,  celebrity& celebrity);
istream& operator>>(istream& in,  events& events);

//template <typename T>
//class Stack
//{
//private:
//	T *stackPtr;                      // указатель на стек
//	const int size;                   // максимальное количество элементов в стеке
//	int top;                          // номер текущего элемента стека
//public:
//	Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
//	Stack(const Stack<T> &);          // конструктор копирования
//	~Stack();                         // деструктор
//
//	inline void push(const T &);     // поместить элемент в вершину стека
//	inline T pop();                   // удалить элемент из вершины стека и вернуть его
//	inline void printStack();         // вывод стека на экран
//	inline const T &Peek(int) const; // n-й элемент от вершины стека
//	inline int getStackSize() const;  // получить размер стека
//	inline T *getPtr() const;         // получить указатель на стек
//	inline int getTop() const;        // получить номер текущего элемента в стеке
//};


template <typename T>
class my_stack
{
public:
	my_stack() :top(NULL)
	{

	}
	~my_stack()
	{
		while (top)
		{
			Node *pv = top;
			top = top->p;
			delete pv;
		}

	}
	my_stack operator = (const my_stack &st)//если мы приравниваем несколько раз
	{
		Node* tmp = st.top;
		if (tmp)
		{
			Node* newNode = new Node();
			newNode->news_st = T(tmp->news_st);
			this->top = newNode;
			while (tmp->p)
			{
				tmp = tmp->p;
				newNode->p = new Node();
				newNode = newNode->p;
				newNode->news_st = T(tmp->news_st);
			}
		}
		size = st.size;
		return *this;
	}
	void Push(T newss)
	{
		Node *pv = new Node;
		pv->news_st = newss;
		pv->p = top;
		top = pv;
		size++;
	}
	T Pop()
	{
		if (isEmpty())
		{
			news n;
			return n;
		}
		T temp = top->news_st;
		Node *pv = top;
		top = top->p;
		delete pv;
		size--;
		return temp;
	}
	bool isEmpty()
	{
		return top ? false : true;
	}
	void Print()
	{
		while (top)
		{
			std::cout << Pop() << ' ' << endl;
		}

		std::cout << std::endl;
	}
	T  operator[](int index)
	{
		int i = 0;
		my_stack *tmp = new my_stack(*this);
		while (!tmp->isEmpty())
		{
			if (i == index)
				return tmp->Pop();
			tmp->Pop();
			i++;
		}
		delete tmp;
		news n;
		return n;
	}

	int stack_size()
	{
		return size;
	}
	my_stack  short_name()
	{
		my_stack* newSt = new my_stack(*this);
		Node* tmp = newSt->top;
		while (tmp)
		{
			tmp->news_st.change_string();
			tmp = tmp->p;
		}
		return  *newSt;
	}
	my_stack(my_stack const & obj)
	{

		Node* tmp = obj.top;
		if (tmp)
		{
			Node* newNode = new Node();
			//T - news *(не может быть объектом)
			//typedef typeid(*tmp->news_st) my_type;
			//newNode->news_st = new my_type(*tmp->news_st)
			//*newNode->news_st = *(tmp->news_st);
			newNode->news_st = (tmp->news_st);
			this->top = newNode;
			while (tmp->p)
			{
				tmp = tmp->p;
				newNode->p = new Node();
				newNode = newNode->p;
				//*newNode->news_st = *T(tmp->news_st);
				newNode->news_st = T(tmp->news_st);
			}
		}
		size = obj.size;
	}
	void del_el(T n)
	{

		if (&n == &top->news_st)
		{
			Node * tmp = top;
			top = top->p;
			delete tmp;
			size--;
			return;
		}
		Node * tmp_prev = top;
		while (!isEmpty())
		{
			if (&n == &tmp_prev->p->news_st)
			{
				Node * tmp = tmp_prev->p;
				tmp_prev->p = tmp_prev->p->p;
				delete tmp;
				size--;
				return;
			}
			tmp_prev = tmp_prev->p;
		}
		throw "Not found!";
		
	}
	void edit_el(T n)
	{
		if (&n == &top->news_st)
		{
			int choice;
			politics new_politics;
			entertainment new_entertainment;
			celebrity new_celebrity;
			events new_events;
			if (typeid(n) == typeid(new_politics))
				choice = 1;
			if (typeid(n) == typeid(new_entertainment))
				choice = 2;
			if (typeid(n) == typeid(new_celebrity))
				choice = 3;
			if (typeid(n) == typeid(new_events))
				choice = 4;
			switch (choice)
			{
			case 1:
			{
				cin >> *(dynamic_cast<politics *> (&top->news_st));
				cout << endl;
			}
			break;
			case 2:
			{
				cin >> *(dynamic_cast<entertainment *> (&top->news_st));
				cout << endl;
			}
			break;
			case 3:
			{
				cin >> *(dynamic_cast<celebrity *> (&top->news_st));
				cout << endl;
			}
			break;
			case 4:
			{
				cin >> *(dynamic_cast<events*> (&top->news_st));
				cout << endl;
			}
			break;
			cout << endl;
			}
			return;
		}
		Node * tmp_prev = top;
		while (!isEmpty())
		{
			if (&n == &tmp_prev->p->news_st)
			{
				int choice;
				politics new_politics;
				entertainment new_entertainment;
				celebrity new_celebrity;
				events new_events;
				if (typeid(n) == typeid(new_politics))
					choice = 1;
				if (typeid(n) == typeid(new_entertainment))
					choice = 2;
				if (typeid(n) == typeid(new_celebrity))
					choice = 3;
				if (typeid(n) == typeid(new_events))
					choice = 4;
				switch (choice)
				{
				case 1:
				{
					cin >> *(dynamic_cast<politics *> (&tmp_prev->p->news_st));
					cout << endl;
				}
				break;
				case 2:
				{
					cin >> *(dynamic_cast<entertainment *> (&tmp_prev->p->news_st));
					cout << endl;
				}
				break;
				case 3:
				{
					cin >> *(dynamic_cast<celebrity *> (&tmp_prev->p->news_st));
					cout << endl;
				}
				break;
				case 4:
				{
					cin >> *(dynamic_cast<events*> (&tmp_prev->p->news_st));
					cout << endl;
				}
				break;
				cout << endl;
				}
				return;
			}
			tmp_prev = tmp_prev->p;
		}
	}

private:
	struct Node
	{
		T news_st;
		Node *p;
	};
	int size = 0;
	Node *top;
};



template <typename T>
class my_pointer
{
public:

	my_pointer(T *p)
	{
		this->ptr = p;
	}
	~my_pointer()
	{
		delete ptr;
	}
	T& operator *()
	{
		return *ptr;
	}
private:
	T * ptr;
};