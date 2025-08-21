#pragma once

/*
* 큐
*/

template<typename T>
class Queue
{

public:
	Queue():
		array(nullptr),
		capacity(8),
		front(0),
		rear(0)
	{ 
		array = new T[capacity];
	}

	~Queue() 
	{ 
		delete[] array;
		array = nullptr;
	}

	bool IsEmpty()
	{
		return (front == rear);
	}

	bool IsFull()
	{
		return (next(rear) == front);
	}

	void Enqueue(const T& value)
	{
		if (IsFull()) { Resize(); }

		array[rear] = value;
		rear = next(rear);
	}

	void Enqueue(T&& value) 
	{ 
		if (IsFull()) { Resize(); }

		array[rear] = std::move(value);
		rear = next(rear);
	}

	T Dequeue()
	{
		T outputData;

		if (Dequeue(outputData))
		{
			return outputData;
		}
		else 
		{
			return T();
		}
	}

	bool Dequeue(T& outputValue) 
	{ 
		if (IsEmpty())
		{
			std::cout << "Queue is empty\n";
			return false;
		}

		outputValue = std::move(array[front]);
		front = next(front);

		return true;
	}

	T Peek()
	{
		T outputData;

		if (!IsEmpty())
		{
			return array[front];
		}
		else
		{
			std::cout << "Queue is empty\n";
			return T();
		}
	}

	bool Peek(T& outputValue)
	{
		if (IsEmpty())
		{
			std::cout << "Queue is empty\n";
			return false;
		}

		outputValue = array[front];
		
		return true;
	}

	void Clear() 
	{
		front = 0;
		rear = 0;
	}

private:
	void Resize()
	{
		int newCapacity = capacity * 2;
		T* newArray = new T[newCapacity];

		int index = 0;

		while (!IsEmpty())
		{
			newArray[index] = std::move(array[front]);

			++index;
			front = next(front);
		}

		delete[] array;

		array = newArray;
		capacity = newCapacity;
		front = 0;
		rear = index;
	}

	inline int next(int index) 
	{
		return (index + 1) % capacity;
	}

	inline int back(int index) 
	{
		return (index + capacity - 1) % capacity;
	}

private:
	T* array = nullptr;

	int capacity = 0;
	int front = 0;
	int rear = 0;

};
