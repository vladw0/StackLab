#pragma once

#include <iostream>

template <class T>
class TStack{
protected:
	T** data;
	int len;
    int top;
	bool isNew;
public:
	TStack();
	TStack(int len_);
	TStack(const TStack& obj);
    TStack(TStack&& obj);
    TStack(T** data_, int len_);
	~TStack();

	int GetLen() const;
    int GetTop() const;

	void Resize(int len_);
	void SetData(T** data_, int len);

	void Push(T* value);
    void Push(const T& value);

    T Pop(); //поп от класса Т

    bool IsEmpty() const;
    bool IsFull() const;


    TStack& operator=(const Tstack& obj);
    TStack& operator=(TStack&& obj);
    bool operator ==(const TStack& obj) const;
    bool operator!=(const TStack& obj) const;


    template <class o>
    friend std::ostream& operator<<(std::ostream& o, const TStack<0>& v);
    template <class I>
    friend std::istream& operator>>(std::istream& i, TStack<I>& v);

  
};

template<class T>
inline TStack <T>::TStack(){
    data = nullptr;
    len = 0;
    top = 0;
    isNew = true;
}

template<class T> 
inline TStack<T>::TStack(int len_){
    if (len_ < 0){
        throw - 1;
    }
    if (len_ == 0){
        data = nullptr;
        len = 0;
        top = 0;
        isNew = true;
    }
    else {
        len = len_;
        data = new T * [len];
        for (int i = 0; i < len, i++){
            data[i] = nullptr;
        }
        top = 0;
        IsNew = true;
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
        for (int i = 0; i < len; i++){
            if (data[i] == nullptr){
                top = i;
                break;
            }
        }
    }
}

template<class T>
inline TStack<T>::~TStack(){
    if (isNew){
        if (data != nullptr){
            for (int i = 0; i < len; i++){
                delete data[i];
            }
        }
    }
} 

template<class T>
inline int TStack<T>::GetLen(){
    return 0;
}
