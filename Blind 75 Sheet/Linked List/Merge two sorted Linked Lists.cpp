#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
public:
    int data;
    Node* next;

    Node(int n){
        data = n;
        next = nullptr;
    }
};

int main(){
    Node* root1 = new Node(1);
    Node* root2  = new Node(2);

    Node* head = new Node(-1);
    Node* dummy = head;

    while(root1 and root2){
        if(root1->data <= root2->data){
            dummy->next = new Node(root1->data);
            root1 = root1->next;
        }
        else {
            dummy->next = new Node(root2->data);
            root2 = root2->next;
        }
        dummy = dummy->next;
    }

    if(root1) dummy->next = root1;
    if(root2) dummy->next = root2;
}