#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* curr = list1;
    ListNode* start = nullptr;
    ListNode* end = nullptr;
    int idx=0;
    while(idx<=b){
        if (idx==a-1){
            start = curr;
        }
        curr = curr->next;idx++;
    }
    end = curr;
    start->next = list2;
    curr = list2;
    while(curr && curr->next!=nullptr){
        curr = curr->next;
    }
    curr->next=end;
    return list1;
}

int main() {

}