#include <iostream>

class Exception
{
private:

public:
	const std::string err = "Error";
	std::string virtual what() = 0;
};

class NullMemory :public Exception
{
public:
	const std::string mem_err = " of memory";
	std::string what() override
	{
		return err + mem_err;
	}
};

class OutOfBound :public Exception
{
public:
	const std::string bound_err = ". Index out of bound";
	std::string what() override
	{
		return err + bound_err;
	}
};

template<typename T>
class TwoLinkedList
{
	class Node;
public:
	class Iterator;
	
	TwoLinkedList() :head(nullptr), tail(nullptr), count(0) {};
	~TwoLinkedList();

	void insert_front(T data);
	void del(int order);
	void show();

	Iterator begin()
	{
		return Iterator(head);
	}

	Iterator end()
	{
		return Iterator(tail);
	}

	class Iterator
	{
	public:
		Iterator(Node* current) :current(current) {}

		T& operator*() { return current->data; }
		Node* operator->() { return current; }

		Iterator& operator++() { current = current->next; return *this; }
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

		Iterator& operator--() { current = current->prev; return *this; }
		Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

		Iterator& operator=(Node* pNode)
		{
			this->current = pNode;
			return *this;
		}

		bool operator!=(const Iterator& iterator)
		{
			return current != iterator.current;
		}


	protected:
		Node* current;
	};

protected:
	class Node
	{	
	public:
		friend class TwoLinkedList;

		Node() : data(), prev(nullptr), next(nullptr) {};
		Node(T data, Node* next, Node* prev) :data(data), next(next), prev(prev) {};

	protected:
		T data;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;
	int count;
};

template<typename T>
TwoLinkedList<T>::~TwoLinkedList()
{
	while (head)
	{
		tail = head->next;
		delete head;
		head = tail;
	}
}

template<typename T>
void TwoLinkedList<T>::show()
{
	try {
		if (!head)
			throw NullMemory();
	}
	catch (Exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return;
	}

	Node* tmp = head;
	while (tmp)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

template<typename T>
void TwoLinkedList<T>::del(int order)//в идеале , с нуля
{
	try
	{
		if (!head)
			throw NullMemory();
		else if (order > count || order < 0)
			throw OutOfBound();
	}
	catch (Exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return;
	}
	

	Node* tmp = head;

	if (order == 0)
	{
		head = head->next;
		if(head)
		head->prev = nullptr;
	}
	else
	{
		while (order > 0)
		{
			tmp = tmp->next;
			order--;
		}
		if (!tmp)
			throw NullMemory();


		if (tmp->next)
		{
			Node* t = tmp->next;
			t->prev = tmp->prev;
			tmp->prev->next = t;
		}
		else
		{
			tmp->prev->next = nullptr;
		}
	}
	delete tmp;
	count--;
}

template<typename T>
void TwoLinkedList<T>::insert_front(T data)
{
	Node* tmp = new Node();

	tmp->data = data;
	
	if (head == nullptr) {
		tail = head = tmp;
		return;
	}
	head->prev = tmp;
	tmp->next = head;
	head = tmp;

	count++;
}

int main()
{
	TwoLinkedList<int> list;
	
	try
	{
		list.insert_front(2);
		list.insert_front(3);
		list.insert_front(4);

		list.show();
		for (auto it = list.begin(); it != nullptr; it++)
		{
			std::cout << *it << " ";
		}

		std::cout << std::endl;

		for (auto it = list.end(); it != nullptr; it--)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		list.del(0);
		list.del(1);
		list.show();

	}
	catch (Exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}