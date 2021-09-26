//
//  arvore_bin.cpp
//  arvore_bin
//
//  Created by Gabriel Batista Cristiano on 25/09/21.
//

#include <string>
#include <stdio.h>
#include <sstream>
#include "arvore_bin.hpp"

using namespace std;

Node::Node()
   : nData("")
   , leftNode (nullptr)
   , rightNode (nullptr)
   , parentNode (nullptr)
{
}

Node::~Node()
{
    leftNode = nullptr;
    rightNode = nullptr;
    parentNode = nullptr;
}

string Node::GetData() const
{
    return nData;
}

void Node::SetData(const string& data)
{
    nData = data;
}

Node* Node::GetLeftNode() const
{
    return leftNode;
}

void Node::SetLeftNode(Node* left)
{
    leftNode = left;
}

Node* Node::GetRightNode() const
{
    return rightNode;
}

void Node::SetRightNode(Node* right)
{
    rightNode = right;
}

Node* Node::GetParentNode() const
{
    return parentNode;
}

void Node::SetParentNode(Node* parent)
{
    parentNode = parent;
}

bool Node::IsRoot(Node* node) const
{
    bool root =  node->GetParentNode() == nullptr ? true : false;
    return root;
}

bool Node::IsLeaf(const Node* node)
{
    bool leaf = node->GetLeftNode() == nullptr && node->GetRightNode() == nullptr ? true : false;
    return leaf;
}

int Node::GetDegree(const Node* node)
{
    if (IsLeaf(node))
    {
        return 0;
    } else if (node->GetLeftNode() == nullptr || node->GetRightNode() == nullptr)
    {
        return 1;
    } else
    {
        return 2;
    }

}

int Node::GetDepth(Node* node) const
{
    int i = 0;
    while(!IsRoot(node))
    {
        node = node->GetParentNode();
        ++i;
    }
    return i;
}

int Node::GetHeight(const Node* node)
{
    if(node == nullptr) return -1;

    else
    {
        int left = GetHeight(node->GetLeftNode());
        int right = GetHeight(node->GetRightNode());

        if (left > right) return (left + 1);
        else return (right + 1);

    }
}

//Implementação da Classe Árvore

Tree::Tree()
{
    root = nullptr;
}

Tree::Tree(Node* root)
{
    SetRoot(root);
}

Tree::~Tree()
{
    root = nullptr;
}

Node* Tree::GetRoot() const
{
    return root;
}

void Tree::SetRoot(Node* root)
{
    this->root = root;
}
string Tree::TraverseInOrder() const
{
    return TraverseInOrderInt(root);
}
string Tree::TraverseInOrderInt(const Node* node) const
{
    if (node != nullptr)
    {
        ostringstream oss;
        oss << TraverseInOrderInt(node->GetLeftNode());
        oss << node->GetData() << ' ';
        oss << TraverseInOrderInt(node->GetRightNode());
        return oss.str();
    }
    return "";
}
string Tree::TraversePreOrder() const
{
    return TraversePreOrderInt(root);
}
string Tree::TraversePreOrderInt(const Node* node) const
{
    if (node != nullptr)
    {
        ostringstream oss;
        oss << node->GetData() << ' ';
        oss << TraversePreOrderInt(node->GetLeftNode());
        oss << TraversePreOrderInt(node->GetRightNode());
        return oss.str();
    }
    return "";
}
string Tree::TraversePostOrder() const
{
    return TraversePostOrderInt(root);
}
string Tree::TraversePostOrderInt(const Node* node) const
{
    if (node != nullptr)
    {
        ostringstream oss;
        cout << TraversePostOrderInt(node->GetLeftNode());
        cout << TraversePostOrderInt(node->GetRightNode());
        cout << node->GetData() << ' ';
        return oss.str();
    }
    return "";
}
