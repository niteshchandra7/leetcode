#include<iostream>
#include<unordered_map>
using namespace std;

int minSteps(string s, string t) {
    unordered_map<char,int>mpT; int count=0;
    for(const auto &elem:t){
        mpT[elem]+=1;
    }
    for(unsigned int i=0;i<s.size();i++){
        if(mpT.find(s[i])==mpT.end()){
            count++;
        } else {
            mpT[s[i]]-=1;
            if (mpT[s[i]]==0) mpT.erase(s[i]);
        }
    }
    return count;     
}

int main(){
    cout << minSteps("leetcode","practice");
    return 0;
}