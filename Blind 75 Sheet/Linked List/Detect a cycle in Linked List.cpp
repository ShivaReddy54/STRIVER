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
    Node* root = new Node(1);

    Node* slow = root;
    Node* fast = root;

    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return 1;
    }
    return 0;
}