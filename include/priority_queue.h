#ifndef INCLUDE_PRIORITY_QUEUE_H_
#define INCLUDE_PRIORITY_QUEUE_H_
#include "four_heap.h"
template <class Type>
class Queue_on_heap {
    FOURheap<Type>* heap;
 public:
    Queue_on_heap();
    ~Queue_on_heap();
    int GetSize() { return heap->GetSize(); }
    bool IsFull() { return heap->IsFull(); }
    bool IsEmpty() { return heap->IsEmpty(); }
    void Push(const Type& val);
    void Pop();
    void Erase(const Type& val);
    Type Top();
};

template<class Type>
Queue_on_heap<Type>::Queue_on_heap() {
    heap = new FOURheap<Type>();
}

template<class Type>
Queue_on_heap<Type>::~Queue_on_heap() {
    delete heap;
}

template<class Type>
void Queue_on_heap<Type>::Push(const Type & val) {
    if (IsFull())
        throw logic_error("Heap is full");
    heap->Insert(val);
}

template<class Type>
void Queue_on_heap<Type>::Pop() {
    if (IsEmpty())
        throw logic_error("Heap is empty");
    heap->EraseMin();
}

template<class Type>
void Queue_on_heap<Type>::Erase(const Type& val) {
    for (int i = 0; i < heap->GetSize(); ++i)
        if (heap->val[i] == val)
            heap->Erase(i);
}

template<class Type>
Type Queue_on_heap<Type>::Top() {
    if (IsEmpty())
        throw logic_error("Heap is empty");
    return (*heap)[0];
}

#endif  // INCLUDE_PRIORITY_QUEUE_H_

