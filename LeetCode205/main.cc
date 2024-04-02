#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.size()!=t.size())return false;
    unordered_map<char,char>mp;
    unordered_set<char>discardedSet;
    for(unsigned int i=0;i<s.size();i++){
        if(mp.find(s[i])==mp.end()){
            if(discardedSet.find(t[i])!=discardedSet.end())return false;
            mp[s[i]] = t[i];
            discardedSet.insert(t[i]);
            continue;
        }
        if (mp[s[i]]!=t[i])return false;
    }
    return true;
}

int main() {

}
