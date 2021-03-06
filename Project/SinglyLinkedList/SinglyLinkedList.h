#pragma once
template <typename T>
class SinglyLinkedList
{
private:
	class Iterator;

	template <typename T>
	class Node
	{
	public:
		Node* Next;
		T Data;

		Node(T data = T(), Node* next = nullptr)
		{
			Data = data;
			Next = next;
		}
	};

	Node<T>* _head;
public:
	class Iterator
	{
	private:
		Node<T>* _current;
	public:
		Iterator(Node<T>* node)
		{
			_current = node;
		}

		Iterator& operator++ (int)
		{
			_current = _current->Next;
			return *this;
		}
		Iterator& operator++ ()
		{
			_current = _current->Next;
			return *this;
		}
		Iterator& operator+ (int n)
		{
			for (int i = 0; i < n; ++i)
			{
				_current = _current->Next;
			}
			return *this;
		}
		bool operator!= (const Iterator& it)
		{
			return _current != it._current;
		}
		bool operator== (const Iterator& it)
		{
			return _current == it._current;
		}
		T& operator*()
		{
			return _current->Data;
		}
	};

	Iterator begin() { return _head; }
	Iterator end() { return nullptr; }

	SinglyLinkedList();
	~SinglyLinkedList();
	T& Front();
	void PushBack(T data);
	void PushFront(T data);
	void InsertAfter(T data, Iterator it);
	void EraseAfter(Iterator it);
	void PopFront();
	void Merge(SinglyLinkedList<T> &list);
	void Clear();
	int Size();
	bool Empty();
};

template<typename T>
inline SinglyLinkedList<T>::SinglyLinkedList()
{
	_head = nullptr;
}

template<typename T>
inline SinglyLinkedList<T>::~SinglyLinkedList()
{
	Clear();
}

template<typename T>
inline T& SinglyLinkedList<T>::Front()
{
	return _head->Data;
}

template<typename T>
inline void SinglyLinkedList<T>::PushBack(T data)
{
	if (_head == nullptr)
	{
		_head = new Node<T>(data);
	}
	else
	{
		Node<T>* node = _head;
		while (node->Next != nullptr)
		{
			node = node->Next;
		}
		node->Next = new Node<T>(data);
	}
}

template<typename T>
inline void SinglyLinkedList<T>::PushFront(T data)
{
	_head = new Node<T>(data, _head);
}

template<typename T>
inline void SinglyLinkedList<T>::InsertAfter(T data, Iterator it)
{
	Node<T>* node = _head;

	while (it != node)
	{
		node = node->Next;
	}
	
	Node<T>* newNode = new Node<T>(data, node->Next);
	node->Next = newNode;
}

template<typename T>
inline void SinglyLinkedList<T>::PopFront()
{
	Node<T>* oldHead = _head;
	_head = _head->Next;
	delete oldHead;
}

template<typename T>
inline void SinglyLinkedList<T>::EraseAfter(Iterator it)
{
	Node<T>* node = _head;
	while (it != node)
	{
		node = node->Next;
	}
	Node<T>* toErase = node->Next;
	node->Next = toErase->Next;
	delete toErase;
}

template<typename T>
inline void SinglyLinkedList<T>::Merge(SinglyLinkedList<T> &list)
{
	auto it = list.begin();
	while (it != list.end())
	{
		PushBack(*it);
		it++;
	}
}

template<typename T>
inline int SinglyLinkedList<T>::Size()
{
	if (_head == nullptr)
	{
		return 0;
	}
	else
	{
		int size = 1;
		Node<T>* current = _head;
		while (current->Next != nullptr)
		{
			size++;
			current = current->Next;
		}
		return size;
	}
}

template<typename T>
inline bool SinglyLinkedList<T>::Empty()
{
	return _head == nullptr;
}

template<typename T>
inline void SinglyLinkedList<T>::Clear()
{
	while (!Empty())
	{
		PopFront();
	}
}