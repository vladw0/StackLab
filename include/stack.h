#pragma once

#include <iostream>

template <class T>
class Tstack
{
protected:
	T** data;
	int len;
	bool isNew;
public:
	TStack();
	TStack(int len_);
	TStack(const TStack& obj);
	~TStack();

	int GetLen();
	void GetVector(T** vector_);

	void Resize(int len_);
	void SetVector(T* vector_);

	void Push(T* value);
    void Push(T value);

    TPop();

	TStack& operator=(const Tstack<T>& obj);
	TStack& operator=(TStack<T>&& obj);
	bool operator ==(const TStack<T>& obj);
	bool operator!=(const TStack<T>& obj);

	template <class o>
	friend std::ostream& operator<<(std::ostream& o, TStack<0>& v);
	template <class I>
	friend std::istream& operator>>(std::istream& i, TStack<I>& v);
};