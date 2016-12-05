#include <iostream>

template <typename T> class DblList;

template <typename T>
class DblListNode {
	template <typename U> friend class DblList;
private:
	int data;
	DblListNode *llink, *rlink;
};

template <typename T>
class DblList {
public:
	DblList() { first = last = NULL; }
	void Add(T data);
	void Insert(DblListNode*, DblListNode*);
	void Delete(DblListNode*);
	void Shift(char c, int n);
private:
	DblListNode<T> *first;  // points to head node
	DblListNode<T> *last;
};

template<typename T>
inline void DblList<T>::Add(T data)
{

}

template <typename T>
void DblList<T>::Insert(DblListNode<T> *p, DblListNode<T> *x)
// insert node @p@ to the right of node @x@
{
	p->llink = x; p->rlink = x->rlink;
	x->rlink->llink = p; x->rlink = p;
}

template <typename T>
void DblList<T>::Delete(DblListNode<T> *x)
{
	if (x == first) std::cerr << "Deletion of head node not permitted" << std:: endl;
	else {
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
		delete x;
	}
}

template <typename T>
inline void DblList::Shift(char c, int n)
{

}
