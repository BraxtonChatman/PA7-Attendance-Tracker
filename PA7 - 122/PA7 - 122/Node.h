#pragma once
#include"Data.h"

template<class T>
class Node {
public:
	Node(T &copyData);
	~Node();

	Node<T>* getNextPtr();
	T& getData();
	void setNextPtr(Node<T>* nextNode);

private:
	T mData;
	Node<T>* pNext;
};


//getters 
template <class T>
Node<T>* Node<T>::getNextPtr()
{
	return this->pNext;
}

template <class T>
T& Node<T>::getData()
{
	return this->mData;
}


//copy constructor
template<class T>
Node<T>::Node(T &copyData)
{
	mData = copyData;
	pNext = nullptr;
}


template<class T>
void Node<T>::setNextPtr(Node<T>* nextNode)
{
	pNext = nextNode;
}

template<class T>
Node<T>::~Node()
{
	delete this;
}
