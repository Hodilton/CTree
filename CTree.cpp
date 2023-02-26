#ifndef _CTREE_CPP_
#define _CTREE_CPP_
#include "CTree.h"

template <typename T>
Node<T>* CTree<T>::CreateRoot(const T& value) 
{
    Node<T>* p = new Node<T>(value);
    return p;
}

template<typename T>
void CTree<T>::AddNode(Node<T>** root, const T& value) 
{
    if (!*root) *root = CreateRoot(value);
    else
    {
        if (value < (*root)->data) {
            if (!(*root)->left) (*root)->left = CreateRoot(value);
            else AddNode(&(*root)->left, value);
        }

        if (value > (*root)->data) {
            if (!(*root)->right) (*root)->right = CreateRoot(value);
            else AddNode(&(*root)->right, value);
        }
    }
}

template<typename T>
void CTree<T>::PrintGoDown(Node<T>* root)
{
    if (root)
    {
        PrintGoDown(root->right);
        cout << root->data << endl;      
        PrintGoDown(root->left);
    }
}

template<typename T>
void CTree<T>::Print(Node<T>* root, const size_t& level)
{
    if (!root) return;

    Print(root->right, level + 1);

    for (size_t i = 0; i < level; i++)
        cout << "     ";

    cout << root->data << endl;

    Print(root->left, level + 1);
}

template<typename T>
void CTree<T>::FreeMemory(Node<T>** root)
{
    if (*root)
    {
        FreeMemory(&(*root)->left);
        FreeMemory(&(*root)->right);

        delete (*root);
        (*root) = nullptr;
    }
}

template<typename T>
CTree<T>::~CTree()
{
    this->FreeMemory(&_root);
}

template<typename T>
void CTree<T>::AddNode(const T& value)
{
    this->AddNode(&_root, value);
}

template<typename T>
void CTree<T>::PrintGoDown()
{
    this->PrintGoDown(_root);
}

template<typename T>
void CTree<T>::Print()
{
    Print(_root, 0);
}

#endif // !_CTREE_CPP_