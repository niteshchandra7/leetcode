#include<iostream>
#include<vector>
using namespace std;

int minOperations(vector<int>&nums, int k) {
    int value = k;
    for(int i=0;i<nums.size();i++) {
        value ^= nums[i];
    }
    return countSetBits(value);
}

int countSetBits(int num) {
    int count = 0;
    while(num>0) {
        count++;
        num = num & (num-1);
    }
    return count;
}

int main() {

}