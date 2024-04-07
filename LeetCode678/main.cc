#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int check(string s,int idx,stack<char>&st,vector<vector<int>>&dp) {
    if(idx==s.size())return st.empty()==true?1:0;
    if(s[idx]=='('){
        st.push(s[idx]);
        if(dp[idx][st.size()]==-1)dp[idx][st.size()] = check(s,idx+1,st,dp);
        st.pop();
    } else if (s[idx]=='*') {
        if(dp[idx][st.size()]==-1)dp[idx][st.size()] = check(s,idx+1,st,dp);
        st.push('(');
        if(dp[idx][st.size()]==-1)dp[idx][st.size()] = check(s,idx+1,st,dp);
        st.pop();
        if(!st.empty()){
            st.pop();
            if(dp[idx][st.size()]==-1)dp[idx][st.size()] = check(s,idx+1,st,dp);
            st.push('(');
        }
    }else {
        if(!st.empty()){
            st.pop();
            if(dp[idx][st.size()]==-1)dp[idx][st.size()] = check(s,idx+1,st,dp);
            st.push('(');
        }
    }
    if (dp[idx][st.size()+1]==1 || dp[idx][st.size()]==1 || (!st.empty() && dp[idx][st.size()-1]==1))return 1;
    return 0;
}

bool checkValidString(string s) {
    vector<vector<int>>dp(s.size(),vector<int>(s.size()+1,-1));
    stack<char> st;
    return check(s, 0, st, dp);
}
