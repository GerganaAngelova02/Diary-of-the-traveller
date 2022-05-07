#pragma once
#include <iostream>

template <typename T>
class Vector
{
	T* data;
	size_t size;
	size_t capasity;

	void copyFrom(const Vector<T>& other);
	void free();

public:
	Vector()
	{
		size = 0;
		capasity = 0;
		data = new T[capasity];
	}
	Vector(size_t cap)
	{
		capsity = cap;
		size = 0;
		data = new T[cap];
	}
	Vector(const Vector<T>& other) 
	{
		copyFrom(other);
	}
	Vector<T>& operator=(const Vector<T>& other)
	{
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}
	~Vector ()
	{
		free();
	}

	size_t capasity() const
	{
		return capasity;
	}
	size_t size()const
	{
		return size;
	}

	void resize();
	
	bool empthy();
	void push_back(const T& element);
	void pop_back();
	void removeAt(int index);
	T getAt(int index)
	{
		return arr[index];
	}

	T& operator [] (int ind)
	{
		return arr[ind];
	}
	const T operator [](int ind) const 
	{
		return arr[ind];
	}

	friend std::ostream& operator << (std::ostream& out, const Vector& v)
	{
		for (int i = 0; i < size(); i++)
			out << v[i];
		return out;
	}
	friend std::istream& operator >> (std::istream& in, Vector& v)
	{
		for (int i = 0; i < size(); i++)
			in >> v[i];
		return in;
	}
};

template<typename T>
inline void Vector<T>::copyFrom(const Vector<T>& other)
{
	size = other.size;
	capaity = other.capasity;
	data = new T[capsity];
	for (int i = 0; i < size(); i++)
		data[i] = other.data[i];
}


template<typename T>
inline void Vector<T>::free()
{
	delete[]data;
}

template<typename T>
inline void Vector<T>::resize()
{
	capassity *= 2;
	T* resizedVector = new T[capasity];
	for (int i = 0; i < size(); i++)
		resizedVector[i] = data[i];

	delete[] data;
	data = resizedVector;
}

template<typename T>
inline bool Vector<T>::empthy()
{
	return size==0;
}

template<typename T>
inline void Vector<T>::push_back(const T& element)
{
	if (size = capasity)
		resize();
	data[size] = element;
	size++;
}

template<typename T>
inline void Vector<T>::pop_back()
{
	delete data[size];
	size--;
}

template<typename T>
inline void Vector<T>::removeAt(int index)
{
	for (int i = 0; i < size(); i++)
	{
		if (i = index)
		{
			std::swap(data[i], data[size]);
			pop_back();
		}
	}
}
