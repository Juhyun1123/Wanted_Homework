#pragma once
#include <iostream>
#include "Node.h"

/*
*  ����
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
	/// ���� ������� Ȯ��
	/// </summary>
	/// <returns>������� ����</returns>
	bool IsEmpty() const 
	{
		return (head->next == nullptr);
	}

	/// <summary>
	/// ������ �Է� 
	/// </summary>
	/// <param name="value">�Է� ������ (L value)</param>
	void Push(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head->next;
		head->next = newNode;
	}

	/// <summary>
	/// ������ �Է� 
	/// </summary>
	/// <param name="value">�Է� ������ (R value)</param>
	void Push(T&& value)
	{
		Node<T>* newNode = new Node<T>(std::move(value));
		newNode->next = head->next;
		head->next = newNode;
	}

	/// <summary>
	/// ������ ��ȯ
	/// </summary>
	/// <returns> ������ </returns>
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
	/// ������ ��ȯ
	/// </summary>
	/// <param name="outputValue"> ��ȯ ���� ����</param>
	/// <returns> ������ ��ȯ ���� ����</returns>
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
	/// ������ ���� �� ������ ȹ��
	/// </summary>
	/// <returns>���� �� ������</returns>
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
	/// ������ ���� �� ������ ȹ��
	/// </summary>
	/// <param name="topValue">�Է� ���� ����</param>
	/// <returns>�Է� ���� ����</returns>
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
	/// ������ ���ϴ�.
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
		// �ٸ������� ������ ���� �ȵ� 
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