#pragma once
#ifndef _CTREE_H_
#define _CTREE_H_
#include "stdafx.h"

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node() : left(nullptr), right(nullptr) {}
    Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class CTree {
private:
    Node<T>* _root;

    CTree(const CTree&) = delete;
    CTree& operator=(const CTree&) = delete;

    Node<T>* CreateRoot(const T& value);
    void AddNode(Node<T>** root, const T& value);
    void PrintGoDown(Node<T>* root);
    void Print(Node<T>* root, const size_t& level);
    void FreeMemory(Node<T>** root);

public:
    CTree() : _root(nullptr) {}
    ~CTree();

    void AddNode(const T& value);
    void PrintGoDown();
    void Print();
};

#include "CTree.cpp"
#endif // !_CTREE_H_