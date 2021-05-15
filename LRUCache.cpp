const int PAGE_SIZE = 3;

template <typename T>
class ListNode
{
public:
	T data;
	ListNode<T>* prev;
	ListNode<T>* next;


	ListNode(const T& e) : data(e), prev(NULL), next(NULL) {}
};


template <typename T>
class List
{
	ListNode<T>* head;
	ListNode<T>* tail;
	

public:
	ListNode<T>* currentProcessdNode;
	T evictedobjValue;
	List() : head(NULL), tail(NULL), currentProcessdNode(NULL) {}

	// called when the element is not available
	void insert(T value)
	{
		ListNode<T>* newNode = new ListNode<T>(value);
		currentProcessdNode = newNode;
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = tail->next;
		}
	}

	//call when the node is avaialble in Cache 
	void AdjustNodeToEnd(ListNode<T>* refNode)
	{
		//Removing node from middle
		refNode->prev->next = refNode->next;
		refNode->next->prev = refNode->prev;

		//Adding node at end
		tail->next = refNode;
		refNode->prev = tail;
		refNode->next = NULL;
		tail = tail->next;

	}


	void ApplyPolicy(T val)
	{
		ListNode<T>* newNode = new ListNode<T>(val);
		currentProcessdNode = newNode;

		//Removing the Least recently used node from list
		ListNode<T>* tempPtr = head;
		evictedobjValue = head->data;
		head = head->next;
		head->prev = NULL;

		delete tempPtr;

		tail->next = newNode;
		newNode->prev = tail;
		tail = tail->next;

	}


	void traverse()
	{
		cout << endl << endl;
		ListNode<T>* ptr = head;
		while (ptr != NULL)
		{
			cout << "    " << ptr->data;
			ptr = ptr->next;
		}

		cout << endl;
	}
};


template <typename T>
class LRUCache
{
private:
	int m_totalcacheMiss;
	int m_totalcacheHits;
	int m_noOfPagesAvailable;
	map<T, ListNode<T>*> m_hTable;
	List<T> listobj;

	
public:
	LRUCache() 
	{
		m_noOfPagesAvailable = 0;
		m_totalcacheMiss = 0;
		m_totalcacheHits = 0;
	}

	void addData(T value)
	{
		if (m_hTable.find(value) != m_hTable.end())
		{
			
			listobj.AdjustNodeToEnd(m_hTable[value]);
			m_totalcacheHits += 1;
		}
		else
		{
			if (m_hTable.size() < PAGE_SIZE)
			{
				listobj.insert(value);
				
			}
			else //Apply eviction policy
			{
				listobj.ApplyPolicy(value);
			}
			ListNode<T>* curNodeAddr = listobj.currentProcessdNode;
			//removing the old entry from map
			m_hTable.erase(listobj.evictedobjValue);
			m_hTable.insert(make_pair(value, curNodeAddr));
			m_totalcacheMiss += 1;
		}
	}

	void GetTotalCacheMiss()
	{
		return m_totalcacheMiss;
	}

	void GetTotalCacheHits()
	{
		return m_totalcacheHits;
	}

	void traverseCache()
	{
		listobj.traverse();
	}
};



int main()
{
	LRUCache<int> obj;

	obj.addData(2);
	obj.addData(3);
	obj.addData(5);

	obj.traverseCache(); 
	obj.addData(7);
	obj.traverseCache();
	obj.addData(5);

	obj.traverseCache();

	return 0;
}
