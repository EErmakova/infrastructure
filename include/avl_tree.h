#ifndef INCLUDE_AVL_TREE_H_
#define INCLUDE_AVL_TREE_H_
#include <stack>
#include <vector>
#include <stdexcept>
using std::stack;
using std::vector;
using std::logic_error;

template <class Type>
class avlnode {
 public:
    Type val;
    avlnode* parent;
    avlnode* left;
    avlnode* right;
    int balance;

    avlnode() {
        val = 0;
        parent = left = right = nullptr;
        balance = 0;
    }
    avlnode(const Type& v, avlnode* par) {
        val = v;
        parent = par;
        left = right = nullptr;
        balance = 0;
    }
};

template <class Type>
class AVLTree {
    void LeftRotation(avlnode<Type>** knot);
    void RightRotation(avlnode<Type>** knot);
    void DoubleLeftRotation(avlnode<Type>** knot);
    void DoubleRightRotation(avlnode<Type>** knot);
 public:
    avlnode<Type>* root;
    AVLTree();
    ~AVLTree();
    vector<avlnode<Type>*> GetAllKnots();
    int GetSize();
    int Height(avlnode<Type>* knot);
    void Balancing(avlnode<Type>** knot);
    avlnode<Type>* Findmin(avlnode<Type>* knot);
    avlnode<Type>* Findnext(avlnode<Type>* knot);
    void Add(const Type& v);
    void Insert(avlnode<Type> **knot, avlnode<Type> **new_node);
    void Erase(avlnode<Type>** knot, const Type& value);
    void Erase(const Type& value);
    void TotalErase(avlnode<Type>** knot);
};

template<class Type>
AVLTree<Type>::AVLTree() {
    root = NULL;
}

template<class Type>
AVLTree<Type>::~AVLTree() {
    TotalErase(&root);
}

template<class Type>
vector<avlnode<Type>*> AVLTree<Type>::GetAllKnots() {
    if (root == nullptr)
        vector<avlnode<Type>*> r(0);
    stack<avlnode<Type>*> s, res;
    s.push(root);
    while (!s.empty()) {
        auto tmp = s.top();
        s.pop();
        if (tmp != nullptr) {
            res.push(tmp);
            if (tmp->left != nullptr)
                s.push(tmp->left);
            if (tmp->right != nullptr)
                s.push(tmp->right);
        }
    }
    vector<avlnode<Type>*> v(res.size());
    while (!res.empty()) {
        v[res.size() - 1] = res.top();
        res.pop();
    }
    return v;
}

template<class Type>
int AVLTree<Type>::GetSize() {
    return GetAllKnots().size();
}

template<class Type>
void AVLTree<Type>::LeftRotation(avlnode<Type>** knot) {
     avlnode<Type>* tmp1 = (*knot);
     avlnode<Type>* tmp2 = tmp1->right;
     avlnode<Type>* tmp3 = tmp2->left;
     tmp1->right = tmp3;
     if (tmp3 != nullptr)
         tmp3->parent = tmp1;
     tmp2->left = tmp1;
     tmp2->parent = tmp1->parent;
     tmp1->parent = tmp2;
     Height(tmp1);
     Height(tmp2);
     (*knot) = tmp2;
}

template<class Type>
void AVLTree<Type>::RightRotation(avlnode<Type>** knot) {
    avlnode<Type>* tmp1 = (*knot);
    avlnode<Type>* tmp2 = tmp1->left;
    avlnode<Type>* tmp3 = tmp2->right;
    tmp1->left = tmp3;
    if (tmp3 != nullptr)
        tmp3->parent = tmp1;
    tmp2->right = tmp1;
    tmp2->parent = tmp1->parent;
    tmp1->parent = tmp2;
    Height(tmp1);
    Height(tmp2);
    (*knot) = tmp2;
}

template<class Type>
void AVLTree<Type>::DoubleLeftRotation(avlnode<Type>** knot) {
    avlnode<Type>* tmp1 = (*knot);
    avlnode<Type>* tmp2 = tmp1->right;
    avlnode<Type>* tmp3 = tmp2->left;
    avlnode<Type>* tmp4 = tmp3->right;
    avlnode<Type>* tmp5 = tmp3->left;
    tmp3->left = tmp1;
    tmp3->parent = tmp1->parent;
    tmp1->parent = tmp3;
    tmp3->right = tmp2;
    tmp2->parent = tmp3;
    tmp2->left = tmp4;
    if (tmp4 != nullptr)
        tmp4->parent = tmp2;
    tmp1->right = tmp5;
    if (tmp5 != nullptr)
        tmp5->parent = tmp1;
    Height(tmp1);
    Height(tmp2);
    Height(tmp3);
    (*knot) = tmp3;
}

template<class Type>
void AVLTree<Type>::DoubleRightRotation(avlnode<Type>** knot) {
    avlnode<Type>* tmp1 = (*knot);
    avlnode<Type>* tmp2 = tmp1->left;
    avlnode<Type>* tmp3 = tmp2->right;
    avlnode<Type>* tmp4 = tmp3->left;
    avlnode<Type>* tmp5 = tmp3->right;
    tmp3->right = tmp1;
    tmp3->parent = tmp1->parent;
    tmp1->parent = tmp3;
    tmp3->left = tmp2;
    tmp2->parent = tmp3;
    tmp2->right = tmp4;
    if (tmp4 != nullptr)
        tmp4->parent = tmp2;
    tmp1->left = tmp5;
    if (tmp5 != nullptr)
        tmp5->parent = tmp1;
    Height(tmp1);
    Height(tmp2);
    Height(tmp3);
    (*knot) = tmp3;
}


template<class Type>
int AVLTree<Type>::Height(avlnode<Type>* knot) {
    if (knot == nullptr)
        return -1;
    int left = Height(knot->left);
    int right = Height(knot->right);
    knot->balance = left - right;
    if (left > right)
        return (left + 1);
    else
        return (right + 1);
}

template<class Type>
void AVLTree<Type>::Balancing(avlnode<Type>** knot) {
    if ((*knot) == nullptr)
        return;
    Height((*knot));
    if ((*knot)->balance == 2) {
        if (((*knot)->left)->balance > 0)
            RightRotation(knot);
        else
            DoubleRightRotation(knot);
    }
    if ((*knot)->balance == -2) {
        if ((*knot)->right->balance <= 0)
            LeftRotation(knot);
        else
            DoubleLeftRotation(knot);
    }
}

template<class Type>
avlnode<Type>* AVLTree<Type>::Findmin(avlnode<Type>* knot) {
    avlnode<Type>* tmp;
    if (knot == nullptr)
        return 0;
    else
        tmp = knot;
    while (tmp->left != nullptr)
        tmp = tmp->left;
    return tmp;
}

template<class Type>
avlnode<Type>* AVLTree<Type>::Findnext(avlnode<Type>* knot) {
    if (knot == nullptr)
        throw logic_error("Entered empty knot");
    if (knot->right != nullptr)
        return Findmin(knot->right);
    while ((knot->parent != nullptr) && knot->parent->right == knot)
        knot = knot->parent;
    if (knot->parent == nullptr)
        throw logic_error("Next knot isn`t found");
    return knot->parent;
}

template<class Type>
void AVLTree<Type>::Add(const Type& value) {
    avlnode<Type>* tmp = new avlnode<Type>(value, nullptr);
    if (tmp == 0)
        throw logic_error("You don`t have a memory");
    if (root == nullptr) {
        root = tmp;
        root->parent = nullptr;
        return;
    }
    Insert(&root, &tmp);
}

template<class Type>
void AVLTree<Type>::Insert(avlnode<Type>** knot, avlnode<Type>** new_node) {
    if ((*new_node)->val < (*knot)->val) {
        if ((*knot)->left == nullptr) {
            (*knot)->left = (*new_node);
            (*new_node)->parent = (*knot);
        } else {
            Insert(&((*knot)->left), new_node);
        }
    } else {
        if ((*knot)->right == nullptr) {
            (*knot)->right = (*new_node);
            (*new_node)->parent = (*knot);
        } else {
            Insert(&((*knot)->right), new_node);
        }
    }
    Balancing(knot);
}

template<class Type>
void AVLTree<Type>::Erase(avlnode<Type>** knot, const Type& value) {
    if ((*knot) == nullptr)
        return;
    if (value < (*knot)->val) {
        Erase(&((*knot)->left), value);
    } else if (value > (*knot)->val) {
       Erase(&((*knot)->right), value);
    } else {
        if ((*knot)->left == nullptr && (*knot)->right == nullptr) {
            avlnode<Type>* tmp1 = (*knot);
            if ((*knot)->parent != nullptr) {
                if ((*knot)->parent->left == (*knot))
                    (*knot)->parent->left = nullptr;
                else
                    (*knot)->parent->right = nullptr;
            } else {
                root = nullptr;
            }
            delete tmp1;
            return;
        }
        if ((*knot)->right == nullptr) {
            avlnode<Type>* tmp1 = (*knot);
            avlnode<Type>* tmp2 = (*knot)->left;
            tmp2->parent = tmp1->parent;
            if (tmp1->parent != nullptr) {
                if (tmp1->parent->left == tmp1)
                    tmp1->parent->left = tmp2;
                else
                    tmp1->parent->right = tmp2;
            } else {
                root = tmp2;
            }
            delete tmp1;
            return;
        }
        if ((*knot)->left == nullptr) {
            avlnode<Type>* tmp1 = (*knot);
            avlnode<Type>* tmp2 = (*knot)->right;
            tmp2->parent = tmp1->parent;
            if (tmp1->parent != nullptr) {
                if (tmp1->parent->left == tmp1)
                    tmp1->parent->left = tmp2;
                else
                    tmp1->parent->right = tmp2;
            } else {
                root = tmp2;
            }
            delete tmp1;
            return;
        } else {
            avlnode<Type>* tmp1 = Findnext((*knot));
            avlnode<Type>* tmp2 = tmp1->parent;
            if (tmp1->parent->left == tmp1)
                tmp2->left = tmp1->right;
            else
                tmp2->right = tmp1->right;
            tmp1->parent = (*knot)->parent;
            tmp1->left = (*knot)->left;
            tmp1->right = (*knot)->right;
            if (tmp1->left != nullptr)
                tmp1->left->parent = tmp1;
            if (tmp1->right != nullptr)
                tmp1->right->parent = tmp1;
            while (tmp2 != nullptr && tmp2 != tmp1) {
                Balancing(&tmp2);
                tmp2 = tmp2->parent;
            }
            avlnode<Type>* temp = (*knot);
            (*knot) = tmp1;
            delete temp;
        }
    }
    Balancing(knot);
}

template<class Type>
void AVLTree<Type>::Erase(const Type& value) {
    if (root == nullptr)
        throw logic_error("Tree is empty");
    Erase(&root, value);
}

template<class Type>
void AVLTree<Type>::TotalErase(avlnode<Type>** knot) {
    if ((*knot) == nullptr)
        return;
    if ((*knot)->left != nullptr)
        TotalErase(&((*knot)->left));
    if ((*knot)->right != nullptr)
        TotalErase(&((*knot)->right));
    delete (*knot);
    (*knot) = nullptr;
}



#endif  // INCLUDE_AVL_TREE_H_
