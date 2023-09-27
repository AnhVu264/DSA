#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node (int data_)
        {
            data = data_;
            next = nullptr;
        }
        Node* next;
};

Node* Insert(Node* head, int positon, int data_)
{
    Node* curr = head;
    Node* newnode = new Node(data);
    
    if (position == 1)
    {
        newnode -> next = head;
        return newnode;
    }
    
    for (int i = 0; i < position - 1; i++)
    {
        curr = curr -> next;
    }
    
    if (curr == nullptr)
        return head;
    
    newnode -> next = curr -> next;
    curr -> next = newnode;
        
}