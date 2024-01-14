#include<iostream>
#include<unordered_map>
using namespace std;

bool closeStrings(string word1, string word2) {
    if(word1.size()!=word2.size())return false;
    unordered_map<char,int>mp1,mp2;
    unordered_map<int,int>s1,s2;
    for (auto &elem:word1){
        mp1[elem]+=1;
    }
    for (auto &elem:word2){
        mp2[elem]+=1;
    }
    for (auto &elem:mp1){
        auto key = elem.first;
        auto value = elem.second;
        if(mp2.find(key)==mp2.end())return false;
        s1[value]+=1;
        s2[mp2[key]]+=1;

    }
    return compareMaps(s1,s2);
}

bool compareMaps(unordered_map<int,int>&s1,unordered_map<int,int>&s2){
    for (auto &elem:s1){
        int key = elem.first;
        int value = elem.second;
        if(s2.find(key)==s2.end())return false;
        if(s2[key]!=value)return false;
    }   
    return true;
}


int main(){

}

// TC:O(N), SC:O(N)