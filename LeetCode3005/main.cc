#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    unsigned int count = 0;
    unsigned int countSum = 0;
    unordered_map<int,int>mp;
    for (unsigned int i=0;i<nums.size();i++){
        mp[nums[i]] += 1;
        if (mp[nums[i]]<count) continue;
        else if (mp[nums[i]]>count) {
            count = mp[nums[i]];
            countSum = mp[nums[i]];
        } 
        else countSum += mp[nums[i]];
    }
    return countSum;        
}

int main() {

}