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

Node* nth(Node* head){
    Node* root = new Node(1);
    int n = 2;

    Node* slow = root;
    Node* fast = root;
    while(n--) fast = fast->next;

    if(fast) return slow->next;

    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return slow;
}