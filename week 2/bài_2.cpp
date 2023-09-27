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
    Node* prev = nullptr;
    Node* newnode = new Node(data_);

    if (head == nullptr){
        newnode = head;
        return head;
    }

    int i = 0;
    while (curr != nullptr){
        if (positon == i){
            break;
        }
        prev = curr;
        curr = curr -> next;
        i++;
    }
    prev -> next = newnode;
    newnode -> next = curr;
    return head;
}

void printNode(Node* head){
    Node* curr = head;
    while (curr != nullptr){
        cout << curr -> data << " ";
        curr = curr -> next;
    }
}

int main()
{
    int n;
    cin >> n;
    Node* head = nullptr;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if (s == "insert"){
            int position, data;
            cin >> position >> data;
            head = Insert(head, position, data);
        }
    }
    printNode(head);
    return 0;
}
