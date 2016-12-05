#include <iostream>

template <class Type> class CircList;
template <class Type> class CircListIterator;

template <class Type>
class ListNode {
	friend class CircList<Type>;
	friend class CircListIterator<Type>;
private:
	Type data;
	ListNode *link;
	ListNode(Type);
	ListNode() {};
};

template <class Type>
ListNode<Type>::ListNode(Type element)
{
	data = element;
	link = 0;
}

template <class Type>
class CircList {
	friend class CircListIterator<Type>;
public:
	CircList() { first = new ListNode<Type>; first->link = first; };
	void Insert(Type);
	void Delete(Type);
	int Length();
	Type AtNth(int n);
	void DeleteAll(int count, Type data);
private:
	ListNode<Type> *first;
};

template <class Type>
void CircList<Type>::Insert(Type k)
{
	ListNode<Type> *newnode = new ListNode<Type>(k);
	newnode->link = first->link;
	first->link = newnode;
}

template <class Type>
void CircList<Type>::Delete(Type k)
{
	ListNode<Type> *previous = first;
	ListNode<Type> *current = first->link;
	for (; (current != first) && (current->data != k);
		previous = current, current = current->link);
	if (current != first)
	{
		previous->link = current->link;
		delete current;
	}
}

template<class Type>
inline int CircList<Type>::Length()
{
	int i = 0;
	ListNode<Type> *node = this->first;
	while (node->link != this->first)
	{
		++i;
		node = node->link;
	}
		
	/*
	CircListIterator<Type> li(*this);
	if (!li.NotNull())
		return 0;
	while (li.NextNotNull())
	{
		i++; li.Next();
	}
	*/
	return i;
}

template<class Type>
inline Type CircList<Type>::AtNth(int n)
{
	int i = 0;
	ListNode<Type> *node = this->first->link;
	while (node != this->first)
	{
		if (i == n)
			return node->data;
		++i;
		node = node->link;
	}
	return Type();
}

template<class Type>
inline void CircList<Type>::DeleteAll(int count, Type data)
{
	ListNode<Type> *previous = first;
	ListNode<Type> *current = first->link;
	while (current != first && count != 0)
	{
		if (current->data == data)
		{
			previous->link = current->link;
			delete current;
			current = previous->link;
			--count;
		}
		else
		{
			previous = current;
			current = current->link;
		}
	}
}

template <class Type>
class CircListIterator {
public:
	CircListIterator(const CircList<Type>& l) : list(l) { current = l.first->link; }
	Type* First();
	Type* Next();
	bool NotNull();
	bool NextNotNull();
private:
	const CircList<Type> &list;
	ListNode<Type>* current;
};

template <class Type>
Type* CircListIterator<Type>::First() {
	if (current != list.first) return &current->data;
	else return 0;
}

template <class Type>
Type* CircListIterator<Type>::Next() {
	current = current->link;
	if (current != list.first) return &current->data;
	else return 0;
}

template <class Type>
bool CircListIterator<Type>::NotNull()
{
	if (current != list.first) return true;
	else return false;
}

template <class Type>
bool CircListIterator<Type>::NextNotNull()
{
	if (current->link != list.first) return true;
	else return false;
}

int sum(CircList<int> l)
{
	CircListIterator<int> li(l);
	if (!li.NotNull()) return 0;
	int retvalue = *li.First();
	while (li.NextNotNull())
		retvalue += *li.Next();
	return retvalue;
}



//template <class Type>
std::ostream& operator<<(std::ostream& os, CircList<char>& l)
{
	CircListIterator<char> li(l);
	if (!li.NotNull()) return os;
	os << *li.First() << std::endl;
	while (li.NextNotNull())
		os << *li.Next() << std::endl;
	return os;
}
