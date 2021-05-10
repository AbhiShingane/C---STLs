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

//vector implementation with iterator

template <typename T>
class VectorClass
{
private:
	T* m_arr;
	int m_currentIndex;
	int m_capacity;

public:
	VectorClass()
	{
		m_arr = new T[1];
		m_capacity = 1;
		m_currentIndex = 0;
	}


	class Visitor
	{
	public:
		typedef Visitor self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::forward_iterator_tag visitor_category;
		typedef int difference_type;
		Visitor(pointer pt) :ptr(pt) {}
		self_type operator++() { self_type i = *this; ptr++; return i; }
		self_type operator++(int junk) { ptr++; return *this; }
		reference operator*() { return *ptr; }
		reference operator->() { return ptr; }
		bool operator!= (const self_type& rhs) { return this->ptr != rhs.ptr; }
		bool operator== (const self_type& rhs) { return this->ptr == rhs.ptr; }
	private:
		pointer ptr;
	};




	void pushAtEnd(int element)
	{
		T* temp;
		if (m_currentIndex == m_capacity)
		{
			temp = new T[2 * m_capacity];
			for (int i = 0; i < m_capacity; i++)
			{
				temp[i] = m_arr[i];
			}

			delete[] m_arr;
			m_arr = temp;
			m_capacity = m_capacity * 2;
		}

		m_arr[m_currentIndex++] = element;
		cout << "Element is inserted at End" << endl;
	}

	void pushAtBegin(int element)
	{
		T* temp;
		if (m_currentIndex == m_capacity)
		{
			temp = new T[2 * m_capacity];
			for (int i = 0; i < m_capacity; i++)
			{
				temp[i] = m_arr[i];
			}

			delete[] m_arr;
			m_arr = temp;
			m_capacity = m_capacity * 2;
		}

		for (int i = m_currentIndex; i > 0; i--)
		{
			m_arr[i] = m_arr[i - 1];
		}

		m_arr[0] = element;

		m_currentIndex++;
		cout << "element inserted at Begining" << endl;

	}


	void deleteAtEnd()
	{
		if (m_capacity < 1)
			return;

		m_arr[m_currentIndex - 1] = -1;
		m_currentIndex--;

		cout << "Element is deleted from End" << endl;;
	}

	void deleteAtFront()
	{
		if (m_capacity < 1)
			return;

		for (int i = 1; i < m_currentIndex; i++)
		{
			m_arr[i - 1] = m_arr[i];
		}

		m_currentIndex--;

		cout << "Element is deleted from Front" << endl;;
	}

	Visitor begin()
	{
		return Visitor(m_arr);
	}

	Visitor End()
	{
		return Visitor(m_arr + m_currentIndex);
	}

	int size()
	{
		return m_currentIndex;
	}

	int capacity()
	{
		return m_capacity;
	}

	void traverse()
	{
		cout << "=================================================" << endl;
		cout << endl << "Array elements :  " << endl;
		for (int i = 0; i < m_currentIndex; i++)
		{
			cout << "    " << m_arr[i];
		}
		cout << endl;
		cout << "=================================================" << endl;
	}

	T& operator[](int index)
	{
		if (index >= m_currentIndex)
		{
			cout << "Invalid index" << endl;;
		}

		return m_arr[index];
	}
};




int main()
{
	VectorClass<int> v;
	v.pushAtEnd(1);
	v.pushAtEnd(2);
	v.traverse();
	v.pushAtEnd(10);
	v.pushAtEnd(15);
	v.pushAtEnd(17);
	v.pushAtEnd(95);
	v.pushAtEnd(105);
	v.traverse();
	v.pushAtBegin(200);
	v.traverse();
	v.pushAtBegin(200);
	v.traverse();

	v.deleteAtEnd();
	v.traverse();
	v.deleteAtEnd();
	v.traverse();
	v.deleteAtFront();
	v.traverse();
	v.deleteAtFront();
	v.traverse();

	cout << "size of vector : " << v.size() << endl;
	cout << "capacity of vector :" << v.capacity() << endl;

	//cout << "begin address " << v.begin() << " end address: " << v.End() << endl ;

	cout << v[3] << endl;

	v[4] = 10;

	v.traverse();

	cout << "Array Elements :  ";

	for (VectorClass<int>::Visitor it = v.begin(); it !=  v.End(); it++)
	{
		cout << "  " << *it;
	}
	

	return 0;
}
