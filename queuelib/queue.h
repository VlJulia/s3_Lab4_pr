#pragma once
#include <iostream>
using namespace std;

//define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
template <class T>
class TQueue {
protected:
    int size;
    int start;
    int end;
    int count;
    T* mas;

public:
    TQueue(int n = 0) {
        this->size = n;
        this->start = 0;
        this->end = 0;
        this->count = 0;
        this->mas = new T[n];
    };
    TQueue(TQueue <T>& q) {
        this->size = q.size;
        this->start = q.start;
        this->end = q.end;
        this->count = q.count;
        this->mas = new T[q.size];
        memcpy(this->mas, q.mas, size * sizeof(T));
    };
    ~TQueue() {
        delete[] this->mas;
        this->mas = nullptr;
    };

    void Push(T a);
	T Get() { if (count == 0) throw "is empty"; return this->mas[start]; }//без удаления
	T Pop();//с удалением из начала

    int GetStart() { return start; }
    int GetSize() { return size; }
    int GetCount() { return count; }
    int GetEnd() { return end; }
	bool IsFull() { return ((count>0)&&(end == start)); }
	bool IsEmpty() {return (count == 0); }
    bool operator==(const TQueue<T>& q) const;
    bool operator!=(const TQueue<T>& q) const;

    //операторы вводы и выводы

	friend std::ostream& operator<< (std::ostream& ostr, const TQueue& obj) {
		ostr << "size is " << obj.size << endl;
		ostr << "begin is " << obj.start << endl;
		ostr << "end is " << obj.end << endl;
		ostr << "count " << obj.count << endl;
		for (int i = 0; i < obj.size; i++) {
			ostr << obj.mas[i] << endl;
		}
		return ostr;
	};
    friend std::istream& operator >> (std::istream& istr, TQueue& obj) {
        int n;
        istr >> n;
        obj.count = n - 1;
        for (int i = 0; i < obj.count; i++) {
            istr >> obj.mas[i];
        }
        return istr;
    };
};

template<class T>
void TQueue<T>::Push(T a) {
    if (IsFull()) throw "if full";
    this->mas[end] = a;
	end=(end+1)%(size);
    count++;
};
template<class T>
T TQueue<T>::Pop() {
    if (count == 0) throw "is empty";
	T tmp =mas[start];
	mas[start] = 0;
	this->start = (start + 1) % size;
	count--;
    return tmp;
}
template<class T>
bool TQueue<T>::operator!=(const TQueue<T>& q) const {
    if (this->size != q.size) return true;
    for (int i = 0; i < this->size; i++) {
        if (this->mas[i] != q.mas[i]) return true;
    }
    return false;
};
template<class T>
bool TQueue<T>::operator==(const TQueue<T>& q) const {
    if (this->size != q.size) return false;
    for (int i = 0; i < this->size; i++) {
        if (this->mas[i] != q.mas[i]) return false;
    }
    return true;
};

