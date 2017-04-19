#ifndef INCLUDE_PRIORITY_QUEUE_H_
#define INCLUDE_PRIORITY_QUEUE_H_
#include "avl_tree.h"
#include "five_heap.h"
template <class Type>
class Queue_on_heap {
    FIVEheap<Type>* heap;
 public:
     Queue_on_heap();
     ~Queue_on_heap();
     int GetSize() { return heap->GetSize(); }
     bool IsFull() { return heap->IsFull(); }
     bool IsEmpty() { return heap->IsEmpty(); }
     void Push(const Type& val);
     void Pop();
     Type Top();
};

template<class Type>
Queue_on_heap<Type>::Queue_on_heap() {
    heap = new FIVEheap<Type>();
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
Type Queue_on_heap<Type>::Top() {
    if (IsEmpty())
        throw logic_error("Heap is empty");
    return (*heap)[0];
}

template <class Type>
class Queue_on_AVLTree {
    AVLTree<Type>* tree;
 public:
     Queue_on_AVLTree();
     ~Queue_on_AVLTree();
     int GetSize() { return tree->GetSize(); }
     bool IsFull();
     bool IsEmpty() { return (tree->GetSize() == 0); }
     void Push(const Type& val) { tree->Add(val); }
     void Pop();
     Type Top();
};

template<class Type>
Queue_on_AVLTree<Type>::Queue_on_AVLTree() {
    tree = new AVLTree<Type>();
}

template<class Type>
Queue_on_AVLTree<Type>::~Queue_on_AVLTree() {
    delete tree;
}

template<class Type>
bool Queue_on_AVLTree<Type>::IsFull() {
    avlnode<Type>* tmp = new avlnode<Type>();
    if (tmp == nullptr)
        return 1;
    delete tmp;
    return 0;
}

template<class Type>
void Queue_on_AVLTree<Type>::Pop() {
    avlnode<Type>* min = tree->Findmin(tree->root);
    tree->Erase(min->val);
}

template<class Type>
Type Queue_on_AVLTree<Type>::Top() {
    if (IsEmpty())
        throw logic_error("Heap is empty");
    return (tree->Findmin(tree->root))->val;
}

#endif  // INCLUDE_PRIORITY_QUEUE_H_
