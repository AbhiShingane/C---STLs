#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include <string>
#include <list>
#include<iterator>
#include<cstddef>
#include <exception>

using namespace std;

struct ForwordListNode
{
	int data;
	struct ForwordListNode* next;
};

struct ForwordListNode* createNode(int data)
{
	struct ForwordListNode* t = new ForwordListNode;
	t->data = data;
	t->next = NULL;

	return t;
}


template <typename T>
class ForwordList
{
private:
	int size;
	struct ForwordListNode* m_headPtr;
	struct ForwordListNode* m_lastNodePtr;
	
	void increaseSize()
	{
		size++;
	}

	void decreaseSize()
	{
		size--;
	}

	int gSz()
	{
		return size;
	}

public:

	class traverser
	{
	public:
		
	//public:
		typedef traverser self_type;
		typedef ForwordListNode valueType;
		typedef ForwordListNode& refTyep;
		typedef ForwordListNode* pointer;
		typedef std::forward_iterator_tag traverser_category;
		pointer nodePtr;
		traverser(pointer pt) : nodePtr(pt){}
		T operator*() { return nodePtr->data; }
		bool operator== (const self_type& rhs) { return rhs.nodePtr == nodePtr; }
		bool operator!= (const self_type& rhs) { return rhs.nodePtr != nodePtr; }
		//refTyep operator->() { return this->nodePtr; }
		
		self_type operator++()
		{
			if (nodePtr)
			{
				nodePtr = nodePtr->next;
			}

			return *this;
		}

		self_type operator++ (int junk)
		{
			self_type i = *this;
			++* this;
			//this->nodePtr = this->nodePtr->next;
			return i;
		}

		//self_type operator++(int junk) { this->nodePtr = this->nodePtr->next;  return *this; }
	};

	ForwordList() {
		m_headPtr = NULL;
	}

	void pushfront(int item);
	void pushback(int item);
	void popfront();
	void popback();
	int getSize();
	void traverse();
	traverser Begin()
	{
		return traverser(m_headPtr);
	}
	traverser End()
	{
		return traverser(NULL);

	}
};

template <typename T>
void ForwordList<T>::pushfront(int dt)
{
	struct ForwordListNode *node = createNode(dt);
	if (m_headPtr == NULL)
	{
		m_headPtr = node;
		m_lastNodePtr = node;
	}
	else
	{
		node->next = m_headPtr;
		m_headPtr = node;
	}
	increaseSize();
	cout << "Node is inserted at First" << endl;
}

template <typename T>
void ForwordList<T>::pushback(int dt)
{
	struct ForwordListNode* node = createNode(dt);
	if (m_headPtr == NULL)
	{
		m_headPtr = node;
		m_lastNodePtr = node;
	}
	else
	{
		m_lastNodePtr->next = node;
		m_lastNodePtr = m_lastNodePtr->next;
	}
	increaseSize();
	cout << "Node is inserted at Last " << endl;
}

template <typename T>
void ForwordList<T>::popfront()
{
	if (gSz() < 1)
	{
		cout << "nothing to delete" << endl;
	}
	else
	{
		struct ForwordListNode* ptr = m_headPtr;
		m_headPtr = m_headPtr->next;
		delete ptr;
	}
	decreaseSize();
	cout << "Node is deleted from front" << endl;
}

template <typename T>
void ForwordList<T>::popback()
{
	if (gSz() < 1)
	{
		cout << "nothing to delete" << endl;
	}
	else
	{
		struct ForwordListNode* ptr = m_headPtr;
		while (ptr->next != m_lastNodePtr)
		{
			ptr = ptr->next;
		}

		ptr->next = NULL;
		m_lastNodePtr = ptr;
	}
	decreaseSize();
	cout << "Node is deleted from last " << endl;
}

template <typename T>
int ForwordList<T>::getSize()
{
	return gSz();
}

template <typename T>
void ForwordList<T>::traverse()
{
	struct ForwordListNode* ptr = m_headPtr;
	cout <<endl<< "Link list elements:   ";
	while (ptr != NULL)
	{
		cout << "  " << ptr->data;
		ptr = ptr->next;
	}
	cout << endl << endl;
	return;
}


int main()
{

	ForwordList<int> fNode;
	fNode.pushback(3);
	fNode.pushback(5);

	fNode.pushfront(10);
	fNode.pushfront(34);

	fNode.traverse();


	cout << "Elements :" << endl;
	for (ForwordList<int>::traverser ptr = fNode.Begin(); ptr != fNode.End(); ptr++)
	{
		cout << *ptr << endl;
	}


	return 0;
}
