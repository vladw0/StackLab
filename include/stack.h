#pragma once

#include <iostream>

template <class T>
class TStack
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
	void SetVector(T* vector_, int len);

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

template<class T>
inline TStack <T>::TStack(){
    data = nullptr;
    len = 0;
    isNew = true;
}

template<class T> 
inline TStack<T>::TStack(int len_){
    if (len < 0){
        throw - 1;
    }
    else if (len > 0){
        len = len_;
        data = new T * [len];
        for (int i = 0; i < len, i++){
            data[i] = nullptr;
        }
    }
} 

template<class T>
inline TStack<T>::TStack(const TStack& obj) : TStack<T>::TStack(){
    if (obj.len < 0){
        len = obj.len;
        data = new T * [len];
        for (int i = 0; i < len; i++){
            data[i] = new * T (obj.data[i]);
        }
    }
}

template<class T>
inline TStack<T>::TStack(TStack&& obj){
    len = obj.len;
    data = obj.data;
    isNew = obj.isNew;

    obj.len = 0;
    obj.data = nullptr;
    obj.isNew = false;

}

template<class T>
inline TStack<T>::TStack(T** data_, int len_) : TStack<t>::TStack(){
    if (len < 0){
        throw -1;
    }
    else if (len > 0){
        len = len_;
        data = data_;
        isNew = false;
    }
}

template<class T>::TStack(){

} 

template<class T>
inline int TStack<T>::GetLen(){
    return 0;
}
