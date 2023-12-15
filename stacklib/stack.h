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
        this->sise = q.sise;
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
	T Get() { if (count == 0) throw "is empty"; return this->mas[start]; }//��� ��������
	T Pop();//� ��������� �� ������

    int GetStart() { return start; }
    int GetCount() { return count; }
    int GetEnd() { return end; }
	bool IsFull() { return ((count>0)&&(end == start)); }
	bool IsEmpty() {return (count == 0); }

    //��������� ����� � ������

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


