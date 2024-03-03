#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==nullptr) return head;
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = nullptr;
    for (unsigned int i=0;i<n-1;i++) {
        fast=fast->next;
    }
    while(fast && fast->next!=nullptr) {
        fast=fast->next;
        prev=slow;
        slow = slow->next;
    }
    if(prev==nullptr) head = slow->next;
    else prev->next = slow->next;
    delete slow;
    return head;
}


int main() {

}