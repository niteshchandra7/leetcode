#include<iostream>
using namespace std;

int main(){
    int getMinEfforts(vector<vector<int>> &heights);
    vector<vector<int>>heights = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    // {{1,2,2},{3,8,2},{5,3,5}};
    cout << getMinEfforts(heights)<<endl;
    return 0;
}


int getMinEfforts(vector<vector<int>> &heights){
    bool updateDp(vector<vector<int>>&dp,vector<vector<int>> &heights);
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    dp[0][0]=0;
    for(int i=1;i<m;i++) dp[0][i]=max(dp[0][i-1],abs(heights[0][i]-heights[0][i-1]));
    for(int i=1;i<n;i++) dp[i][0]=max(dp[i-1][0],abs(heights[i][0]-heights[i-1][0]));
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++){
            int top = max(dp[i-1][j],abs(heights[i][j]-heights[i-1][j]));
            int left = max(dp[i][j-1],abs(heights[i][j]-heights[i][j-1]));
            dp[i][j] = min(left,top);
        }
    }
    for(int i=n-2;i>=0;i--) {
        for(int j=m-2;j>=0;j--){
            int bottom = max(dp[i+1][j],abs(heights[i+1][j]-heights[i][j]));
            int right = max(dp[i][j+1],abs(heights[i][j+1]-heights[i][j]));
            dp[i][j] = min(dp[i][j],bottom);
            dp[i][j] = min(dp[i][j],right);
        }
    }
    bool check=true;
    while(check!=false)check=updateDp(dp,heights);
    return dp[n-1][m-1];
}

bool updateDp(vector<vector<int>>&dp,vector<vector<int>> &heights){
    int n = heights.size();
    int m = heights[0].size();
    bool check=false;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            int top = INT_MAX;
            if(i-1>=0) top = max(dp[i-1][j],abs(heights[i][j]-heights[i-1][j]));
            int left = INT_MAX;
            if(j-1>=0)left = max(dp[i][j-1],abs(heights[i][j]-heights[i][j-1]));
            int bottom = INT_MAX;
            if(i+1<n) bottom = max(dp[i+1][j],abs(heights[i+1][j]-heights[i][j]));
            int right = INT_MAX;
            if(j+1<m) right = max(dp[i][j+1],abs(heights[i][j+1]-heights[i][j]));
            int temp = dp[i][j];
            dp[i][j] = min(dp[i][j],top);
            dp[i][j] = min(dp[i][j],left);
            dp[i][j] = min(dp[i][j],bottom);
            dp[i][j] = min(dp[i][j],right);
            if(temp!=dp[i][j])check=true;
        }
    }
    return check;
}