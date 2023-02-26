#ifndef _CTREE_CPP_
#define _CTREE_CPP_
#include "CTree.h"

template <typename T>
CNode<T>* CTree<T>::CreateRoot(const T& data)
{
    CNode<T>* p = new CNode<T>(data);
    return p;
}

template<typename T>
void CTree<T>::AddNode(CNode<T>** root, const T& data)
{
    if (!*root) *root = CreateRoot(data);
    else
    {
        if (data < (*root)->data) {
            if (!(*root)->left) (*root)->left = CreateRoot(data);
            else AddNode(&(*root)->left, data);
        }

        if (data > (*root)->data) {
            if (!(*root)->right) (*root)->right = CreateRoot(data);
            else AddNode(&(*root)->right, data);
        }
    }
}

template<typename T>
void CTree<T>::DeleteNode(CNode<T>** root, const T& data)
{
    if (*root == nullptr) return;

    if (data < (*root)->data) {
        DeleteNode(&(*root)->left, data);
    }
    else if (data > (*root)->data) {
        DeleteNode(&(*root)->right, data);
    }
    else if (data == (*root)->data) {
        if ((*root)->left == nullptr) {
            CNode<CData>* temp = *root;
            *root = (*root)->right;
            delete temp;
        }
        else if ((*root)->right == nullptr) {
            CNode<CData>* temp = *root;
            *root = (*root)->left;
            delete temp;
        }
        else // Есть оба потомка
        {
            CNode<CData>* temp = FindMin((*root)->right); // Находим минимальный элемент в правом поддереве
            (*root)->data = temp->data; // Копируем значение в удаляемый узел
            DeleteNode(&(*root)->right, temp->data); // Удаляем найденный узел
        }
    }
}

template<typename T>
void CTree<T>::PrintGoDown(CNode<T>* root)
{
    if (root)
    {
        PrintGoDown(root->right);
        cout << root->data << endl;      
        PrintGoDown(root->left);
    }
}

template<typename T>
void CTree<T>::Print(CNode<T>* root, const size_t& level)
{
    if (!root) return;

    Print(root->right, level + 1);

    for (size_t i = 0; i < level; i++)
        cout << "     ";

    cout << root->data << endl;

    Print(root->left, level + 1);
}

template<typename T>
void CTree<T>::FreeMemory(CNode<T>** root)
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
CNode<T>* CTree<T>::FindMin(CNode<T>* data)
{
    while (data->left != nullptr) {
        data = data->left;
    }
    return data;
}

template<typename T>
CTree<T>::~CTree()
{
    this->FreeMemory(&_root);
}

template<typename T>
void CTree<T>::AddNode(const T& data)
{
    this->AddNode(&_root, data);
}

template<typename T>
void CTree<T>::DeleteNode(const T& data)
{
    this->DeleteNode(&_root, data);
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