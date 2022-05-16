#pragma once
#include <iostream>


template<typename T>
class DynamicArray
{
	T* data=nullptr;
	size_t size=0;
	size_t capacity=0;

	void copyFrom(const DynamicArray<T>& other)
	{
		capacity = other.capacity;
		size = other.size;
		data = new T[capacity];
		for (int i=0 ; i<size;i++)
			data[i] = other.data[i];

	}
	void free()
	{
		delete[]data;
		size = 0;
	}
	void reallocate(size_t newCapasity);
public:
	DynamicArray()
	{
		reallocate(2);
	}
	DynamicArray(size_t cap):capacity(cap)
	{
		size = 0;
		data = new T[capacity];
	}
	DynamicArray(const DynamicArray<T>& other)
	{
		copyFrom(other);
	}

	size_t getSize() const
	{
		return size;
	}

	DynamicArray<T>& operator =(const DynamicArray<T>& other)
	{
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}
	~DynamicArray()
	{
		free();
	}

	T& operator[] (int index);
	const T& operator[] (int index) const;

	void add(const T& element);

	friend std::istream& operator >> (std::istream& in, DynamicArray<T>& arr)
	{
		delete[]arr.data;
		T buffer[1000];
		in >> buffer;
		arr.data = new char[arr.size];
		for (int i = 0; i < arr.getSize(); i++)
			buffer[i] =arr[i];
		return in;
	}
	friend std::ostream& operator << (std::ostream& out, const DynamicArray<T>& arr)
	{
		for (int i = 0; i <arr.getSize(); i++)
			out << arr[i]<<',';
		return out;
	}
};

template<typename T>
inline void DynamicArray<T>::reallocate(size_t newCapasity)
{
	T* newData = new T[newCapasity];

	if (newCapasity < size)
		size = newCapasity;

	for (int i = 0; i < size ;i++)
		newData[i] = data[i];

	delete[]data;
	data = newData;
	capacity = newCapasity;
}

template<typename T>
inline T& DynamicArray<T>::operator[](int index)
{
	if (index > getSize()-1)
		std::cout << "Invalid index!";
	return data[index];
}

template<typename T>
inline const T& DynamicArray<T>::operator[](int index) const
{
	if (index > getSize()-1)
		std::cout << "Invalid index!";
	return data[index];
}

template<typename T>
inline void DynamicArray<T>::add(const T& element)
{
	if (size >= capacity)
		reallocate(capacity * 2);
	data[size] = element;
	size++;
}


