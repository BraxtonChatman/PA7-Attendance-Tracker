#pragma once
#include"Node.h"

template <class T>
class List {
public:
	//-structors
	List();
	~List();

	Node<T>* getHeadPtr();

	void insertAtFront(T &newData);


private:
	Node<T>* pHead;
};

template<class T>
Node<T>* List<T>::getHeadPtr()
{
	return this->pHead;
}


template<class T>
void List<T>::insertAtFront(T &newData)
{
	Node<T>* newNode = new Node<T>(newData);
	newNode->setNextPtr(pHead);
	pHead = newNode;
}

template<class T>
List<T>::List()
{
	pHead = nullptr;
}

template<class T>
List<T>::~List()
{
	Node<T>* pCurrent = pHead;
	Node<T>* pTrash = pHead;

	while (pCurrent != nullptr)
	{
		pTrash = pCurrent;
		pCurrent = pCurrent->getNextPtr();

		pTrash->~Node();
	}
}