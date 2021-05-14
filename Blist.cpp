template <typename K>
class Node
{
public:
	K data;
	Node* next;
	Node* prev;
public:
	Node(const K& e) : data(e), next(NULL), prev(NULL) {}
};


template <typename T>
class BLinkedlist
{
public:
	Node<T>* head;
	Node<T>* tail;
	int size;

	void insertInternal(T info, Node<T>* pos, int flag);
	Node<T>* GetElementPosn(T val);
	void incrSize()
	{
		size++;
	}
	void decrSize()
	{
		size--;
	}
	void deleteInternal(Node<T>* pos, int flag);
public:
	BLinkedlist() : head(NULL), tail(NULL), size(0) {}

	void pushBack(T info);
	void pushFront(T val);
	void insertAfter(T info, T pos);
	void Traverse();
	int GetSize();
	void deleteBack();
	void deleteFront();
	void deleteAtPos(T pos);
};


template <typename T>
void BLinkedlist<T>::insertInternal(T val, Node<T>* pos, int flag)
{
	Node<T>* newNode = new Node<T>(val);
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		if (head == pos && flag == 0)
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		else if (pos == tail && flag == 1)
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = tail->next;
		}
		else
		{
			newNode->next = pos->next;
			pos->next = newNode;
			newNode->prev = pos;
			newNode->next->prev = newNode;
		}
	}

	incrSize();
	return;
}

template <typename T>
Node<T>* BLinkedlist<T>::GetElementPosn(T val)
{
	Node<T>* result = NULL;
	if (head != NULL)
	{
		Node<T>* ptr = head;
		while (ptr->data != val)
		{
			ptr = ptr->next;
		}

		result = ptr;
	}
	
	return result;
}


template <typename T>
void BLinkedlist<T>::deleteInternal(Node<T>* pos, int flag)
{

	if (flag == 0)
	{
		Node<T>* ptr = head;
		head = head->next;
		head->prev = NULL;
		delete ptr;
	}
	else if (flag == 1)
	{
		Node<T>* ptr = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete ptr;
	}
	else
	{
		Node<T>* ptr = pos;
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete ptr;
	}
	decrSize();
	return;
}


template <typename T>
void BLinkedlist<T>::pushBack(T val)
{
	insertInternal(val, tail, 1);
	cout << "element is added at back " << endl;
}

template <typename T>
void BLinkedlist<T>::pushFront(T val)
{
	insertInternal(val, head, 0);
	cout << "element added at front " << endl;
}


template <typename T>
void BLinkedlist<T>::insertAfter(T val, T pos)
{
	Node<T>* RefNode = GetElementPosn(pos);
	insertInternal(val, RefNode, 2);
	cout << "element added after given position " << endl;
}

template <typename T>
void BLinkedlist<T>::deleteFront()
{
	if (GetSize() > 0)
	{
		deleteInternal(head, 0);
		cout << "element is delete from Front" << endl;
	}
	else
	{
		cout << "No element is delete" << endl;
	}

	return;
}


template <typename T>
void BLinkedlist<T>::deleteBack()
{
	if (GetSize() > 0)
	{
		deleteInternal(tail, 1);
		cout << "element is deleted from back" << endl;
	}
	else
	{
		cout << "No element is delete" << endl;
	}

	return;
}


template <typename T>
void BLinkedlist<T>::deleteAtPos(T pos)
{
	if (GetSize() > 0)
	{
		Node<T>* refNode = GetElementPosn(pos);
		deleteInternal(refNode, 2);
		cout << "element is delete from position" << endl;
	}
	else
	{
		cout << "No element is delete" << endl;
	}

	return;
}


template<typename T>
void BLinkedlist<T>::Traverse()
{
	Node<T>* ptr = head;

	cout << "=====================================================================" << endl;
	cout << "From left to right:  " << endl;
	while (ptr != NULL)
	{
		cout << " " << ptr->data;
		ptr = ptr->next;
	}
	cout << endl;

	cout << "=====================================================================" << endl;
	cout << "From right to left:  " << endl;
	ptr = tail;
	while (ptr != NULL)
	{
		cout << " " << ptr->data;
		ptr = ptr->prev;
	}
	cout << endl;

	cout << "=====================================================================" << endl;

	return;
}

template <typename T>
int BLinkedlist<T>::GetSize()
{
	return size;
}















int main()
{
	BLinkedlist<string> obj;

	obj.pushBack("10");
	obj.pushBack("20");
	obj.pushBack("30");
	obj.Traverse();
	obj.pushFront("40");
	obj.pushFront("50");
	obj.Traverse();
	
	obj.insertAfter("60", "40");
	obj.Traverse();
	cout << obj.GetSize() << endl;

	obj.deleteBack();
	cout << obj.GetSize() << endl;

	obj.Traverse();

	obj.deleteFront();
	cout << obj.GetSize() << endl;

	obj.Traverse();


	return 0;
}
