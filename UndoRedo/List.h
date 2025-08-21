#pragma once
#include <iostream>

/*
*  ���� �迭 
*/

template<typename T>
class List
{

public:
	List() :
		capacity(4), size(0)
	{
		array = new T[capacity];
	}

	~List()
	{
		if (array)
		{
			delete[] array;
			array = nullptr;
		}
	}

	/// <summary>
	/// ���� �迭 ���� ������ ��ȯ
	/// </summary>
	/// <returns>���� �迭 ������</returns>
	int Size()
	{
		return size;
	}

	/// <summary>
	/// ���� �迭 ������� Ȯ��
	/// </summary>
	/// <returns>������� ����</returns>
	bool IsEmpty()
	{
		return (size == 0);
	}

	/// <summary>
	/// ���� �迭 �������� �� ������ �Է�
	/// </summary>
	/// <param name="data">�߰� ������</param>
	void Add(T&& data)
	{
		if (capacity <= size)
		{
			Resize();
		}

		array[size] = std::move(data);
		++size;
	}

	/// <summary>
	/// ���� �迭 �������� �� ������ �Է�
	/// </summary>
	/// <param name="data">�߰� ������</param>
	void Add(const T& data)
	{
		if (capacity <= size)
		{
			Resize();
		}

		array[size] = data;
		++size;
	}

	/// <summary>
	/// ���� �����Ϳ� ��ġ�ϴ� ������ �ϳ� ���� (�ߺ��� ���� �� ������ ����)
	/// </summary>
	/// <param name="data">���� ������</param>
	/// <returns>���� ����</returns>
	bool Delete(const T& data)
	{
		return DeleteAt(SearchIndex(data));
	}

	/// <summary>
	/// �ε��� ��� ������ ����
	/// </summary>
	/// <param name="data">���� �ε���</param>
	/// <returns>���� ����</returns>
	bool DeleteAt(const int index)
	{
		if (index < 0 || size <= index) { return false; }
		if (IsEmpty()) { return false; }

		array[index].~T();

		for (int i = index + 1; i < size; ++i)
		{
			array[i - 1] = std::move(array[i]);
		}

		--size;

		return true;
	}

	/// <summary>
	/// ���� �迭 ����
	/// </summary>
	void Clear()
	{
		for (int i = 0; i < size; ++i) { array[i].~T(); }
		size = 0;
	}

	/// <summary>
	/// �������� �ε��� ��ȯ (�ߺ��� ���� �� ������ �ε��� ��ȯ)
	/// </summary>
	/// <param name="data">�˻� ������</param>
	/// <returns>��ȯ ������ / ���н� -1</returns>
	int SearchIndex(const T& data) const
	{
		for (int i = 0; i < size; ++i)
		{
			if (data == array[i])
			{
				return i;
			}
		}

		return -1;
	}

	// ������ ���� �ε�
	const T& operator[](int index) const 
	{
		if (index < 0 || size <= index)
		{
			__debugbreak();
		}

		return array[index];
	}

private:

	/// <summary>
	/// ������ Ȯ��
	/// </summary>
	void Resize()
	{
		int newCapacity = capacity * 2;
		T* newArray = new T[newCapacity];

		for (int i = 0; i < size; ++i)
		{
			newArray[i] = std::move(array[i]);
		}

		delete[] array;

		array = newArray;
		capacity = newCapacity;
	}
		
private:
	T* array;
	int capacity;
	int size;

};
