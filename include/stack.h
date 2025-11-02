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
inline TStack<T>::TStack(const TStack& obj){
    data = nullptr;
    len = 0;
    top = 0;
    isNew = true;
    if (obj.len < 0){
        throw -1;
    }
    if (obj.len > 0){
        len = obj.len;
        data = new T*[len];
        for (int i = 0; i < len; i++){
            if (i < obj.top && obj.data[i] != 0){
                data[i] = new T(*(obj.data[i]));
            }
            else {
                data[i] = nullptr;
            }    
        }
        top = obj.top;
        isNew = true;
    }
}

template<class T>
inline TStack<T>::TStack(TStack&& obj){
    len = obj.len;
    data = obj.data;
    isNew = obj.isNew;
    top = obj.top;

    obj.len = 0;
    obj.data = nullptr;
    obj.isNew = false;
    obj.top = 0;

}

template<class T>
inline TStack<T>::TStack(T** data_, int len_){
    if (len < 0){
        throw -1;
    }
    data = data_;
    len = len_;
    isNew = false;
    top = 0;
    for (int i = 0; i < len; i++){
        if (data[i] == 0){
            top = i;
            break;
        }
        top = i + 1;
    }
}

template<class T>
inline TStack<T>::~TStack(){
    if (isNew && data != nullptr){
        for (int i = 0; i < len; i++){
            if (data[i] != nullptr){
                delete data[i];
                data[i] = 0;
            }
        }
        delete [] data;
        data = nullptr;
    }
} 

template<class T>
inline int TStack<T>::GetLen() const{
    return len;
}

template <class T>
inline int TStack<T>::GetTop() const{ 
    return top; 
}

template <class T>
inline void TStack<T>::Resize(int len_) {
    if (!isNew){ 
        throw -1; 
    }
    if (len_ < 0){ 
        throw -1; 
    }
    if (len_ == len){
        return;
    }
    T** newdata = nullptr;
    if (len_ > 0){
        newdata = new T*[len_];
        for (int i = 0; i < len_; i++){ 
            newdata[i] = 0; 
        }
        int limit = len_ < len ? len_ : len;
        for (int i = 0; i < limit; i++){ 
            newdata[i] = data[i]; 
        }
    }
    if (data != 0){ 
        delete [] data; 
    }
    data = newdata;
    len = len_;
    if (top > len){ 
        top = len; 
    }
}

template <class T>
inline void TStack<T>::SetData(T** data_, int len_) {
    if (isNew && data != nullptr) {
        for (int i = 0; i < len; ++i) {
            if (data[i] != nullptr) { 
                delete data[i]; 
                data[i] = nullptr; 
            }
        }
        delete [] data;
    }
    data = data_; 
    len = len_; 
    isNew = false; 
    top = 0;
    for (int i = 0; i < len; ++i) {
        if (data[i] == 0) { top = i; break; }
        top = i + 1;
    }
}

template <class T>
inline void TStack<T>::Push(T* value){
    if (top >= len) { 
        throw -1; 
    }
    data[top++] = value;
}