#pragma once
#include "c:/Users/psiph/source/repos/Vector/Vector/Vector/Vector.h"
#include "PQ_ComplHeap_macro.h"
#include <map>

template <typename T>
class PQ_ComplHeap : public Vector<T>
{
public:
	PQ_ComplHeap() = default;
	~PQ_ComplHeap() = default;
	PQ_ComplHeap(T *a, int s);
	void insert(T const& e);
	T delMax();
	T getMax() const { return Vector<T>::elem_[0]; }
	void heapSort();
private:
	int percolateUp(int loc);
	int percolateDown(int n, int loc);
	void heapify(int n);
};

template <typename T>
PQ_ComplHeap<T>::PQ_ComplHeap(T* a, int s)
{
	Vector<T>::copyFrom(a, 0, s);
	heapify(s);
}

template <typename T>
void PQ_ComplHeap<T>::insert(T const& e)
{
	Vector<T>::append(e);
	percolateUp(Vector<T>::size_ - 1);
}

template <typename T>
T PQ_ComplHeap<T>::delMax()
{
	T temp = Vector<T>::elem_[0];
	Vector<T>::elem_[0] = Vector<T>::elem_[--Vector<T>::size_];
	percolateDown(Vector<T>::size_, 0);
	return temp;
}

template <typename T>
void PQ_ComplHeap<T>::heapSort()
{
	while (!this->empty())
	{
		std::swap(this->elem_[0], this->elem_[--this->size_]);
		percolateDown(Vector<T>::size_, 0);
	}
}

template <typename T>
int PQ_ComplHeap<T>::percolateUp(int loc)
{
	while (ParentValid(loc))
	{
		int i = Parent(loc);
		if (Vector<T>::elem_[loc] < Vector<T>::elem_[i])
			break;
		std::swap(Vector<T>::elem_[loc], Vector<T>::elem_[i]);
		loc = i;
	}
	return loc;
}

template <typename T>
int PQ_ComplHeap<T>::percolateDown(int n, int loc)
{
	int j = 0;
	while (loc != (j = ProperParent(Vector<T>::elem_,n,loc)))
	{
		std::swap(Vector<T>::elem_[loc], Vector<T>::elem_[j]);
		loc = j;
	}
	return loc;
}

template <typename T>
void PQ_ComplHeap<T>::heapify(int n)
{
	int i = LastInternal(n);
	while (InHeap(n,i))
	{
		percolateDown(n, i);
		--i;
	}
}
