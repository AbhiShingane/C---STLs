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

template <typename T>
class SStack
{
private:
	int size;
	vector<T> container;

public:
	SStack() { size = 0; }

	bool IsEmpty();
	T GetTop();
	void insert(T element);
	void RemoveTop();
	int getSize();
};

template <typename T>
bool SStack<T>::IsEmpty()
{
	if (container.size() == 0)
		return true;
	else
		return false;
}

template <typename T>
T SStack<T>::GetTop()
{
	T element;
	if (getSize() > 0)
	{
	   element = container.back();
	}

	return element;
}

template <typename T>
int SStack<T>::getSize()
{
	size = container.size();

	return size;
}

template <typename T>
void SStack<T>::insert(T element)
{
	container.push_back(element);
}


template <typename T>
void SStack<T>::RemoveTop()
{
	container.pop_back();
}

int main()
{
	SStack<string> stkobj;

	stkobj.insert("Hello");
	stkobj.insert("abc");
	stkobj.insert("xyz");

	cout << stkobj.getSize() << endl;;

	cout << stkobj.GetTop() << endl;

	stkobj.RemoveTop();

	cout << stkobj.GetTop() << endl;

	return 0;

}
