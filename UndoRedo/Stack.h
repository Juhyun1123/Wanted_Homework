#pragma once
#include <iostream>
#include "Node.h"

/*
*  스택
*/

template<typename T>
class Stack
{

public:
	Stack()
	{
		head = new Node<T>();
	}

	~Stack()
	{
		Clear();

		delete head;
		head = nullptr;
	}

	/// <summary>
	/// 스택 비었는지 확인
	/// </summary>
	/// <returns>비었는지 여부</returns>
	bool IsEmpty() const 
	{
		return (head->next == nullptr);
	}

	/// <summary>
	/// 데이터 입력 
	/// </summary>
	/// <param name="value">입력 데이터 (L value)</param>
	void Push(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head->next;
		head->next = newNode;
	}

	/// <summary>
	/// 데이터 입력 
	/// </summary>
	/// <param name="value">입력 데이터 (R value)</param>
	void Push(T&& value)
	{
		Node<T>* newNode = new Node<T>(std::move(value));
		newNode->next = head->next;
		head->next = newNode;
	}

	/// <summary>
	/// 데이터 반환
	/// </summary>
	/// <returns> 데이터 </returns>
	T Pop()
	{
		T outputData;
		
		if (Pop(outputData))
		{
			return outputData;
		}
		else
		{
			return T();
		}
	}

	/// <summary>
	/// 데이터 반환
	/// </summary>
	/// <param name="outputValue"> 반환 받을 변수</param>
	/// <returns> 데이터 반환 성공 여부</returns>
	bool Pop(T& outputValue)
	{
		if (IsEmpty())
		{
			std::cout << "Stack is empty\n";
			return false;
		}

		Node<T>* outputNode = head->next;

		head->next = outputNode->next;
		outputValue = std::move(outputNode->data);

		delete outputNode;
		outputNode = nullptr;

		return true;
	}


	/// <summary>
	/// 스택의 가장 위 데이터 획득
	/// </summary>
	/// <returns>가장 위 데이터</returns>
	T Top()
	{
		T topData;

		if (Top(topData))
		{
			return topData;
		}
		else
		{
			return T();
		}
	}

	/// <summary>
	/// 스택의 가장 위 데이터 획득
	/// </summary>
	/// <param name="topValue">입력 받을 변수</param>
	/// <returns>입력 성공 여부</returns>
	bool Top(T& topValue)
	{
		if (IsEmpty())
		{
			std::cout << "Stack Is Empty\n";
			return false;
		}

		topValue = head->next->data;

		return true;
	}

	/// <summary>
	/// 스택을 비웁니다.
	/// </summary>
	void Clear()
	{
		Node<T>* deleteNode;

		while (!IsEmpty())
		{
			deleteNode = head->next;
			head->next = deleteNode->next;

			delete deleteNode;
			deleteNode = nullptr;
		}
	}

	void Print()
	{
		std::cout << "Stack List : ";

		if (IsEmpty())
		{
			std::cout << "Empty \n";
			return;
		}

		PrintRecursion(head->next);
	}

private:
	void PrintRecursion(Node<T>* node)
	{
		// 다른데에서 쓸때는 쓰면 안됨 
		std::cout << *(node->data);

		if (node->next == nullptr) 
		{
			std::cout << "\n";
			return; 
		}
		
		std::cout << " -> ";
		PrintRecursion(node->next);
	}

private:
	Node<T>* head = nullptr;



};