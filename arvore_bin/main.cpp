// Gabriel Batista Cristiano
// TIA: 32090722
// Fabio Silveira Tanikawa
// TIA: 32092563


#include <iostream>
#include <sstream>
#include "arvore_bin.hpp"

using namespace std; 

void InfoNode(Node* node)
{
    cout << "-------------------------- \n\n";
    cout << "Inserindo no: " << node->GetData() << "\n";
    node->IsRoot(node) ? cout << "E raiz\n" : cout << "Nao e raiz" << "\n";
    node->IsLeaf(node) ? cout << "E folha\n" : cout << "Nao e folha" << "\n";
    cout << "Grau do no: "<<  to_string(node->GetDegree(node)) << "\n";
    cout << "Nivel do no: "<<  to_string(node->GetDepth(node)) << "\n";
    cout << "Altura do no: "<<  to_string(node->GetHeight(node)) << "\n\n";

}



int main() 
{
    Node* A = new Node();
    Node* B = new Node();
    Node* C = new Node();
    Node* D = new Node();
    Node* E = new Node();
    Node* F = new Node();

    A->SetData("A");
    A->SetLeftNode(B);
    A->SetRightNode(C);
    InfoNode(A);   
    
    B->SetData("B");
    B->SetParentNode(A);
    B->SetLeftNode(D);
    InfoNode(B);   

    C->SetData("C");
    C->SetParentNode(A);
    C->SetLeftNode(E);
    C->SetRightNode(F);
    InfoNode(C);

    D->SetData("D");
    D->SetParentNode(B);   
    InfoNode(D);

    E->SetData("E");    
    E->SetParentNode(C);
    InfoNode(E);

    F->SetData("F");
    F->SetParentNode(C);
    InfoNode(F);      

    Tree* tree = new Tree(A); 
//if arvore vazia(false)- continua
//Em ordem: D->B->A->E->C->F
//Pre-ordem: A->B->D->C->E->F  1-visitar nó raiz 2-percorrer a subarvore da esquerda e depois da direita em pre ordem
//Pós ordem: D->B->E->F->C->A  1-percorrer a subarvore da esquerda e depois da direita em pos ordem 2-visitar nó raiz
    cout << "------- Arvore em Ordem -------\n";
    cout << tree->TraverseInOrder() << "\n\n";

    cout << "------- Arvore em Pos-ordem -------\n";
    cout << tree->TraversePostOrder() << "\n\n";

    cout << "------- Arvore em Pre-ordem -------\n";
    cout << tree->TraversePreOrder() << "\n\n";

    delete tree;
    delete F;
    delete E;
    delete D;
    delete C;
    delete B;
    delete A;  
}
