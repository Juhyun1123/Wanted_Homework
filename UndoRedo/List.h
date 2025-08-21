#pragma once
#include <iostream>

/*
*  동적 배열 
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
	/// 동적 배열 현재 사이즈 반환
	/// </summary>
	/// <returns>동적 배열 사이즈</returns>
	int Size()
	{
		return size;
	}

	/// <summary>
	/// 동적 배열 비었는지 확인
	/// </summary>
	/// <returns>비었는지 여부</returns>
	bool IsEmpty()
	{
		return (size == 0);
	}

	/// <summary>
	/// 동적 배열 마지막에 새 데이터 입력
	/// </summary>
	/// <param name="data">추가 데이터</param>
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
	/// 동적 배열 마지막에 새 데이터 입력
	/// </summary>
	/// <param name="data">추가 데이터</param>
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
	/// 삭제 데이터와 일치하는 데이터 하나 삭제 (중복시 가장 앞 데이터 삭제)
	/// </summary>
	/// <param name="data">삭제 데이터</param>
	/// <returns>삭제 여부</returns>
	bool Delete(const T& data)
	{
		return DeleteAt(SearchIndex(data));
	}

	/// <summary>
	/// 인덱스 기반 데이터 삭제
	/// </summary>
	/// <param name="data">삭제 인덱스</param>
	/// <returns>삭제 여부</returns>
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
	/// 동적 배열 비우기
	/// </summary>
	void Clear()
	{
		for (int i = 0; i < size; ++i) { array[i].~T(); }
		size = 0;
	}

	/// <summary>
	/// 데이터의 인덱스 반환 (중복시 가장 앞 데이터 인덱스 반환)
	/// </summary>
	/// <param name="data">검색 데이터</param>
	/// <returns>반환 데이터 / 실패시 -1</returns>
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

	// 연산자 오버 로딩
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
	/// 사이즈 확장
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
