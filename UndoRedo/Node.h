#pragma once
#include <iostream>

template<typename> class LinkedList;
template<typename> class Stack;

template<typename T>
class Node 
{
	friend class LinkedList<T>;
	friend class Stack<T>;

public:

	Node(T value = T())
		: data(value), next(nullptr)
	{ }

private:
	T data;
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;
};