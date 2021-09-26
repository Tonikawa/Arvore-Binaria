//  Created by Gabriel Batista Cristiano
//  TIA: 32090722
//  And Fabio Silveira Tanikawa
//  TIA: 32092563

#ifndef arvore_bin_h
#define arvore_bin_h


#include <string>
#include <iostream>

using namespace std;

class Node
{

    private:
        string nData;

        Node* leftNode;
        Node* rightNode;
        Node* parentNode;

    public:
        Node();
        ~Node();

        string GetData() const;
        void SetData(const string& data);

        Node* GetLeftNode() const;
        void SetLeftNode(Node* left);

        Node* GetRightNode() const;
        void SetRightNode(Node* right);

        Node* GetParentNode() const;
        void SetParentNode(Node* parent);

        bool IsRoot(Node* node) const;
        bool IsLeaf(const Node* node);
        int GetDegree(const Node* node);
        int GetDepth(Node* node) const;
        int GetHeight(const Node* node);
};


class Tree
{
    private:
        Node* root;
        string TraverseInOrderInt(const Node* node) const;
        string TraversePreOrderInt(const Node* node) const;
        string TraversePostOrderInt(const Node* node) const;
        //string TraversePerLevelInt(const Node* node) const;


    public:
        Tree();
        Tree(Node* root);
        ~Tree();

        Node* GetRoot() const;
        void SetRoot(Node* root);

        string TraverseInOrder() const;
        string TraversePreOrder() const;
        string TraversePostOrder() const;
        //string TraversePerLevel() const;
        
};


#endif /* arvore_bin_h */
