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

Node* mergeKLists(vector<Node*>& lists) {
    priority_queue<int, vector<int>, greater<int>> p;

    for(Node* list : lists){
        Node* temp = list;
        while(temp){
            p.push(temp->data);
            temp = temp->next;
        }
    }

    Node* newnode = new Node(-1);
    Node* dummy = newnode;

    while(!p.empty()){
        dummy->next = new Node(p.top());
        p.pop();
        dummy = dummy->next;
    }
    return newnode->next;
}
